#!/usr/bin/env python2


def main():
	with open("inputX.txt", "r") as fd:
		test_id = int(fd.readline())
	try:
		with open("output{}.txt".format(test_id), "r") as fd:
			output_data = fd.read()
		with open("outputX.txt", "w") as fd:
			fd.write(output_data)
	except IOError as exc:
		print(exc)


if __name__ == "__main__":
	main()
