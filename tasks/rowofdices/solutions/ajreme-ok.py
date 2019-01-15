N, prime = int(input()), [-1]*20000

for i in range(2, 20000):
	if prime[i] == -1:
		prime[i] = i
		for j in range(i*i, 20000, i):
			prime[j] = 0
prime = [*filter(lambda x: prime[x]==x, prime)]

def solve(cur=1, ptr=0, need4=0):
	ret = 1-need4
	for i in range(ptr, len(prime)):
		if cur*prime[i]**(4 if need4 else 6) > N:
			break
		for j in range(6, 60, 6):
			if cur*prime[i]**j > N:
				break
			ret += solve(cur*prime[i]**j, i+1, need4)
		for j in range(4, 60, 6):
			if cur*prime[i]**j > N:
				break
			ret += solve(cur*prime[i]**j, i+1, 1-need4)
	return ret

print(solve())
