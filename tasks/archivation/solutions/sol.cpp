#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <map>

using namespace std;

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
