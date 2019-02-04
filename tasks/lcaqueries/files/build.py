#!/usr/bin/env python3
# -*- coding: utf-8 -*-

from subprocess import run
from shutil import copyfile, move
from os import remove
from os.path import exists


SOURCE = "solutions/wilcot.cpp"
BINARY = "solution"
INPUT_FILE = "lcaqueries.in"
OUTPUT_FILE = "lcaqueries.out"


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
	run(["g++", "-o", BINARY, SOURCE])
	for i in range(25):
		input_file = "tests/tests/{:02}".format(i + 1)
		output_file = "tests/tests/{:02}.a".format(i + 1)
		run_test(input_file, output_file)
	remove(BINARY)


if __name__ == "__main__":
	main()
