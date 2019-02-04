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

def permutation(N, K):
	arr, file = [*range(1, N+1)], str(N)+' '+str(N)+'\n'
	random.shuffle(arr)
	for i in arr:
		file += str(i) + ' '
	return file[:-1] + '\n'

def full_random(N, K):
	arr, file = [random.randint(1, N) for i in range(K)], str(N)+' '+str(K)+'\n'
	random.shuffle(arr)
	for i in arr:
		file += str(i) + ' '
	return file[:-1] + '\n'

def sqrt_dist(N, K):
	dist = int(math.sqrt(N))
	choose = random.sample([*range(1, N)], dist)
	random.shuffle(choose)
	arr, file = [choose[i%dist] for i in range(K)], str(N)+' '+str(K)+'\n'
	for i in arr:
		file += str(i) + ' '
	return file[:-1] + '\n'

def shuffle_sqrt_dist(N, K):
	dist = int(math.sqrt(N))
	choose = random.sample([*range(1, N)], dist)
	random.shuffle(choose)
	arr, file = [choose[i%dist] for i in range(K)], str(N)+' '+str(K)+'\n'
	random.shuffle(arr)
	for i in arr:
		file += str(i) + ' '
	return file[:-1] + '\n'

def equal(N, K):
	arr, file = [random.randint(1, N)]*K, str(N)+' '+str(K)+'\n'
	for i in arr:
		file += str(i) + ' '
	return file[:-1] + '\n'

def random_test(limitLN, limitRN, limitLK, limitRK):
	N, K = random.randint(limitLN, limitRN), random.randint(limitLK, limitRK)
	if limitRN == limitRK and random.randint(1, 10) < 5:
		N, K = max(limitRN, limitRK), max(limitRN, limitRK)
	T = random.randint(1, 100)
	if 0 <= T <= 49:
		add_test(shuffle_sqrt_dist(N, K))
	elif 50 <= T <= 79:
		add_test(sqrt_dist(N, K))
	else:
		add_test(full_random(N, K))

for i in range(4):
	N = random.randint(4, 10)
	add_test(permutation(N, N))
for i in range(4):
	N = random.randint(4, 10)
	add_test(sqrt_dist(N, N))
for i in range(4):
	N = random.randint(4, 10)
	add_test(shuffle_sqrt_dist(N, N))
for i in range(4):
	N = random.randint(4, 10)
	add_test(equal(N, N))
for i in range(4):
	N = random.randint(4, 10)
	add_test(full_random(N, N))

for i in range(20):
	random_test(5*10**4, 10**5, 10**2, 10**3)

for i in range(20):
	random_test(6*10**4, 10**5, 3*10**3, 5*10**3)

for i in range(40):
	random_test(7*10**4, 10**5, 6*10**4, 10**5)

write_tests()
