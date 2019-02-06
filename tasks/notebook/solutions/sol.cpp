#include <iostream>
#include <string>
#include <fstream>
#include <vector>

using namespace std;

int64_t ans = 0;
vector <int64_t> f[2];

int64_t solve(const string& s, int m) {
	f[0].assign(m, 0);
	f[1].assign(m, 0);
	ans = 0;
	for (size_t i = 0; i < s.size(); i++) {
		for (int j = 0; j < m; j++) {
			f[(i + 1) & 1][j] = 0;
		}
		f[(i + 1) & 1][(s[i] - '0') % m] = 1;
		for (int j = 0; j < m; j++) {
			f[(i + 1) & 1][(j * 10 + s[i] - '0') % m] += f[i & 1][j];
		}
		ans += f[(i + 1) & 1][0];
	}
	return ans;
}

int main() {
	string s; int m;
	//	cin >> s; m = 4; //cf edition
	cin >> s >> m;
	cout << solve(s, m) << endl;
	return 0;
}
