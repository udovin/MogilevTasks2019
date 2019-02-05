#include <string>
#include <iostream>
#include <random>
#include <fstream>
#include <vector>
#include <utility>

using namespace std;

int64_t ans = 0;
vector <int64_t> f[2];

string getTestName(const int& test_number) {
	string ans = "00";
	ans[0] = char('0' + test_number / 10);
	ans[1] = char('0' + test_number % 10);
	ans = "../tests/tests/" + ans;
	return move(ans);
}

mt19937_64 rnd(42);

int64_t solve(const string& s, int m) {
	f[0].assign(m, 0);
	f[1].assign(m, 0);
	ans = 0;
	for (size_t i = 0; i < s.size(); i++) {
		for (int j = 0; j < m; j++) {
			f[(i + 1) & 1][j] = 0;
		}
		f[(i + 1) & 1][(s[i] - '0') % m] = 1;
		for (int j = 0; j < m; j++) {
			f[(i + 1) & 1][(j * 10 + s[i] - '0') % m] += f[i & 1][j];
		}
		ans += f[(i + 1) & 1][0];
	}
	return ans;
}

void print(const int& test_number, const string& s, int m) {
	ofstream test_in(getTestName(test_number));
	//cout << getTestName(test_number) << endl;
	test_in << s << " " << m << "\n";
	test_in.close();
	ofstream test_out(getTestName(test_number) + ".a");
	test_out << solve(s, m) << "\n";
	//cout << getTestName(test_number) << endl;
	test_out.close();
}

string generateString(int sz) {
	string ans;
	for (int i = 0; i < sz; i++) {
		ans = ans + char('0' + rnd() % 10);
	}
	return move(ans);
}

int main() {
	for (int i = 1; i <= 15; ++i) {
		int sz = rnd() % 30 + 70;
		int m = rnd() % 30 + 70;
		string s(generateString(sz));
		print(i, s, m);
		cout << i << endl;
	}
	for (int i = 16; i <= 30; ++i) {
		int sz = rnd() % 700 + 4300;
		int m = rnd() % 700 + 4300;
		string s(generateString(sz));
		print(i, s, m);
		cout << i << endl;
	}
	for (int i = 31; i <= 40; ++i) {
		int sz = rnd() % 5000 + 1;
		int m = rnd() % (500000 / sz) + 500000 / sz;
		m = min(100000, m);
		string s(generateString(sz));
		print(i, s, m);
		cout << i << endl;
	}
	for (int i = 40; i <= 48; ++i) {
		int sz = rnd() % 50000 + 50000;
		int m = rnd() % (500000 / sz) + 500000 / sz + 1;
		m = min(100000, m);
		//cout << sz << " " << m << endl;
		string s(generateString(sz));
		print(i, s, m);
		cout << i << endl;
	}
	print(49, generateString(10), 100000);
	cout << 49 << endl;
	print(50, generateString(100000), 10);
	cout << 50 << endl;
	return 0;
}
