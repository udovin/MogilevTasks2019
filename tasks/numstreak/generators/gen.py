import math
import random

tests = []
def add_test(file):
	tests.append(file)

def write_tests():
	for i in range(len(tests)):
		with open(str(i+1) + '.in', 'w') as fd:
			fd.write(tests[i])

######################################################################

for i in range(1, 25+1):
	add_test(str(random.randint(10**4, 10**7)) + ' ' + str(random.randint(1, 10)) + '\n')

for i in range(1,  5+1):
	add_test(str(random.randint(10**4, 10**7)) + ' ' + str(random.randint(10, 42)) + '\n')

for i in range(1, 15+1):
	add_test(str(random.randint(10**10, 10**18)) + ' ' + str(random.randint(5, 10)) + '\n')

for i in range(1,  5+1):
	add_test(str(random.randint(10**15, 10**18)) + ' ' + str(random.randint(10**10, 10**18)) + '\n')

write_tests()
