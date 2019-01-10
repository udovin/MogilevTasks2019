#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;

int n;
string s;

inline bool check(int a, int b) {
	for (int i = 1; i < b; i++) {
		int d = (26 + s[0] - s[a * i]) % 26;
		for (int j = 1; j < a; j++) {
			int cd = (26 + s[j] - s[a * i + j]) % 26;
			if (cd != d)
				return false;
		}
	}
	return true;
}

pair<string, string> gen(int a, int b) {
	string p;
	string q;
	p.resize(a);
	q.resize(b);
	p[0] = 'a';
	for (int i = 1; i < a; i++)
		p[i] = 'a' + (p[0] - 'a' + (s[i] - s[0] + 26) % 26) % 26;
	for (int i = 0; i < b; i++)
		q[i] = 'a' + (s[0] - 'a' + (s[a * i] - s[0] + 26) % 26) % 26;
	return {p, q};
}

int main() {
	cin >> s;
	n = s.size();
	pair<string, string> ans;
	string pans;
	for (int i = 1; i * i <= n; i++) {
		int j = n / i;
		if (j * i != n)
			continue;
		if (check(i, j)) {
			auto p = gen(i, j);
			string q = p.first + p.second;
			if (pans.empty() || q < pans)
				ans = p, pans = q;
		}
		if (i != j && check(j, i)) {
			auto p = gen(j, i);
			string q = p.first + p.second;
			if (pans.empty() || q < pans)
				ans = p, pans = q;
		}
	}
	if (pans.empty()) {
		cout << -1 << endl;
		return 0;
	}
	cout << ans.first << ' ' << ans.second << endl;
	return 0;
}
