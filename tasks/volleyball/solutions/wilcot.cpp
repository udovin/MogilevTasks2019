#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int S = 201, K = 6;

pair<int, int> f[K][K][S][S];

void print(int ka, int kb, int sa, int sb) {
	cout << ka << ':' << kb << endl;
	vector<pair<int, int>> ans;
	while (ka > 0 || kb > 0) {
		ans.push_back(f[ka][kb][sa][sb]);
		if (ans.back().first < ans.back().second)
			kb--;
		else
			ka--;
		sa -= ans.back().first;
		sb -= ans.back().second;
	}
	reverse(ans.begin(), ans.end());
	for (auto p : ans)
		cout << p.first << ':' << p.second << ' ';
	cout << endl;
}

void solve() {
	int a, b;
	cin >> a >> b;
	for (int i = 0; i < 3; i++) {
		if (f[3][i][a][b].first != -1) {
			print(3, i, a, b);
			return;
		}
	}
	for (int i = 2; i >= 0; i--) {
		if (f[i][3][a][b].first != -1) {
			print(i, 3, a, b);
			return;
		}
	}
	cout << "Impossible" << endl;
}

inline int g(int n) {
	return n == 5 ? 15 : 25;
}

int main() {
	for (int ka = 0; ka < K; ka++)
		for (int kb = 0; kb < K; kb++)
			for (int sa = 0; sa < S; sa++)
				for (int sb = 0; sb < S; sb++)
					f[ka][kb][sa][sb] = {-1, -1};
	f[0][0][0][0] = {0, 0};
	for (int ka = 0; ka < K; ka++) {
		for (int kb = 0; kb < K; kb++) {
			for (int sa = 0; sa < S; sa++) {
				for (int sb = 0; sb < S; sb++) {
					if (ka > 0 && kb < 3) {
						for (int i = g(ka + kb) + 1; i <= sa; i++) {
							int j = i - 2;
							if (i <= sa && j <= sb && f[ka - 1][kb][sa - i][sb - j].first != -1)
								f[ka][kb][sa][sb] = {i, j};
						}
						for (int j = 0; j <= g(ka + kb) - 2; j++) {
							int i = g(ka + kb);
							if (i <= sa && j <= sb && f[ka - 1][kb][sa - i][sb - j].first != -1)
								f[ka][kb][sa][sb] = {i, j};
						}
					}
					if (kb > 0 && ka < 3) {
						for (int j = g(ka + kb) + 1; j <= sb; j++) {
							int i = j - 2;
							if (i <= sa && j <= sb && f[ka][kb - 1][sa - i][sb - j].first != -1)
								f[ka][kb][sa][sb] = {i, j};
						}
						for (int i = 0; i <= g(ka + kb) - 2; i++) {
							int j = g(ka + kb);
							if (i <= sa && j <= sb && f[ka][kb - 1][sa - i][sb - j].first != -1)
								f[ka][kb][sa][sb] = {i, j};
						}
					}
				}
			}
		}
	}
	int t;
	cin >> t;
	while (t --> 0)
		solve();
	return 0;
}
