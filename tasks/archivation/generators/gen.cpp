#include <string>
#include <iostream>
#include <random>
#include <fstream>
#include <map>
#include <vector>
#include <utility>

using namespace std;

string getTestName(const int& test_number) {
	string ans = "00";
	ans[0] = char('0' + test_number / 10);
	ans[1] = char('0' + test_number % 10);
	ans = "../tests/tests/" + ans;
	return move(ans);
}

mt19937_64 rnd(42);

const int MODULE = 1000000000 + 7;

vector <long long> f[2];
int ans = 0;

int solve(int n, int q, vector < pair <string, char> >& s) {
	map < pair <char, char>, int > mp;
	for (int i = 0; i < q; i++) {
		mp[{s[i].first[0], s[i].second}]++;
	}
	vector < pair <int, int> > a[26];
	for (auto x : mp) {
		a[x.first.first - 'a'].push_back({x.first.second - 'a', x.second});
	}
	f[0].assign(26, 0);
	f[1].assign(26, 0);
	for (int j = 0; j < 26; j++) {
		for (size_t k = 0; k < a[j].size(); k++) {
			f[0][a[j][k].first] += a[j][k].second;
			f[0][a[j][k].first] %= MODULE;
		}
	}
	/*
	cout << "kokoko" << endl;
	for (int i = 0; i < 26; i++) {
		cout << f[0][i] << " ";
	}
	cout << endl;
	*/
	for (int i = 0; i < n - 2; i++) {
		for (int j = 0; j < 26; j++) {
			f[(i + 1) & 1][j] = 0;
		}
		for (int j = 0; j < 26; j++) {
			for (size_t k = 0; k < a[j].size(); k++) {
				f[(i + 1) & 1][a[j][k].first] += f[i & 1][j] * a[j][k].second;
				f[(i + 1) & 1][a[j][k].first] %= MODULE;
			}
		}
		/*
		cout << "kokoko" << endl;
		for (int j = 0; j < 26; j++) {
			cout << f[(i + 1) & 1][j] << " ";
		}
		cout << endl;
		*/
	}
	
	return f[(n - 2) & 1][0];
}


void print(const int& test_number, int n, int q, vector < pair <string, char> >& s) {
	ofstream test_in(getTestName(test_number));
	//cout << getTestName(test_number) << endl;
	test_in << n << " " << q << "\n";
	for (int i = 0; i < q; i++) {
		test_in << s[i].first << " " << s[i].second << "\n";
	}
	test_in.close();
	ofstream test_out(getTestName(test_number) + ".a");
	test_out << solve(n, q, s) << "\n";
	//cout << getTestName(test_number) << endl;
	test_out.close();
}

vector < pair<string, char> > generate(int sz) {
	vector < pair<string, char> > added;
	vector < pair<string, char> > toadd;
	for (int i = 0; i < 26; i++) {
		for (int j = 0; j < 26; j++) {
			for (int k = 0; k < 26; k++) {
				toadd.push_back({string("") + (char('a' + i)) + (char('a' + j)), char('a' + k)});
			}
		}
	}
	for (int i = 0; i < sz; i++) {
		int z = rnd() % toadd.size();
		added.push_back(toadd[z]);
		swap(toadd[z], toadd[toadd.size() - 1]);
		toadd.pop_back();
	}
	return added;
}

int main() {
	for (int i = 1; i <= 15; ++i) {
		int n = rnd() % 3 + 2;
		int q = rnd() % 9 + 2;
		vector < pair<string, char> > s(generate(q));
		print(i, n, q, s);
		cout << i << endl;
	}

	for (int i = 16; i <= 30; ++i) {
		int n = rnd() % 50 + 150;
		int q = rnd() % 50 + 150;
		vector < pair<string, char> > s(generate(q));
		print(i, n, q, s);
		cout << i << endl;
	}

	for (int i = 31; i <= 49; ++i) {
		int n = rnd() % 700 + 4300;
		int q = rnd() % 1000 + 16000;
		vector < pair<string, char> > s(generate(q));
		print(i, n, q, s);
		cout << i << endl;
	}
	{
		int n = 5000;
		int q = 17576;
		vector < pair<string, char> > s(generate(q));
		print(50, n, q, s);
		cout << 50 << endl;
	}
	
	return 0;
}
