#include <cctype>
#include <string>
#include <vector>
#include <map>
//#include <iostream>
#include "testlib.h"

//#include <fstream>

using namespace std;

using std::vector;
using std::pair;

vector <vector < pair <int, int> > > g;
//ofstream out("lplp");
vector <bool> used;
vector <int> dp;
std::map < pair<int, int>, int> mp;

void dfs(int v) {
	used[v] = true;
	for (size_t i = 0; i < g[v].size(); i++) {
		int to = g[v][i].first;
		if (!used[to]) {
			dfs(to);
			if (dp[to]) {
				//out << v << " " << to << endl;
				mp[{v, to}] = 1;
				mp[{to, v}] = 1;
				dp[v] = 1;
			}
		}
	}
}

int main(int argc, char *argv[]) {
    registerTestlibCmd(argc, argv);
    
    int jury_ans = ans.readInt();
    int part_ans = ouf.readInt();
    if (jury_ans != part_ans) {
		quitf(_wa, "jury_ans = %d != part_ans = %d", jury_ans, part_ans);
	}
    vector<int> val(part_ans);
    for (int i = 0; i < part_ans; i++) {
		val[i] = ouf.readInt(); val[i]--;
	}

	int n = inf.readInt();
	g.resize(n);
	for (int i = 0; i < n - 1; i++) {
		int x = inf.readInt(); x--;
		int y = inf.readInt(); y--;
		int t = inf.readInt(); t--;
		
		g[x].push_back({y, t});
		g[y].push_back({x, t});
		mp[{x, y}] = t ^ 1;
		mp[{y, x}] = t ^ 1;
	}
	used.assign(n, false);
	dp.assign(n, 0);

		for (int i = 0; i < part_ans; i++) {
		if ((val[i] < 0) || (val[i] > n - 1)) {
			quitf(_wa, "wrong value[%d] = %d", i, val[i]);
		} else {
			dp[val[i]] = 1;
		}
	}
	
	dfs(0);
	for(auto x:mp) {
		if (x.second != 1) {
			quitf(_wa, "wrong answer");
		}
	}
	
	
	/*
    if (jury != part) {
        if (jury) {
            quitf(_wa, "Participant can't find partition but jury have found (n = %d)", n);
        } else {
            quitf(_fail, "Jury can't find partition but participant has found (n = %d)", n);
        }
    }
    */
    quitf(_ok, "ans = %d", jury_ans);
}
