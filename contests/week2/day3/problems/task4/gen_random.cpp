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
	DECLARE_D(int, kmin, 1);
	
	cout << n << endl;
	for (int i = 0; i < n; ++i) {
		if (i) {
			cout << " ";
		}
		cout << rnd.wnext(1, amax, apol);
	}
	cout << endl;
	
	cout << q << endl;
	for (int i = 0; i < q; ++i) {
		int k = rnd.wnext(kmin, kmax, kpol);
		int p = rnd.wnext(1, n, ppol);
		cout << p << " " << k << "\n";
	}
	
	return 0;
}
