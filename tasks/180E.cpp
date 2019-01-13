#include <iostream>
#include <vector>
using namespace std;

int n, m, k;
vector<vector<int> > a;
int ans;

int main() {
	cin >> n >> m >> k;
	a.resize(m);
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		a[x - 1].push_back(i);
	}
	ans = 0;
	for (int i = 0; i < m; i++) {
		for (int j = 0, it = 0; j < a[i].size(); j++) {
			while (it < j && a[i][j] - a[i][it] + it - j > k)
				it++;
			ans = max(ans, j - it + 1);
		}
	}
	cout << ans << endl;
	return 0;
}
