N = int(input())
L, R, ans, mod = 1, 1, 0, 10**9+7

def sqsum(x):
	return (x*(x+1)*(2*x+1)//6) % mod

while R < N:
	ans = (ans + (sqsum(R) - sqsum(L-1))*(N//L)) % mod
	L, R = R+1, N//(N//(R+1))
ans = (ans + (sqsum(N) - sqsum(L-1))) % mod

print(ans)
