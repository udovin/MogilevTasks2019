#include "testlib.h"

int main(int argc, char *argv[]) {
	registerValidation(argc, argv);
	
	int n = inf.readInt(1, 500, "n");
	inf.readEoln();
	auto a = inf.readInts(n, 1, n, "a");
	for (int i = 2; i < n; ++i) {
		ensure(a[i] != a[i-1]);
	}
	inf.readEoln();
	
	switch (validator.group()[0]) {
		case '1': {
			ensure(n <= 9);
		} break;
		case '2': {
			for (int i = 0; i < n; ++i) {
				ensure(a[i] <= 2);
			}
		} break;
		case '3': {
			ensure(n <= 20);
		} break;
		case '4': {
			ensure(n <= 100);
		} break;
		default: {
			// no checks
		}
	}
	
	inf.readEof();
	return 0;
}
