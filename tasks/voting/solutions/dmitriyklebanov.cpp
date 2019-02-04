#include <iostream>
#include <vector>

using namespace std;

vector <vector < pair <int, int> > > g;
vector <bool> used;
vector<int> ans;

bool dfs(int v) {
	used[v] = true;
	bool local_ans = 0;
	for (size_t i = 0; i < g[v].size(); i++) {
		int to = g[v][i].first;
		if (!used[to]) {
			int cur_ans = dfs(to);
			if ((!cur_ans) && (g[v][i].second)) {
				ans.push_back(to + 1);
				cur_ans = 1;
			}
			local_ans |= cur_ans;
		}
	}
	return local_ans;
}

int main() {
	int n; cin >> n;
	g.resize(n);
	for (int i = 0; i < n - 1; i++) {
		int x, y, t; cin >> x >> y >> t;
		x--; y--; t--;
		g[x].push_back({y, t});
		g[y].push_back({x, t});
	}
	used.assign(n, false);
	dfs(0);
	cout << ans.size() << endl;

	for (int& v : ans) {
		cout << v << " ";
	}
	cout << endl;
	return 0;
}
