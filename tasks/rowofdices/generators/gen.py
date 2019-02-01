import math
import random

tests = []
def add_test(file):
	tests.append(file)

def write_tests():
	for i in range(len(tests)):
		open(str(i+1) + '.in', 'w+').write(tests[i])

######################################################################

for i in range(10):
	add_test(str(random.randint(10**4, 10**7)) + '\n')

for i in range(15):
	add_test(str(random.randint(10**8, 10**10)) + '\n')

for i in range(15):
	add_test(str(random.randint(10**12, 10**14)) + '\n')

for i in range(10):
	add_test(str(random.randint(10**16, 10**18)) + '\n')

write_tests()
