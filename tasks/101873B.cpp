#include <iostream>
using namespace std;

const int M = int(1e9) + 7;

int gcd(int a, int b) {
	int c;
	while (b != 0) {
		c = a % b;
		a = b;
		b = c;
	}
	return a;
}

int pow(int a, int b) {
	int c = 1;
	while (b > 0) {
		if (b % 2 == 1)
			c = int64_t(c) * a % M;
		a = int64_t(a) * a % M;
		b /= 2;
	}
	return c;
}

int main() {
	int n, m, c;
	cin >> n >> m >> c;
	int x = pow(c, n * n);
	int ans = 0;
	for (int i = 0; i < m; i++)
		ans = (ans + pow(x, gcd(i, m))) % M;
	ans = int64_t(ans) * pow(m, M - 2) % M;
	cout << ans;
	return 0;
}
