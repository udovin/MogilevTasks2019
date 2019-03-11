#include <algorithm>
#include <bitset>
#include <cassert>
#include <chrono>
#include <climits>
#include <cstdint>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <deque>
#include <fstream>
#include <functional>
#include <iostream>
#include <iomanip>
#include <map>
#include <numeric>
#include <queue>
#include <random>
#include <set>
#include <stack>
#include <sstream>
#include <tuple>
#include <vector>

using namespace std;
using namespace chrono;

#ifdef DEBUG
	#define LOCAL_INPUT_FILE
#else
	//~ #define USE_FILE_IO
#endif

#ifdef USE_FILE_IO
	#define INPUT_FILE "input.txt"
	#define OUTPUT_FILE "output.txt"
	#define cin ____cin
	#define cout ____cout
	ifstream cin(INPUT_FILE);
	ofstream cout(OUTPUT_FILE);
#else
	#ifdef LOCAL_INPUT_FILE
		#define cin ____cin
		ifstream cin("input.txt");
	#endif
#endif

const int infinity = (int)1e9 + 42;
const int64_t llInfinity = (int64_t)1e18 + 256;
const int module = (int)1e9 + 7; 
const long double eps = 1e-8;

mt19937_64 randGen(system_clock().now().time_since_epoch().count());

inline void raiseError(string errorCode) {
	cerr << "Error : " << errorCode << endl;
	exit(42);
}

signed main() {
	#ifndef USE_FILE_IO
		ios_base::sync_with_stdio(false);
	#endif
	int n, m; cin >> n >> m;
	vector< pair<int, int> > clones;
	vector<int> pd, pu, num, who;
	pd.push_back(-1);
	pu.push_back(-1);
	num.push_back(INT_MIN);
	who.push_back(-1);
	clones.emplace_back(0, 0);
	for (int i = 0; i < n; ++i) {
		string query; cin >> query;
		if (query == "check") {
			int c; cin >> c; --c;
			assert(c < int(clones.size()));
			int numbr = num[clones[c].first];
			if (numbr == INT_MIN) {
				cout << "basic\n";
			} else {
				cout << numbr << "\n";
			}
		} else if (query == "learn") {
			int c, p; cin >> c >> p; --c;
			assert(c < int(clones.size()));
			clones[c].second = 0;
			int par = clones[c].first;
			clones[c].first = pd.size();
			num.push_back(p);
			pd.push_back(par);
		} else if (query == "rollback") {
			int c; cin >> c; --c;
			assert(c < int(clones.size()));
			assert(clones[c].first != 0);
			int par = clones[c].second;
			clones[c].second = pu.size();
			pu.push_back(par);
			who.push_back(clones[c].first);
			clones[c].first = pd[clones[c].first];
		} else if (query == "relearn") {
			int c; cin >> c; --c;
			assert(c < int(clones.size()));
			assert(clones[c].second != 0);
			clones[c].first = who[clones[c].second];
			clones[c].second = pu[clones[c].second];
		} else if (query == "clone") {
			int c; cin >> c; --c;
			assert(c < int(clones.size()));
			clones.push_back(clones[c]);
		} else {
			assert(false);
		}
	}
	return 0;
}
