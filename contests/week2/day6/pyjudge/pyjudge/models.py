# -*- coding: utf-8 -*-

from json import loads, dumps, JSONDecodeError
from time import time
from hashlib import sha256


class Storage(object):
	def __init__(self, file_path):
		self.file_path = file_path

	def insert(self, new_rows):
		def _insert(rows):
			for row in rows:
				yield row
			for row in new_rows:
				yield row

		self.update(_insert)

	def delete(self, func):
		def _delete(rows):
			for row in rows:
				if not func(row):
					yield row

		self.update(_delete)

	def select(self, func):
		try:
			with open(self.file_path, "r") as fd:
				try:
					rows = loads(fd.read())
				except JSONDecodeError:
					rows = []
				return func(rows)
		except FileNotFoundError:
			return func([])

	def update(self, func):
		rows = list(self.select(func))
		with open(self.file_path, "w") as fd:
			fd.write(dumps(rows, indent=2))


class Users(Storage):
	def __init__(self):
		super().__init__("users.json")	

	def check_auth(self, login, password):
		def _select(rows):
			for row in rows:
				if login == row["login"] \
						and password_hash == row["password_hash"]:
					return True
			return False

		password_hash = sha256(password.encode()).hexdigest()
		return self.select(_select)

	def add_user(self, login, password, is_danik=False):
		if self.get_user(login):
			raise RuntimeError("User already exists")
		self.insert([dict(
			login=login,
			password_hash=sha256(password.encode()).hexdigest(),
			is_danik=is_danik,
			submits={},
		)])

	def get_user(self, login):
		def _select(rows):
			for row in rows:
				if login == row["login"]:
					return row
			return None

		return self.select(_select)

	def get_submits(self, login, task):
		def _select(rows):
			for row in rows:
				if login == row["login"]:
					return row["submits"].get(task, [])
			return []

		return self.select(_select)

	def add_submit(self, login, task, is_accepted):
		def _update(rows):
			for row in rows:
				if login == row["login"]:
					if task not in row["submits"]:
						row["submits"][task] = []
					row["submits"][task].append(dict(
						is_accepted=is_accepted,
						time=time(),
					))
				yield row

		if not self.get_user(login):
			raise RuntimeError("User does not exists")
		self.update(_update)
