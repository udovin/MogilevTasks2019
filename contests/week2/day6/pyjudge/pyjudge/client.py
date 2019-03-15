# -*- coding: utf-8 -*-

from requests import get, post
from json import dumps
from tabulate import tabulate


class Client(object):
	HOST_URL = "http://localhost:4242"

	def __init__(self, login, password):
		self.login = login
		self.password = password

	def get_contest(self):
		return Contest(self)

	def get_cookies(self):
		return dict(
			login=self.login,
			password=self.password,
		)


class Contest(object):
	def __init__(self, client):
		self.client = client

	def show_standings(self):
		result = get(
			"{}/standings".format(self.client.HOST_URL),
			cookies=self.client.get_cookies(),
		).json()
		if not result["good"]:
			raise RuntimeError(result["error"])
		tasks, users = result["data"]
		cols = [
			"rank",
			"user",
			"score",
			"penalty",
		]
		for name in tasks:
			cols.append(name)
		rows = []
		for user in users:
			row = [
				user["rank"],
				user["user"],
				user["score"],
				user["penalty"],
			]
			for task in user["tasks"]:
				if task[0] == True:
					if task[1]:
						row.append("+{}".format(task[1]))
					else:
						row.append("+")
				elif task[0] == False:
					row.append("-{}".format(task[1]))
				else:
					row.append("")
			rows.append(row)
		print(tabulate(rows, cols, tablefmt="grid"))

	def show_tasks(self):
		result = get(
			"{}/tasks".format(self.client.HOST_URL),
			cookies=self.client.get_cookies(),
		).json()
		if not result["good"]:
			raise RuntimeError(result["error"])
		for task, accepted in result["data"]:
			print(task, end='')
			print(" \U0001F389" if accepted else "")

	def get_task(self, name):
		result = get(
			"{}/task/{}".format(self.client.HOST_URL, name),
			cookies=self.client.get_cookies(),
		).json()
		if not result["good"]:
			raise RuntimeError(result["error"])
		return Task(self.client, name, result["data"])


class Task(object):
	def __init__(self, client, name, legend):
		self.client = client
		self.name = name
		self.legend = legend

	def show_legend(self):
		print(self.name)
		print("-" * 10)
		print(self.legend)
		print("-" * 10)

	def solve(self, answer):
		if callable(answer):
			answer = self._run_solution(answer)
		else:
			answer = [answer]
		accepted, message = self._send_answer(answer)
		print("\U0001F389 Accepted" if accepted else "\u274C Rejected")
		if message:
			print("-" * 10)
			print(message)
			print("-" * 10)

	def _run_solution(self, func):
		answer = []
		for args, kwargs in self._get_inputs():
			answer.append(func(*args, **kwargs))
		return answer

	def _get_inputs(self):
		result = get(
			"{}/task/{}/inputs".format(self.client.HOST_URL, self.name),
			cookies=self.client.get_cookies(),
		).json()
		if not result["good"]:
			raise RuntimeError(result["error"])
		return result["data"]

	def _send_answer(self, answer):
		result = post(
			"{}/task/{}/submit".format(self.client.HOST_URL, self.name),
			data=dumps(answer),
			cookies=self.client.get_cookies(),
		).json()
		if not result["good"]:
			raise RuntimeError(result["error"])
		return result["data"]
