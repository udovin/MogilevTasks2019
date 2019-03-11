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
	initGenerator(argc, argv, 1);
	
	DECLARE_GEN(GenRange<int>, n);
	DECLARE(double, undo);
	int uc = undo * n;
	DECLARE_D(int, upolar, 0);
	
	vector<char> undoing(n, false);
	for (int i = 0; i < uc; ++i) {
		int w;
		do {
			w = rnd.wnext(n, upolar);
		} while (undoing[w]);
		undoing[w] = true;
	}
	
	set<int> s;
	vector<int> arr;
	for (int i = 0; i < n; ++i) {
		s.insert(i+1);
	}
	
	cout << n << "\n";
	for (int i = 0; i < n; ++i) {
		int del = -1;
		while (!arr.empty() && del < 0) {
			int idx = rnd.next(int(arr.size()));
			if (s.count(arr[idx])) {
				swap(arr[idx], arr.back());
				arr.pop_back();
			} else {
				del = arr[idx];
			}
		}
		if (del >= 0 && undoing[i]) {
			cout << del << "\n";
			s.insert(del);
		} else {
			cout << 0 << "\n";
			int num = *s.begin();
			s.erase(s.begin());
			arr.push_back(num);
		}
	}
	
	return 0;
}
