#include <iostream>
#include <string>
using namespace std;

const int M = 100;

string s;
int m;
int f[2][M];
int64_t ans;

/**
 * Вместо делимости на 4 сделаем делимость на m
 * Сложность: O(|s| * m)
 */
int main() {
	cin >> s >> m;
	for (int i = 0, j = 0; i < s.size(); i++) {
		f[(i + 1) % 2][j]++;
		for (int j = 0; j < m; j++) {
			f[i % 2][(j * 10) % m] += f[(i + 1) % 2][j];
			f[(i + 1) % 2][j] = 0;
		}
		j = (j * 10 + int(s[i] - '0')) % m;
		ans += f[i % 2][(m - j) % m];
	}
	cout << ans << endl;
	return 0;
}
