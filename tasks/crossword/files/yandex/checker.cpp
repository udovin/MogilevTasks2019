#include "testlib.h"
#include <vector>

int n, m;
std::vector<int> a, b;

double readOutput(InStream &out) {
	std::vector<std::string> r;
	for (int i = 0; i < n; i++) {
		r.push_back(out.readLine());
		if (r.back().size() != m) {
			out.quitf(_pe, "Wrong output format");
		}
	}
	double difference = 0;
	for (int i = 0; i < n; i++) {
		int k = 0;
		bool f = false;
		for (int j = 0; j < m; j++) {
			if (r[i][j] == '#') {
				if (!f) {
					k++;
				}
				f = true;
			} else {
				f = false;
			}
		}
		difference += (a[i] - k) * (a[i] - k);
	}
	for (int i = 0; i < m; i++) {
		int k = 0;
		bool f = false;
		for (int j = 0; j < n; j++) {
			if (r[j][i] == '#') {
				if (!f) {
					k++;
				}
				f = true;
			} else {
				f = false;
			}
		}
		difference += (b[i] - k) * (b[i] - k);
	}
	return difference;
}

int main(int argc, char **argv) {
	registerTestlibCmd(argc, argv);
	int test = inf.readInt();
	n = inf.readInt();
	m = inf.readInt();
	a.resize(n), b.resize(m);
	for (int i = 0; i < n; i++) {
		a[i] = inf.readInt();
	}
	for (int i = 0; i < m; i++) {
		b[i] = inf.readInt();
	}
	double ja = readOutput(ans);
	double pa = readOutput(ouf);
	quitp(10 * (1 + ja) / (1 + pa));
}
