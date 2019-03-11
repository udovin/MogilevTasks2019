#include "testlib.h"
#include "parmpars.hpp"
#include <vector>
#include <algorithm>
#include <numeric>
#include <iostream>
#include <set>
#include <map>

using namespace std;

int main(int argc, char **argv) {
	ios_base::sync_with_stdio(false);
	initGenerator(argc, argv, 1);
	
	DECLARE_GEN(GenRange<int>, n);
	DECLARE_GEN(GenRange<int>, q);
	DECLARE_D(int, amax, n);
	DECLARE_D(int, apol, -2);
	DECLARE_D(int, kmax, n);
	DECLARE_D(int, kpol, -2);
	DECLARE_D(int, ppol, -1);
	DECLARE(int, sqrng);
	
	cout << n << endl;
	for (int i = 0; i < n; ++i) {
		if (i) {
			cout << " ";
		}
		cout << rnd.wnext(1, amax, apol);
	}
	cout << endl;
	
	vector< pair<int, int> > queries;
	for (int i = 0; i < sqrng; ++i) {
		for (int j = 0; j < i; ++j) {
			queries.emplace_back(j+1, i+1);
		}
	}
	if (int(queries.size()) > q) {
		cerr << "too many queries (expected " << int(queries.size()) << ", found " << q << ")" << endl;
		queries.resize(q);
	}
	while (int(queries.size()) < q) {
		int k = rnd.wnext(1, kmax, kpol);
		int p = rnd.wnext(1, n, ppol);
		queries.emplace_back(p, k);
	}
	shuffle(begin(queries), end(queries));
	
	cout << q << endl;
	for (int i = 0; i < q; ++i) {
		cout << queries[i].first << " " << queries[i].second << "\n";
	}
	
	return 0;
}
