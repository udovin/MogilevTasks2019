#include "testlib.h"

int main(int argc, char *argv[]) {
	registerValidation(argc, argv);
	
	int n = inf.readInt(1, 500'000, "n");
	inf.readSpace();
	long long k = inf.readLong(1, (long long)n * (n-1) / 2, "k");
	inf.readEoln();
	
	auto a = inf.readInts(n, 1, int(1e9), "a");
	inf.readEoln();
	
	switch (validator.group()[0]) {
		case '1': {
			ensure(n <= 10'000);
		} break;
		case '2': {
			for (int i = 0; i < n; ++i) {
				ensure(a[i] <= 5'000);
			}
		} break;
		case '3': {
			ensure(k <= 1'000'000);
		} break;
		case '4': {
			ensure(n <= 100'000);
		} break;
		default: {
			// do nothing
		}
	}
	
	inf.readEof();
	return 0;
}
