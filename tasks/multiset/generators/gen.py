import math
import random
from subprocess import run
from shutil import copyfile, move
from os import remove
from os.path import exists


tests = []
def add_test(file):
	tests.append(file)

def write_tests():
	for i in range(len(tests)):
		input_file = '{:02}'.format(i+1)
		output_file = '{:02}.a'.format(i+1)
		with open(input_file, 'w') as fd:
			fd.write(tests[i])
		copyfile(input_file, 'multiset.in')
		run(['./a.out'])
		remove('multiset.in')
		move('multiset.out', output_file)

######################################################################

def insert_than_query(q, insert_num):
	file = str(q) + '\n'
	for i in range(insert_num):
		file += '+ ' + str(random.randint(1, 10**9)) + '\n'
	for i in range(q - insert_num):
		file += '? ' + str(random.randint(1, 10**9)) + '\n'
	return file

def insert_delete_1query(q):
	file, cur = str(q) + '\n', []
	for i in range(q - 1):
		if len(cur) != 0 and random.random() < 0.4:
			X = random.choice(cur)
			cur.remove(X)
			file += '- ' + str(X) + '\n'
		else:
			X = random.randint(1, 10**9)
			cur += [X]
			file += '+ ' + str(X) + '\n'
	file += '? ' + str(random.randint(1, 10**9)) + '\n'
	return file

def full_random(q):
	file, cur = str(q) + '\n', []
	for i in range(q - 1):
		if len(cur) != 0 and random.random() < 0.2:
			X = random.choice(cur)
			cur.remove(X)
			file += '- ' + str(X) + '\n'
		elif random.random() < 0.8:
			X = random.randint(1, 10**9)
			cur += [X]
			file += '+ ' + str(X) + '\n'
		else:
			file += '? ' + str(random.randint(1, 10**9)) + '\n'
	file += '? ' + str(random.randint(1, 10**9)) + '\n'
	return file

def random_test(q):
	T = random.randint(1, 10)
	if 0 <= T <= 3:
		return full_random(q)
	elif 4 <= T <= 6:
		return insert_than_query(q, random.randint(1, q - 1))
	else:
		return insert_delete_1query(q)

for i in range(20):
	print(random.random())
	add_test(random_test(random.randint(400, 1000)))

for i in range(40):
	add_test(random_test(random.randint(2000, 5000)))

for i in range(40):
	add_test(random_test(random.randint(6*10**4, 10**5)))

write_tests()
