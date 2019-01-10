#include <iostream>
#include <vector>
using namespace std;

const int N = int(2e5);
const int INF = int(1e9);

int n, m, x, y;
vector<int> g[N];
bool gank[N];
int sdown[N], mdown[N], mdown2[N];
int sup[N], mup[N];
int ansI, ansS;

void addEdge(int a, int b) {
	g[a].push_back(b);
	g[b].push_back(a);
}

void dfs1(int a, int p = -1) {
	sdown[a] = 0, mdown[a] = -1, mdown2[a] = -1;
	if (gank[a])
		mdown[a] = 0;
	for (int i = 0; i < g[a].size(); i++) {
		int b = g[a][i];
		if (b != p) {
			dfs1(b, a);
			if (mdown[b] >= 0) {
				if (mdown[b] + 1 > mdown[a])
					mdown2[a] = mdown[a], mdown[a] = mdown[b] + 1;
				else if (mdown[b] + 1 > mdown2[a])
					mdown2[a] = mdown[b] + 1;
				sdown[a] += sdown[b] + 1;
			}
		}
	}
}

void dfs2(int a, int p = -1) {
	sup[a] = 0, mup[a] = -1;
	if (gank[a])
		mup[a] = 0;
	if (p != -1) {
		if (mup[p] >= 0) {
			mup[a] = max(mup[a], mup[p] + 1);
			sup[a] = sup[p] + sdown[p] - sdown[a];
			if (mdown[a] < 0)
				sup[a]++;
		}
		if (mdown[a] < 0 && mdown[p] >= 0) {
			mup[a] = max(mup[a], mdown[p] + 1);
			sup[a] = sup[p] + sdown[p] - sdown[a];
			sup[a]++;
		}
		if (mdown[a] >= 0 && mdown2[p] >= 0) {
			if (mdown[p] != mdown[a] + 1)
				mup[a] = max(mup[a], mdown[p] + 1);
			else
				mup[a] = max(mup[a], mdown2[p] + 1);
			sup[a] = sup[p] + sdown[p] - sdown[a];
		}
	}
	for (int i = 0; i < g[a].size(); i++) {
		int b = g[a][i];
		if (b != p)
			dfs2(b, a);
	}
}

int main() {
	cin >> n >> m;
	for (int i = 1; i < n; i++) {
		cin >> x >> y;
		addEdge(x - 1, y - 1);
	}
	for (int i = 0; i < m; i++) {
		cin >> x;
		x--;
		gank[x] = true;
	}
	dfs1(0), dfs2(0);
	ansS = 1e9, ansI = -1;
	for (int i = 0; i < n; i++) {
		int ansN = (sup[i] + sdown[i]) * 2 - max(mup[i], mdown[i]);
		if (ansN < ansS)
			ansS = ansN, ansI = i;
	}
	cout << ansI + 1 << endl << ansS << endl;
	return 0;
}
