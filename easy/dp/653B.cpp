#include <iostream>
#include <string>
using namespace std;

const int N = 5000, L = 26;

int n, m;
int g[L][L];
int f[N][L];

/**
 * Сделаем ограничение n <= 5000, а размер алфавита 26
 * Сложность: O(n * 26^2 + m)
 */
int main() {
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		string a, b;
		cin >> a >> b;
		g[b[0] - 'a'][a[0] - 'a']++;
	}
	for (int i = 0; i < 6; i++)
		f[0][i] = 1;
	for (int i = 1; i < 6; i++)
		for (int j = 0; j < 6; j++)
			for (int k = 0; k < 6; k++)
				f[i][j] += g[j][k] * f[i - 1][k];
	cout << f[n - 1][0] << endl;;
	return 0;
}
