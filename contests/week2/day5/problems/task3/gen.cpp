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
	DECLARE_D(int, psz, n);
	DECLARE(int, cnt);
	DECLARE_D(int, polar, 0);
	
	auto p = rnd.perm(psz, 1);
	vector<int> v(n);
	for (int i = 0; i < n; ++i) {
		do {
			v[i] = rnd.wnext(cnt, polar);
		} while (i != 0 && v[i-1] == v[i]);
	}
	
	set<int> s(begin(v), end(v));
	cerr << "n = " << n << " unique = " << s.size() << endl;
	
	for (int i = 0; i < n; ++i) {
		v[i] = p[v[i]];
	}
	
	println(n);
	println(v);
	
	return 0;
}
