import math
import random

tests = []
def add_test(file):
	tests.append(file)

def write_tests():
	for i in range(len(tests)):
		with open(str(i+1) + '.in', 'w+') as fd:
			fd.write(tests[i])

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
			X = random.choice(cur_set)
			cur.remove(X)
			file += '- ' + str(X) + '\n'
		else:
			file += '+ ' + str(random.randint(1, 10**9)) + '\n'
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
			file += '+ ' + str(random.randint(1, 10**9)) + '\n'
		else:
			file += '? ' + str(random.randint(1, 10**9)) + '\n'
	file += '? ' + str(random.randint(1, 10**9)) + '\n'
	return file

def random_test(q):
	print('generate...')
	T = random.randint(1, 10)
	if 0 <= T <= 3:
		print('full random')
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
