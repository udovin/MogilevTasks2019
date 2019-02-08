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
	with open("{}.a".format(filename), "w") as fd:
		fd.write("{}\n".format(n))
		fd.write("{}\n".format(" ".join(str(i + 1) for i in range(n))))

def main():
	seed("graphcoloring-seed")
	generate("tests/tests/01", 10, 15)
	generate("tests/tests/02", 10, 25)
	generate("tests/tests/03", 100, 500)
	generate("tests/tests/04", 100, 2641)
	generate("tests/tests/05", 250, 5780)
	generate("tests/tests/06", 500, 1000)
	generate("tests/tests/07", 500, 50000)
	generate("tests/tests/08", 500, 112345)
	generate("tests/tests/09", 500, 912)
	generate("tests/tests/10", 500, 124749)


if __name__ == "__main__":
	main()
