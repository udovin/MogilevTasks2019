#include "testlib.h"
#include "parmpars.hpp"
#include <vector>
#include <algorithm>
#include <numeric>
#include <iostream>
#include <functional>
#include <set>
#include <cassert>
#include <map>

using namespace std;

int main(int argc, char **argv) {
	ios_base::sync_with_stdio(false);
	initGenerator(argc, argv, 1);
	
	DECLARE(int, t);
	DECLARE(int, n);
	DECLARE(int, m);
	DECLARE(int, l);
	DECLARE(int, h);
	
	vector<string> a(n, string(m, '?'));
	
	auto square = [&](int x1, int x2, int y1, int y2) -> int {
		return (y2-y1+1) * (x2-x1+1);
	};
	
	function<bool(int, int, int, int)> boxed = [&](int x1, int x2, int y1, int y2) -> bool {
		int sqr = square(x1, x2, y1, y2);
		assert(sqr >= 2*l);
		if (sqr <= h) {
			vector< pair<int, int> > cells;
			for (int i = x1; i <= x2; ++i) {
				for (int j = y1; j <= y2; ++j) {
					cells.emplace_back(i, j);
				}
			}
			shuffle(begin(cells), end(cells));
			for (int i = 0; i < l; ++i) {
				auto head = cells.back(); cells.pop_back();
				a[head.first][head.second] = 'C';
				head = cells.back(); cells.pop_back();
				a[head.first][head.second] = 'F';
			}
			for (auto it : cells) {
				a[it.first][it.second] = "CF"[rnd.next(2)];
			}
			return true;
		}
		for (int i = 0; i < 300; ++i) {
			bool dir = rnd.next(2);
			if (dir) {
				if (x1 == x2) {
					continue;
				}
				int mid = rnd.next(x1, x2-1);
				if (square(x1, mid, y1, y2) < 2*l || square(mid+1, x2, y1, y2) < 2*l) {
					continue;
				}
				boxed(x1, mid, y1, y2);
				boxed(mid+1, x2, y1, y2);
				return true;
			} else {
				if (y1 == y2) {
					continue;
				}
				int mid = rnd.next(y1, y2-1);
				if (square(x1, x2, y1, mid) < 2*l || square(x1, x2, mid+1, y2) < 2*l) {
					continue;
				}
				boxed(x1, x2, y1, mid);
				boxed(x1, x2, mid+1, y2);
				return true;
			}
		}
		cerr << "panic on " << x1 << " " << x2 << " " << y1 << " " << y2 << " :: " << sqr << endl;
		assert(false);
	};
	boxed(0, n-1, 0, m-1);
	
	println(t);
	println(n, m, l, h);
	for (int i = 0; i < n; ++i) {
		println(a[i]);
	}
	
	return 0;
}
