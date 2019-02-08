#include "testlib.h"
#include <vector>

using namespace std;

typedef vector<pair<int, int>> Edges;

int readOutput(InStream& in, int n, const Edges& g) {
	int k = in.readInt(1, n);
	vector<int> a(n);
	for (int i = 0; i < n; i++) {
		a[i] = in.readInt(1, k);
	}
	for (const pair<int, int>& e : g) {
		if (a[e.first - 1] == a[e.second - 1]) {
			quitf(_wa, "Conflict");
		}
	}
	return k;
}

int main(int argc, char* argv[]) {
	registerTestlibCmd(argc, argv);
	int t = inf.readInt();
	int n = inf.readInt();
	int m = inf.readInt();
	vector<pair<int, int>> g;
	for (int i = 0; i < m; i++) {
		g.emplace_back(
			inf.readInt(1, n),
			inf.readInt(1, n)
		);
	}
	int ja = readOutput(ans, n, g);
	int pa = readOutput(ouf, n, g);
	quitp(10 * pow(double(ja) / pa, 3));
	return 0;
}
