#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <map>

using namespace std;

int main() {
	int n, q;
	cin >> n >> q;
	vector <pair <string, char> > s(q);
	for (int i = 0; i < q; i++) {
		cin >> s[i].first >> s[i].second;
	}
	cout << solve(n, q, s) << endl;
	return 0;
}
