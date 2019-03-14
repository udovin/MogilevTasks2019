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
	DECLARE_GEN_D(GenRange<int64_t>, k, genRange(int64_t(1), int64_t(n)*(n-1)/2));
	DECLARE_D(GenRange<int>, val, genRange(1, int(1e9)));
	DECLARE_D(int, polar, 0);
	
	vector<int> a(n);
	for (int i = 0; i < n; ++i) {
		a[i] = val.weightedGen(polar);
	}
	
	println(n, k);
	println(a);
	
	return 0;
}
