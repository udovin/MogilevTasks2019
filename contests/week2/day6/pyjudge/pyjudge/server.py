# -*- coding: utf-8 -*-

from flask import Flask, request
from json import dumps, loads
from functools import wraps
from traceback import print_exc
from .models import Users


app = Flask(__name__)
users = Users()
tasks = dict()


def api_result(func):
	@wraps(func)
	def wrapper(*args, **kwargs):
		try:
			return dumps(dict(
				good=True,
				data=func(*args, **kwargs),
			))
		except Exception as exc:
			print_exc()
			return dumps(dict(
				good=False,
				error=exc.args[0],
			))
	return wrapper


def auth_required(func):
	@wraps(func)
	def wrapper(*args, **kwargs):
		login = request.cookies.get('login')
		if not login:
			raise RuntimeError("Login is not provided")
		password = request.cookies.get('password')
		if not password:
			raise RuntimeError("Password is not provided")
		if not users.check_auth(login, password):
			raise RuntimeError(
				"User with such login and password does not exists"
			)
		return func(*args, **kwargs)

	return wrapper


@app.route("/tasks")
@api_result
@auth_required
def get_tasks():
	login = request.cookies["login"]
	user = users.get_user(login)
	result = list()
	for task in tasks.keys():
		accepted = False
		submits = users.get_submits(login, task)
		for submit in submits:
			if submit["is_accepted"]:
				accepted = True
				break
		result.append((task, accepted))
	return result


@app.route("/task/<name>")
@api_result
@auth_required
def get_task(name):
	if not name in tasks:
		raise RuntimeError("Task '{}' does not exists".format(name))
	return tasks[name]["legend"]


@app.route("/task/<name>/inputs")
@api_result
@auth_required
def get_task_inputs(name):
	if not name in tasks:
		raise RuntimeError("Task '{}' does not exists".format(name))
	if "inputs" not in tasks[name]:
		raise RuntimeError("Task '{}' does not have inputs".format(name))
	return _get_task_inputs(name)


@app.route("/task/<name>/submit", methods=("POST",))
@api_result
@auth_required
def post_task_answer(name):
	login = request.cookies["login"]
	if not name in tasks:
		raise RuntimeError("Task '{}' does not exists".format(name))
	output = loads(request.data)
	accepted = _check_task_output(name, output)
	users.add_submit(login, name, accepted)
	return accepted, None


def _get_task_inputs(name):
	task = tasks[name]
	inputs = []
	for task_input in task["inputs"]:
		if isinstance(task_input, dict):
			inputs.append((
				task_input["args"],
				task_input["kwargs"],
			))
		else:
			inputs.append((task_input, {}))
	return inputs


def _get_task_answer(name):
	task = tasks[name]
	if "answer" in task:
		return [task["answer"]]
	answer = list()
	solution = task["solution"]
	for args, kwargs in _get_task_inputs(name):
		answer.append(solution(*args, **kwargs))
	return answer


def _check_task_output(name, output):
	task = tasks[name]
	answer = _get_task_answer(name)
	if len(answer) != len(output):
		return False
	checker = task.get("checker")
	for ja, pa in zip(answer, output):
		if checker:
			if not checker(ja, pa):
				return False
		else:
			if ja != pa:
				return False
	return True


@app.route("/standings")
@api_result
@auth_required
def get_standings():
	rows = []


def start():
	app.run(port=4242)
