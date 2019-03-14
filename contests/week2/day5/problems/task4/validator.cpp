#include "testlib.h"

int main(int argc, char *argv[]) {
	registerValidation(argc, argv);
	
	int n = inf.readInt(1, 100'000, "n");
	inf.readEoln();
	inf.readInts(n, 1, int(1e9), "a");
	inf.readEoln();
	
	inf.readEof();
	return 0;
}
