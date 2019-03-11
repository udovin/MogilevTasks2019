#include "testlib.h"

int main(int argc, char *argv[]) {
	registerValidation(argc, argv);
	
	// minimalistic validator, other things are checked by the solution
	int n = inf.readInt(1, 500'000, "n");
	inf.readEoln();
	for (int i = 0; i < n; ++i) {
		std::string s = inf.readToken();
		inf.readSpace();
		ensure(s == "info" || s == "rollback" || s == "undo" || s == "clone" || s == "check");
		inf.readInt(1, n, "c_" + vtos(i+1));
		if (s == "info") {
			inf.readSpace();
			inf.readInt(1, int(1e9), "p_" + vtos(i+1));
		}
		inf.readEoln();
	}
	
	inf.readEof();
	return 0;
}
