#!/usr/bin/env python3
# -*- coding: utf-8 -*-

from random import seed, randint
from subprocess import run
from shutil import copyfile, move
from os import remove
from os.path import exists


SOURCE = "solutions/wilcot.cpp"
BINARY = "solution"
INPUT_FILE = "buildings.in"
OUTPUT_FILE = "buildings.out"


def run_test(input_file, output_file):
	if exists(INPUT_FILE):
		remove(INPUT_FILE)
	if exists(output_file):
		remove(output_file)
	copyfile(input_file, INPUT_FILE)
	run(["./{}".format(BINARY)])
	remove(INPUT_FILE)
	move(OUTPUT_FILE, output_file)


def generate(test_file, n, m, c):
	with open(test_file, "w") as fd:
		fd.write("{} {} {}\n".format(n, m, c))


def main():
	seed("6iNCQpP1ErneCHvI")
	run(["g++", "-o", BINARY, SOURCE])
	for i in range(10):
		input_file = "tests/group1/{}.in".format(i + 1)
		output_file = "tests/group1/{}.out".format(i + 1)
		generate(input_file, 1, randint(3, 4), randint(1, 500))
		run_test(input_file, output_file)
	for i in range(10):
		input_file = "tests/group2/{}.in".format(i + 1)
		output_file = "tests/group2/{}.out".format(i + 1)
		generate(input_file, 1, randint(5, 500), randint(1, 500))
		run_test(input_file, output_file)
	for i in range(10):
		input_file = "tests/group3/{}.in".format(i + 1)
		output_file = "tests/group3/{}.out".format(i + 1)
		generate(input_file, randint(2, 500), randint(3, 4), randint(1, 500))
		run_test(input_file, output_file)
	for i in range(20):
		input_file = "tests/group4/{}.in".format(i + 1)
		output_file = "tests/group4/{}.out".format(i + 1)
		generate(input_file, randint(2, 500), randint(5, 500), randint(1, 500))
		run_test(input_file, output_file)
	remove(BINARY)


if __name__ == "__main__":
	main()
