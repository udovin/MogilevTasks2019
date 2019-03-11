#include "testlib.h"

int main(int argc, char *argv[]) {
	registerValidation(argc, argv);
	
	int n = inf.readInt(1, 200'000, "n");
	inf.readEoln();
	
	inf.readInts(n, 1, n, "a");
	inf.readEoln();
	
	int q = inf.readInt(1, 200'000, "q");
	inf.readEoln();
	
	for (int i = 0; i < q; ++i) {
		inf.readInt(1, n, "p_" + vtos(i+1));
		inf.readSpace();
		inf.readInt(1, n, "p_" + vtos(i+1));
		inf.readEoln();
	}
	
	inf.readEof();
	return 0;
}
