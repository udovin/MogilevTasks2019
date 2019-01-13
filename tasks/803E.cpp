#include <iostream>
using namespace std;

const int N = 1002;

int n, k;
string s;
char f[N][2 * N];

int main() {
	cin >> n >> k >> s;
	f[0][N] = '?';
	for (int i = 1; i <= n; i++) {
		char c = s[i - 1];
		bool b = i < n;
		for (int j = N - k + b; j <= N + k - b; j++) {
			if (f[i - 1][j - 1] && (c == '?' || c == 'W'))
				f[i][j] = 'W';
			if (f[i - 1][j + 1] && (c == '?' || c == 'L'))
				f[i][j] = 'L';
			if (f[i - 1][j] && (c == '?' || c == 'D'))
				f[i][j] = 'D';
		}
	}
	int b = -1;
	if (f[n][N - k])
		b = N - k;
	if (f[n][N + k])
		b = N + k;
	if (b == -1) {
		cout << "NO" << endl;;
		return 0;
	}
	for (int i = n; i > 0; i--) {
		s[i - 1] = f[i][b];
		if (f[i][b] == 'W')
			b--;
		else if (f[i][b] == 'L')
			b++;
	}
	cout << s << endl;
	return 0;
}
