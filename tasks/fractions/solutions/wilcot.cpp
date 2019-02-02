#include <iostream>
#include <cstdio>
using namespace std;

int64_t gcd(int64_t a, int64_t b) {
	int64_t c;
	while (a > 0) {
		c = a;
		a = b % a;
		b = c;
	}
	return b;
}

int main() {
	freopen("fractions.in", "rt", stdin);
	freopen("fractions.out", "wt", stdout);
	int64_t n;
	cin >> n;
	int64_t a = -1, b = -1;
	for (int64_t i = 2; i * i <= n; i++) {
		if (n % i != 0)
			continue;
		int64_t j = n / i;
		if (gcd(i, j) == 1) {
			a = i, b = j;
		}
	}
	if (a == -1 && b == -1) {
		cout << "NO" << endl;
		return 0;
	}
	cout << "YES" << endl << 2 << endl;
	for (int64_t i = 0; i * b < n; i++) {
		if ((n - 1 - i * b) % a != 0)
			continue;
		int64_t j = (n - 1 - i * b) / a;
		if (i >= a || j >= b)
			continue;
		cout << i << ' ' << a << endl;
		cout << j << ' ' << b << endl;
		return 0;
	}
	return 0;
}
