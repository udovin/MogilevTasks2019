#include <iostream>
#include <vector>
#include <fstream>

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

string translate(int i) {
	string ans = "00";
	ans[0] = char('0' + i / 10);
	ans[1] = char('0' + i % 10);
	ans = "../tests/tests/" + ans;
	return ans;
}

int main() {

for (int t = 1; t <= 50; t++) {
	cout << t << endl;
ifstream in(translate(t));
	ans.clear();
	g.clear();
	int n; in >> n;
	g.resize(n);
	for (int i = 0; i < n - 1; i++) {
		int x, y, t; in >> x >> y >> t;
		x--; y--; t--;
		g[x].push_back({y, t});
		g[y].push_back({x, t});
	}
	used.assign(n, false);
	dfs(0);
in.close();
ofstream out(translate(t) + ".a");
	out << ans.size() << endl;
	for (int& v : ans) {
		out << v << " ";
	}
	out << endl;
out.close();
}
	return 0;
}
