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
	
	DECLARE(int, t);
	DECLARE(int, n);
	DECLARE(int, m);
	DECLARE(int, h);
	DECLARE(int, l);
	
	println(t);
	println(n, m, l, h);
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			cout << "CF"[(i + j) & 1];
		}
		cout << endl;
	}
	
	return 0;
}
