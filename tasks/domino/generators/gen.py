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

def get_next_random_pos(st, )

def full_random(N, len=10**8):
	file = str(N) + '\n'
	st = set()
	for i in range(N):
		X = random.randint(-len, len)
		while X in st:
			X = random.randint(-len, len)
		Y = random.randint(2, len//100)
		file += str(X) + ' ' + str(Y) + '\n'
		st.add(X)
	return file

def step_random(N, len=10**8):
	file = str(N) + '\n'
	max_len, start, height, arr = len//3//N, random.randint(-len, 0), 2, []
	for i in range(N):
		if random.random() < 0.05:
			start += random.randint(max_len, 2*max_len)
			height = random.randint(2, len)
		else:
			plus = random.randint(3, 2*max_len)
			start += plus
			height = random.randint(2, plus-1)
		arr += [[start, height]]
	random.shuffle(arr)
	for i in arr:
		if -10**8 <= i[0] <= 10**8:
			file += str(i[0]) + ' ' + str(i[1]) + '\n'
		else:
			print('logic error!')
	return file

def random_test(N):
	if random.randint(1, 10) < 7:
		return step_random(N)
	else:
		return full_random(N)

for i in range(50):
	add_test(random_test(random.randint(400, 1000)))

for i in range(20):
	add_test(random_test(random.randint(2000, 5000)))

for i in range(30):
	add_test(random_test(random.randint(4*10**4, 10**5)))

write_tests()
