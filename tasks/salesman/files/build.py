#!/usr/bin/env python3
# -*- coding: utf-8 -*-

from random import seed, randint


def generate(filename, n, a, b):
	with open(filename, "w") as fd:
		fd.write("{}\n".format(n))
		fd.write("{}\n".format(" ".join(str(randint(1, a)) for _ in range(n))))
		for i in range(n):
			fd.write("{}\n".format(" ".join(str(randint(1, b)) for _ in range(n))))


def main():
	seed("salesman-seed")
	generate("tests/public/input1.txt", 10, 10, 10)
	generate("tests/public/input2.txt", 20, 1000, 10)
	generate("tests/public/input3.txt", 30, 10, 1000)
	generate("tests/public/input4.txt", 100, 1000, 1000)
	generate("tests/public/input5.txt", 250, 1000, 1000)
	generate("tests/public/input6.txt", 500, 16, 16)
	generate("tests/public/input7.txt", 500, 100000, 10)
	generate("tests/public/input8.txt", 500, 100000, 100000)
	generate("tests/public/input9.txt", 500, 2, 5)
	generate("tests/public/input10.txt", 500, 128, 100000)
	generate("tests/samples/01", 6, 5, 5)


if __name__ == "__main__":
	main()
