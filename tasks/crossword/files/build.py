#!/usr/bin/env python3
# -*- coding: utf-8 -*-

from random import seed, randint, choices
from subprocess import run
from shutil import copyfile, move
from os import remove
from os.path import exists


def run_test(input_file, output_file):
	if exists(INPUT_FILE):
		remove(INPUT_FILE)
	if exists(output_file):
		remove(output_file)
	copyfile(input_file, INPUT_FILE)
	run(["./{}".format(BINARY)])
	remove(INPUT_FILE)
	move(OUTPUT_FILE, output_file)


def generate(n, m):
	a = [choices(('#', '.'), k=m) for i in range(n)]
	return a


def write_test(number, data):
	n = len(data)
	m = len(data[0])
	a = [0 for _ in range(n)]
	b = [0 for _ in range(m)]
	for i in range(n):
		last = False
		for j in range(m):
			if data[i][j] == '#':
				if not last:
					a[i] += 1
					last = True
			else:
				last = False
	for i in range(m):
		last = False
		for j in range(n):
			if data[j][i] == '#':
				if not last:
					b[i] += 1
					last = True
			else:
				last = False
	with open("tests/tests/{:02}".format(number), "w") as fd:
		fd.write("{} {}\n".format(n, m))
		fd.write("{}\n".format(" ".join(map(str, a))))
		fd.write("{}\n".format(" ".join(map(str, b))))
	with open("tests/tests/{:02}.a".format(number), "w") as fd:
		for i in range(n):
			for j in range(m):
				fd.write(data[i][j])
			fd.write('\n')


def main():
	seed("hYefn64DalPvgtuh")
	write_test(3, generate(10, 10))
	write_test(4, generate(17, 15))
	write_test(5, generate(11, 40))
	write_test(6, generate(60, 17))
	write_test(7, generate(79, 81))
	write_test(8, generate(4, 91))
	write_test(9, generate(100, 5))
	write_test(10, generate(100, 100))


if __name__ == "__main__":
	main()
