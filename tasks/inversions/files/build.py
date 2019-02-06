#!/usr/bin/env python3
# -*- coding: utf-8 -*-

from random import seed, randint
from subprocess import run
from shutil import copyfile, move
from os import remove
from os.path import exists


SOURCE = "solutions/wilcot.cpp"
BINARY = "solution"
INPUT_FILE = "inversions.in"
OUTPUT_FILE = "inversions.out"


def run_test(input_file, output_file):
	if exists(INPUT_FILE):
		remove(INPUT_FILE)
	if exists(output_file):
		remove(output_file)
	copyfile(input_file, INPUT_FILE)
	run(["./{}".format(BINARY)])
	remove(INPUT_FILE)
	move(OUTPUT_FILE, output_file)


def generate_zeroes(test_file, n, k):
	with open(test_file, "w") as fd:
		fd.write("{} {}\n".format(n, k))
		fd.write("{}\n".format("\n".join("0" for _ in range(n))))


def generate(test_file, n, k, p):
	def maybe_zero():
		if randint(1, 100) <= p:
			return "0"
		return str(randint(1, k))
	with open(test_file, "w") as fd:
		fd.write("{} {}\n".format(n, k))
		fd.write("{}\n".format("\n".join(maybe_zero() for _ in range(n))))


def main():
	seed("nrtjR6H2gjLLyft0")
	run(["g++", "-o", BINARY, SOURCE])
	for i in range(10):
		input_file = "tests/tests/{:02}".format(i + 1)
		output_file = "tests/tests/{:02}.a".format(i + 1)
		generate_zeroes(input_file, i + 1, randint(1, 10))
		run_test(input_file, output_file)
	for i in range(10, 20):
		input_file = "tests/tests/{:02}".format(i + 1)
		output_file = "tests/tests/{:02}.a".format(i + 1)
		generate(input_file, randint(8, 10), randint(1, 10), 50)
		run_test(input_file, output_file)
	for i in range(20, 40):
		input_file = "tests/tests/{:02}".format(i + 1)
		output_file = "tests/tests/{:02}.a".format(i + 1)
		generate(input_file, randint(70, 100), randint(1, 100), 70)
		run_test(input_file, output_file)
	for i in range(40, 60):
		input_file = "tests/tests/{:02}".format(i + 1)
		output_file = "tests/tests/{:02}.a".format(i + 1)
		generate(input_file, randint(70, 100), randint(1, 100), 30)
		run_test(input_file, output_file)
	for i in range(60, 80):
		input_file = "tests/tests/{:02}".format(i + 1)
		output_file = "tests/tests/{:02}.a".format(i + 1)
		generate(input_file, randint(70000, 100000), randint(1, 100), 30)
		run_test(input_file, output_file)
	for i in range(80, 100):
		input_file = "tests/tests/{:02}".format(i + 1)
		output_file = "tests/tests/{:02}.a".format(i + 1)
		generate(input_file, randint(70000, 100000), randint(1, 100), 70)
		run_test(input_file, output_file)
	remove(BINARY)


if __name__ == "__main__":
	main()
