#include <iostream>
using namespace std;

const int X = 100, M = int(1e9) + 7;

int n, m, k, x, l;
int f[X], g[X], c[X], ai;

int binPow(int a, int n) {
	int b = 1, c = a;
	while (n > 0) {
		if (n % 2 == 1)
			b = int64_t(b) * c % x;
		c = int64_t(c) * c % x;
		n /= 2;
	}
	return b;
}

void merge(int* a, int* b, int l) {
	int p = binPow(10, l);
	for (int i = 0; i < x; i++)
		c[i] = 0;
	for (int i = 0; i < x; i++) {
		for (int j = 0; j < x; j++) {
			int k = (int64_t(p) * i + j) % x;
			c[k] = (c[k] + int64_t(a[i]) * b[j]) % M;
		}
	}
	for (int i = 0; i < x; i++)
		a[i] = c[i];
}

int main() {
	cin >> n >> m >> k >> x;
	for (int i = 0; i < n; i++) {
		cin >> ai;
		f[ai % x]++;
	}
	g[0] = 1, l = 1;
	while (m > 0) {
		if (m % 2 == 1)
			merge(g, f, l);
		merge(f, f, l);
		l *= 2, m /= 2;
	}
	cout << g[k] << endl;
	return 0;
}
