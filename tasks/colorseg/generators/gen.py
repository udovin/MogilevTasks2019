import math
import random

tests = []
def add_test(file):
	tests.append(file)

def write_tests():
	for i in range(len(tests)):
		open(str(i+1) + '.in', 'w+').write(tests[i])

######################################################################

def all_different(N):
	ret_file = str(N) + '\n'
	array = [i for i in range(1, N+1)]
	random.shuffle(array)
	for i in array:
		ret_file += str(i) + ' '
	return ret_file[:-1] + '\n'

def k_different(N, K):
	ret_file = str(N) + '\n'
	array = ([i for i in range(1, N+1)]*(N//K+1	))[:N]
	random.shuffle(array)
	for i in array:
		ret_file += str(i) + ' '
	return ret_file[:-1] + '\n'

def full_random(N):
	ret_file = str(N) + '\n'
	for i in [random.randint(1, N) for i in range(N)]:
		ret_file += str(i) + ' '
	return ret_file[:-1] + '\n'

def all_equal(N):
	ret_file = str(N) + '\n'
	eq = random.randint(1, N)
	for i in [eq for i in range(1, N+1)]:
		ret_file += str(i) + ' '
	return ret_file[:-1] + '\n'

def sorted(N):
	ret_file = str(N) + '\n'
	for i in [i for i in range(1, N+1)]:
		ret_file += str(i) + ' '
	return ret_file[:-1] + '\n'

def sorted_inv(N):
	ret_file = str(N) + '\n'
	for i in [N-i for i in range(N)]:
		ret_file += str(i) + ' '
	return ret_file[:-1] + '\n'

def random_test(N):
	T = random.randint(1, 10)
	if T == 1:
		return all_different(N)
	elif 2 <= T <= 4:
		return k_different(N, random.randint(1, N))
	elif 5 <= T <= 7:
		return full_random(N)
	elif T == 8:
		return all_equal(N)
	elif T == 9:
		return sorted(N)
	elif T == 10:
		return sorted_inv(N)

add_test(all_different(1))
for i in range(9):
	add_test(random_test(random.randint(40, 100)))

for i in range(10):
	add_test(random_test(random.randint(600, 1000)))

for i in range(10):
	add_test(random_test(random.randint(6000, 10000)))

for i in range(20):
	add_test(random_test(random.randint(600000, 1000000)))

write_tests()
