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
	#define USE_FILE_IO
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
	int n; cin >> n;
	vector<int> a(n+2);
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
	}
	a[0] = -43;
	a[n+1] = -42;
	const int mod = 998244353;
	static int64_t dp[505][505] = {};
	for (int i = 1; i <= n; ++i) {
		dp[i][i] = 1;
		dp[i][i-1] = dp[i+1][i] = 1;
	}
	static int64_t cnt[505][505] = {};
	for (int i = 0; i <= n; ++i) {
		for (int j = 0; j <= n; ++j) {
			if (!i || !j) {
				cnt[i][j] = 1;
				continue;
			}
			cnt[i][j] = (cnt[i-1][j] + cnt[i][j-1]) % mod;
		}
	}
	for (int i = n; i > 0; --i) {
		for (int j = i+1; j <= n; ++j) {
			if (a[i-1] == a[j+1]) {
				continue;
			}
			for (int k = i; k <= j; ++k) {
				if (a[i-1] == a[k] || a[k] == a[j+1]) {
					continue;
				}
				dp[i][j] += dp[i][k-1] * dp[k+1][j] % mod * cnt[k-i][j-k];
				dp[i][j] %= mod;
			}
		}
	}
	cout << dp[1][n] % mod << endl;
	return 0;
}
