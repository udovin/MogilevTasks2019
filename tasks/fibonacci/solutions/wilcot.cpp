#include <iostream>
using namespace std;

const int K = 101;
const int64_t ANS = int64_t(1e18);

int k;
int64_t n;
int64_t f[K][K];
int64_t fib[K];

int main() {
	for (int i = 0; i < K; i++)
		f[0][i] = 1;
	for (int i = 1; i < K; i++) {
		f[i][0] = f[i - 1][0];
		for (int j = 1; j < K; j++) {
			f[i][j] = f[i][j - 1] + f[i - 1][j] - f[i - 1][j - 1];
			if (i > 1) {
				f[i][j] += f[i - 2][j - 1];
				if (j > 1)
					f[i][j] -= f[i - 2][j - 2];
			}
		}
	}
	fib[0] = fib[1] = 1;
	for (int i = 2; i < K; i++)
		fib[i] = fib[i - 1] + fib[i - 2];
	cin >> k >> n;
	n += k;
	int64_t ans = 0;
	bool b = false;
	for (int i = 87; i >= 0; i--) {
		if (f[i][k] < n && !b) {
			ans += fib[i];
			if (ans > ANS) {
				cout << "No" << endl;
				return 0;
			}
			n -= f[i][k];
			k--;
			b = true;
		} else {
			b = false;
		}
	}
	if (ans > ANS) {
		cout << "No" << endl;
		return 0;
	}
	cout << ans << endl;
	return 0;
}
