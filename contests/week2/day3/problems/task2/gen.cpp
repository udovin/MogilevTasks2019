#include "testlib.h"
#include "parmpars.hpp"
#include <vector>
#include <algorithm>
#include <numeric>
#include <iostream>
#include <cassert>
#include <set>
#include <map>

using namespace std;

int main(int argc, char **argv) {
	ios_base::sync_with_stdio(false);
	initGenerator(argc, argv, 1);
	
	DECLARE_GEN(GenRange<int>, n);
	DECLARE_GEN_D(GenRange<int>, ruZones, genRange(0));
	DECLARE_D(GenRange<int>, ruLens, genRange(n/5 / max(1, ruZones), n/3 / max(1, ruZones)));
	DECLARE_D(double, rollback_c, 1);
	DECLARE_D(double, undo_c, 1);
	DECLARE_D(double, info_c, 1);
	DECLARE_D(double, rollback_z, rollback_c);
	DECLARE_D(double, undo_z, undo_c);
	DECLARE_D(double, clone_gc, 0.2);
	DECLARE_D(double, check_gc, 0.25);
	
	cout << n << "\n";
	
	vector< pair<int, int> > clones;
	vector<int> pd, pu, num, who;
	pd.push_back(-1);
	pu.push_back(-1);
	num.push_back(INT_MIN);
	who.push_back(-1);
	clones.emplace_back(0, 0);
	int csz = 1;
	
	auto canUndo = [&](int c) {
		return clones[c].second != 0;
	};
	
	auto canRollback = [&](int c) {
		return clones[c].first != 0;
	};
	
	auto info = [&](int c, int p) {
		cout << "info " << c+1 << " " << p << "\n";
		assert(c < int(clones.size()));
		clones[c].second = 0;
		int par = clones[c].first;
		clones[c].first = pd.size();
		num.push_back(p);
		pd.push_back(par);
	};
	
	auto rollback = [&](int c) {
		cout << "rollback " << c+1 << "\n";
		assert(c < int(clones.size()));
		assert(clones[c].first != 0);
		int par = clones[c].second;
		clones[c].second = pu.size();
		pu.push_back(par);
		who.push_back(clones[c].first);
		clones[c].first = pd[clones[c].first];
	};
	
	auto undo = [&](int c) {
		cout << "undo " << c+1 << "\n";
		assert(c < int(clones.size()));
		assert(clones[c].second != 0);
		clones[c].first = who[clones[c].second];
		clones[c].second = pu[clones[c].second];
	};
	
	auto clone = [&](int c) {
		cout << "clone " << c+1 << "\n";
		assert(c < int(clones.size()));
		clones.push_back(clones[c]);
		++csz;
	};
	
	auto takeEvent = [&](vector<double> v) {
		double sum = 0;
		for (double d : v) {
			sum += d;
		}
		assert(sum > 1e-9);
		double val = rnd.next(sum);
		for (int i = 0; i < int(v.size()); ++i) {
			if (val < v[i]) {
				return i;
			}
			val -= v[i];
		}
		assert(val < 1e-9);
		return int(v.size()) - 1;
	};
	
	vector<char> ruzone(n, false);
	for (int i = 0; i < ruZones; ++i) {
		int len = ruLens.generate();
		int l = rnd.next(n - len + 1);
		for (int i = 0; i < len; ++i) {
			ruzone[l+i] = true;
		}
	}
	for (int i = 0; i < n; ++i) {
		double grand = rnd.next(1.0);
		if (grand < clone_gc) {
			clone(rnd.next(csz));
			continue;
		}
		grand -= clone_gc;
		if (grand < check_gc) {
			cout << "check " << rnd.next(1, csz) << "\n";
			continue;
		}
		
		auto attempt = [&]() {
			int c = rnd.next(csz);
			vector<double> chances {info_c, canUndo(c) ? undo_c : 0.0, canRollback(c) ? rollback_c : 0.0};
			if (ruzone[i]) {
				chances[0] = 0;
				chances[1] = canUndo(c) ? undo_z : 0.0;
				chances[2] = canRollback(c) ? rollback_z : 0.0;
			}
			if (!chances[0] && !chances[1] && !chances[2]) {
				return false;
			}
			int evt = takeEvent(chances);
			if (evt == 0) {
				info(c, rnd.next(1, 1'000'000'000));
			} else if (evt == 1) {
				undo(c);
			} else if (evt == 2) {
				rollback(c);
			} else {
				assert(false);
			}
			return true;
		};
		
		bool ok = false;
		for (int i = 0; i < 100; ++i) {
			if (attempt()) {
				ok = true;
				break;
			}
		}
		if (ok) {
			continue;
		}
		ruzone[i] = false;
		for (int i = 0; i < 100; ++i) {
			if (attempt()) {
				ok = true;
				break;
			}
		}
		if (ok) {
			continue;
		}
		assert(false);
	}
	
	return 0;
}
