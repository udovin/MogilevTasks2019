#!/usr/bin/env python3
# -*- coding: utf-8 -*-

from random import seed, randint


def generate(filename, n, m):
	with open(filename, "w") as fd:
		fd.write("{} {}\n".format(n, m))
		edges = set()
		while len(edges) < m * 2:
			x, y = randint(1, n), randint(1, n)
			if x == y:
				continue
			if (x, y) not in edges:
				edges.add((x, y))
				edges.add((y, x))
				fd.write("{} {}\n".format(x, y))

def main():
	seed("graphcoloring-seed")
	generate("tests/public/input1.txt", 10, 15)
	generate("tests/public/input2.txt", 10, 25)
	generate("tests/public/input3.txt", 100, 500)
	generate("tests/public/input4.txt", 100, 2641)
	generate("tests/public/input5.txt", 250, 5780)
	generate("tests/public/input6.txt", 500, 1000)
	generate("tests/public/input7.txt", 500, 50000)
	generate("tests/public/input8.txt", 500, 112345)
	generate("tests/public/input9.txt", 500, 912)
	generate("tests/public/input10.txt", 500, 124749)
	generate("tests/samples/01", 6, 5)


if __name__ == "__main__":
	main()
