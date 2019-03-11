#include "testlib.h"
#include <set>

using namespace std;

int main(int argc, char *argv[]) {
	registerValidation(argc, argv);
	
	int n = inf.readInt(1, 300'000);
	inf.readEoln();
	set<int> s;
	for (int i = 0; i < n; ++i) {
		s.insert(i+1);
	}
	for (int i = 0; i < n; ++i) {
		int q = inf.readInt(0, n);
		inf.readEoln();
		if (q == 0) {
			s.erase(s.begin());
		} else {
			ensure(!s.count(q));
			s.insert(q);
		}
	}
	
	inf.readEof();
	return 0;
}
