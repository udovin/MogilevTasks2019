#include <iostream>
#include <string>
#include <fstream>
#include <vector>

using namespace std;

int main() {
	string s; int m;
	cin >> s; m = 4; //cf edition
	//cin >> s >> m;
	cout << solve(s, m) << endl;
	return 0;
}
