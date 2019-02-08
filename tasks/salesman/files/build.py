#!/usr/bin/env python3
# -*- coding: utf-8 -*-

from random import seed, randint


def generate(filename, n, a, b):
	with open(filename, "w") as fd:
		fd.write("{}\n".format(n))
		fd.write("{}\n".format(" ".join(str(randint(1, a)) for _ in range(n))))
		for i in range(n):
			fd.write("{}\n".format(" ".join(str(randint(1, b)) for _ in range(n))))
	with open("{}.a".format(filename), "w") as fd:
		fd.write("{}\n".format(" ".join(str(i + 1) for i in range(n))))


def main():
	seed("salesman-seed")
	generate("tests/tests/01", 10, 10, 10)
	generate("tests/tests/02", 20, 1000, 10)
	generate("tests/tests/03", 30, 10, 1000)
	generate("tests/tests/04", 100, 1000, 1000)
	generate("tests/tests/05", 250, 1000, 1000)
	generate("tests/tests/06", 500, 16, 16)
	generate("tests/tests/07", 500, 100000, 10)
	generate("tests/tests/08", 500, 100000, 100000)
	generate("tests/tests/09", 500, 2, 5)
	generate("tests/tests/10", 500, 128, 100000)


if __name__ == "__main__":
	main()
