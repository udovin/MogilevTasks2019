#include "testlib.h"
#include <vector>

using namespace std;

int64_t readOutput(
	InStream& in,
	int n,
	const vector<int>& a,
	const vector<vector<int>>& w
) {
	vector<int> p(n);
	for (int i = 0; i < n; i++) {
		p[i] = in.readInt(1, n) - 1;
		for (int j = 0; j < i; j++) {
			if (p[j] == p[i]) {
				quitf(_wa, "Wrong permutation");
			}
		}
	}
	int64_t ans(0);
	for (int i = 1; i < n; i++) {
		ans += (w[p[i - 1]][p[i]] + (i & a[p[i - 1]])) ^ a[p[i]];
	}
	return ans;
}

int main(int argc, char* argv[]) {
	registerTestlibCmd(argc, argv);
	int t = inf.readInt();
	int n = inf.readInt();
	vector<int> a(n);
	vector<vector<int>> w(n, vector<int>(n));
	for (int i = 0; i < n; i++) {
		a[i] = inf.readInt();
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			w[i][j] = inf.readInt();
		}
	}
	int ja = readOutput(ans, n, a, w);
	int pa = readOutput(ouf, n, a, w);
	quitp(10 * pow(double(ja) / pa, 3));
	return 0;
}
