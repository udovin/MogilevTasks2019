#include "testlib.h"

using namespace std;

int main(int argc, char *argv[]) {
	registerValidation(argc, argv);
	
	inf.readInt(0, 10, "t");
	inf.readEoln();
	int n = inf.readInt(1, 1000, "n");
	inf.readSpace();
	int m = inf.readInt(1, 1000, "m");
	inf.readSpace();
	inf.readInt(1, 1000, "l");
	inf.readSpace();
	inf.readInt(1, 1000, "h");
	inf.readEoln();
	
	for (int i = 0; i < n; ++i) {
		string s = inf.readString();
		ensure((int)s.size() == m);
		for (int j = 0; j < m; ++j) {
			ensuref(s[j] == 'F' || s[j] == 'C', "char %c(#%d) found, C or F expected (row %d, col %d)", s[i], int(s[i]), i+1, j+1);
		}
	}
	
	inf.readEof();
	return 0;
}
