#include <iostream>
#include <vector>
using namespace std;

class ConvexHullTrick {
private:
	struct Line {
		int64_t a, b;

		int64_t get(int64_t x) {
			return a * x + b;
		}
	};

	vector<Line> hull;
	size_t it;

	bool isBad(vector<Line>::iterator curr) {
		vector<Line>::iterator prev = curr, next = curr;
		--prev, ++next;
		const Line& p = *prev, c = *curr, n = *next;
		return (c.b - n.b) * (c.a - p.a) <= (p.b - c.b) * (n.a - c.a);
	}

public:
	ConvexHullTrick() : hull(), it() {}

	void clear() {
		hull.clear();
		it = 0;
	}

	void addLine(int64_t a, int64_t b) {
		hull.push_back((Line){a, b});
		while (hull.size() > 2 && isBad(hull.end() - 2))
			hull.erase(hull.end() - 2);
	}

	int64_t query(int64_t x) {
		it = min(it, hull.size() - 1);
		while (it + 1 < hull.size()) {
			if (hull[it].get(x) > hull[it + 1].get(x))
				break;
			it++;
		}
		while (it > 0) {
			if (hull[it].get(x) > hull[it - 1].get(x))
				break;
			it--;
		}
		return hull[it].get(x);
	}
};

int main() {
	freopen("permutations.in", "rt", stdin);
	freopen("permutations.out", "wt", stdout);
	int n, m;
	cin >> n >> m;
	vector<int> a(n);
	vector<int> p;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		if (a[i] == 0)
			p.push_back(i);
	}
	ConvexHullTrick ch;
	vector<int64_t> fl(p.size()), fr(p.size());
	vector<vector<int64_t>> f(2, vector<int64_t>(p.size()));
	for (int i = m - 1; i >= 0; i--) {
		for (int j = 0, k = 0, c = 0; j < n; j++) {
			while (k < p.size() && p[k] <= j) {
				fl[k] = c;
				if (k > 0)
					fl[k] += fl[k - 1];
				k++;
			}
			if (k == p.size())
				continue;
			if (a[j] > i + 1)
				c++;
		}
		for (int j = n - 1, k = int(p.size()) - 1, c = 0; j >= 0; j--) {
			while (k >= 0 && p[k] >= j) {
				fr[k] = c;
				if (k + 1 < p.size())
					fr[k] += fr[k + 1];
				k--;
			}
			if (k < 0)
				continue;
			if (a[j] > 0 && a[j] <= i)
				c++;
		}
		for (int j = 0; j < p.size(); j++) {
			f[i % 2][j] = f[(i + 1) % 2][j];
			if (i < m - 1) {
				int64_t flu = fl[j];
				int64_t fld = j > 0 ? fl[j - 1] : 0;
				int64_t fru = fr[j];
				int64_t frd = j + 1 < p.size() ? fr[j + 1] : 0;
				int64_t fp = j > 0 ? f[(i + 1) % 2][j - 1] : 0;
				ch.addLine(j, fp + j * int64_t(1 - j) + fru - fld);
				f[i % 2][j] = max(f[(i + 1) % 2][j], flu - frd + ch.query(j));
			} else {
				int64_t flu = fl[j];
				int64_t fld = 0;
				int64_t fru = fr[0];
				int64_t frd = j + 1 < p.size() ? fr[j + 1] : 0;
				f[i % 2][j] = flu - fld + fru - frd;
			}
		}
		ch.clear();
	}
	int64_t ans = 0;
	vector<int> cnt(m);
	for (int i = 0; i < n; i++) {
		if (a[i] == 0)
			continue;
		for (int j = m - 1; j >= a[i]; j--)
			ans += cnt[j];
		cnt[a[i] - 1]++;
	}
	if (!p.empty()) {
		ans += f[0][p.size() - 1];
	}
	cout << ans << endl;
	return 0;
}
