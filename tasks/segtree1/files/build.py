#!/usr/bin/env python3
# -*- coding: utf-8 -*-

from subprocess import run
from shutil import copyfile, move
from os import remove
from os.path import exists
from random import randint, seed


SOURCE = "solutions/wilcot.cpp"
BINARY = "solution"
INPUT_FILE = "segtree1.in"
OUTPUT_FILE = "segtree1.out"


def run_test(input_file, output_file):
	if exists(INPUT_FILE):
		remove(INPUT_FILE)
	if exists(output_file):
		remove(output_file)
	copyfile(input_file, INPUT_FILE)
	run(["./{}".format(BINARY)])
	remove(INPUT_FILE)
	move(OUTPUT_FILE, output_file)


def gen_test(input_file, n, q, mx):
	with open(input_file, "w") as fd:
		fd.write("{} {}\n".format(n, q))
		for i in range(q):
			if randint(1, 2) == 1:
				fd.write("+ {} {}\n".format(randint(1, n), randint(1, mx)))
			else:
				l = randint(1, n)
				r = randint(l, n)
				fd.write("? {} {}\n".format(l, r))


def main():
	seed("hello, world!")
	run(["g++", "-o", BINARY, SOURCE])
	gen_test("tests/samples/01", 6, 15, 10)
	run_test("tests/samples/01", "tests/samples/01.a")
	for i in range(25):
		input_file = "tests/tests/{:02}".format(i + 1)
		output_file = "tests/tests/{:02}.a".format(i + 1)
		gen_test(input_file, randint(100000, 200000), randint(100000, 200000), 1000000000)
		run_test(input_file, output_file)
	remove(BINARY)


if __name__ == "__main__":
	main()
