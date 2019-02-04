#include<iostream>
#include<fstream>
#include<cstdio>
#include<cmath>
#include<ctime>
#include<algorithm>
#include<vector> 
#include<cstring>
#include<string>
#include<map>
#define mp make_pair
#define scn second
#define frs first
#define pb push_back

using namespace std;
typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int> pi;

long long dst[500][500];
int x[500], y[500];
int n;

void make_dst() {
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j)
			dst[i][j] = (x[i] - x[j]) * (x[i] - x[j]) + (y[i] - y[j]) * (y[i] - y[j]);	
}
int used[500];



long long dfs(int v) {
	used[v] = 1;
	int to = -1;
	for (int i = 0; i < n; ++i) {
		if (used[i])
			continue;
		if (to == -1 || dst[v][to] > dst[v][i])
			to = i;
	}
	if (to == -1)
		return 0;
	return dfs(to) + dst[v][to];
}

string translate(int i) {
	string ans = "00";
	ans[0] = char('0' + i / 10);
	ans[1] = char('0' + i % 10);
	ans = "../tests/tests/" + ans;
	return ans;
}


int main(){
	for (int t = 1; t <= 50; t++) {
	cout << t << endl;
ifstream in(translate(t));
	
	in >> n;//scanf("%d", &n);
	for (int i = 0; i < n; ++i) 
		in >> x[i] >> y[i];//scanf("%d%d", &x[i], &y[i]);
	in.close();
ofstream out(translate(t) + ".a");
		make_dst();
	ll ans = 1000000000000000000LL;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j)
			used[j] = 0;
		ll tmp = dfs(i);
		ans = min(ans, tmp);		
	}
	out << ans;//printf("%I64d", ans);
out.close();
}
	return 0;
}
/*
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
*/
