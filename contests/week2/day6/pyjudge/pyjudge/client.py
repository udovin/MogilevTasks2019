# -*- coding: utf-8 -*-

from requests import get
from json import dumps
from os import environ


CONFIG = dict(
	host_url="http://localhost:4242",
	login=environ.get("USER"),
)


class Contest(object):
	def __init__(self):
		pass

	def get_tasks(self):
		result = get(
			"{}/tasks".format(CONFIG["host_url"]),
		).json()
		if not result["good"]:
			raise RuntimeError(result["error"])
		for task in result["data"]:
			print(task)

	def get_task(self, name):
		result = get(
			"{}/task/{}".format(CONFIG["host_url"], name)
		).json()
		if not result["good"]:
			raise RuntimeError(result["error"])
		return Task(
			name=result["data"]["name"],
			text=result["data"]["text"],
		)


class Task(object):
	def __init__(self, name, statement):
		self.name = name
		self.statement = statement

	def get_statement(self):
		print(self.name)
		print("-" * 10)
		print(self.statement)

	def solve(self, answer):
		if callable(answer):
			answer = self._run_solution(answer)
		accepted, message = self._send_answer(answer)
		print("Accepted" if accepted else "Rejected")
		if message:
			print(message)

	def _run_solution(self, func):
		outputs = []
		for args, kwargs in self._get_inputs():
			output.append(func(*args, **kwargs))
		return outputs

	def _send_answer(self, answer):
		result = post(
			"{}/send/{}".format(CONFIG["host_url"], self.name),
			data=dict(answer=dumps(answer)),
		).json()
		if not result["good"]:
			raise RuntimeError(result["error"])
		return result["data"]["accepted"], result["data"]["message"]

	def _get_inputs(self):
		result = get(
			"{}/inputs/{}".format(CONFIG["host_url"], self.name),
		).json()
		if not result["good"]:
			raise RuntimeError(result["error"])
		for item in result["data"]:
			yield item["args"], item["kwargs"]
