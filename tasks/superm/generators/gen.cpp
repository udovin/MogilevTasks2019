#include <string>
#include <iostream>
#include <random>
#include <fstream>
#include <map>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

string getTestName(const int& test_number) {
	string ans = "00";
	ans[0] = char('0' + test_number / 10);
	ans[1] = char('0' + test_number % 10);
	ans = "../tests/tests/" + ans;
	return move(ans);
}

mt19937_64 rnd(42);

vector < pair <int, int> > gr;

void generateTree(int n) {
	gr.clear();
	if (n == 1) return;
	vector <int> toadd(n);
	vector <int> added;
	for (int i = 0; i < n; i++) {
		toadd[i] = i;
	}
	//shuffle(toadd.begin(), toadd.end(), rnd);
	int z1 = rnd() % toadd.size();
	swap(toadd[z1], toadd[toadd.size() - 1]);
	added.push_back(toadd.back());
	z1 = toadd.back();
	toadd.pop_back();

	int z2 = rnd() % toadd.size();
	swap(toadd[z2], toadd[toadd.size() - 1]);
	added.push_back(toadd.back());
	z2 = toadd.back();
	toadd.pop_back();
	gr.push_back({z1 + 1, z2 + 1});
	for (int i = 0; i < n - 2; i++) {
		z2 = rnd() % added.size();
		z2 = added[z2];
		z1 = rnd() % toadd.size();
		swap(toadd[z1], toadd[toadd.size() - 1]);
		added.push_back(toadd.back());
		z1 = toadd.back();
		toadd.pop_back();
		gr.push_back({z1 + 1, z2 + 1});		
	}
}


const int N = int(2e5) + 100;
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

vector<int> generateAns(int n, int m, vector<pair<int, int> >& s, vector <int>& q, int& ans) {
	for (int i = 0; i < n; i++) {
		g[i].clear();
	}

	for (int i = 1; i < n; i++) {
		addEdge(s[i - 1].first - 1, s[i - 1].second - 1);
	}
	for (int i = 0; i < n; i++) {
		gank[i] = false;
	}
	for (int i = 0; i < m; i++) {
		gank[q[i] - 1] = true;
	}
	dfs1(0), dfs2(0);
	ansS = 1e9, ansI = -1;
	for (int i = 0; i < n; i++) {
		int ansN = (sup[i] + sdown[i]) * 2 - max(mup[i], mdown[i]);
		if (ansN < ansS)
			ansS = ansN, ansI = i;
	}
	ans = ansI + 1;
	vector <int> z(n);
	for (int i = 0; i < n; i++) {
		int ansN = (sup[i] + sdown[i]) * 2 - max(mup[i], mdown[i]);
		z[i] = ansN;
	}
	return z;
}

void print(const int& test_number, int n, int m, vector < pair <int, int> >& s, vector< int>& q) {
	ofstream test_in(getTestName(test_number));
	//cout << getTestName(test_number) << endl;
	test_in << n << " " << m << "\n";
	for (int i = 0; i < n - 1; i++) {
		test_in << s[i].first << " " << s[i].second << "\n";
	}
	for (int i = 0; i < m; i++) {
		test_in << q[i] << " ";
	}
	test_in.close();
	ofstream test_out(getTestName(test_number) + ".a");
	int ansZ;
	vector<int> ans = generateAns(n, m, s, q, ansZ);
	test_out << ansZ << "\n";
	for (int i = 0; i < n; i++) {
		test_out<<ans[i] << " ";
	}
	//cout << getTestName(test_number) << endl;
	test_out.close();
}

vector <int> generateQ(int m, int n) {
	vector <int> q;
	vector <int> toadd(n);
	for (int i = 0; i < n; i++) {
		toadd[i] = i;
	}
	for (int i = 0; i < m; i++) {
		int z = rnd() % toadd.size();
		
		q.push_back(toadd[z] + 1);
		swap(toadd[z], toadd[toadd.size() - 1]);
		toadd.pop_back();
	}
	return q;
}

int main() {
	for (int i = 1; i <= 10; ++i) {
		int n = rnd() % 7 + 13;
		int m = rnd() % n + 1;
		generateTree(n);
		vector <int> q(generateQ(m, n));
		print(i, n, m, gr, q);
		cout << i << endl;
	}
	for (int i = 11; i <= 30; ++i) {
		int n = rnd() % 700 + 4300;
		int m = rnd() % n + 1;
		generateTree(n);
		vector <int> q(generateQ(m, n));
		print(i, n, m, gr, q);
		cout << i << endl;
	}
	for (int i = 31; i <= 49; ++i) {
		int n = rnd() % 50000 + 150000;
		int m = rnd() % (n - 50000) + 50000;
		generateTree(n);
		vector <int> q(generateQ(m, n));
		print(i, n, m, gr, q);
		cout << i << endl;
	}

	{
		int n = 200000;
		int m = 200000;
		generateTree(n);
		vector <int> q(generateQ(m, n));
		print(50, n, m, gr, q);
		cout << 50 << endl;
	}
	
	return 0;
}
