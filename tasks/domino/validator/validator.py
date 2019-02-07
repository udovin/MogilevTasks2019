def check(test_num):
	file = open(str(test_num) + '.in').read().split()
	st = set()
	N = int(file[0])
	if not (1 <= N <= 10**5):
		print('invalid N:', N, ', test_num:', test_num)
	for i in range(N):
		X = int(file[2*i+1])
		Y = int(file[2*i+2])
		if not (-10**8 <= X <= 10**8 and 2 <= Y <= 10**8 and not (X in st)):
			print('invalid X or Y or Was:', X, Y, ', test_num:', test_num)
		st.add(X)

for i in range(1, 101):
	print('validation of', i)
	check(i)

while True:
	pass
