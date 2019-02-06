#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

struct SegTree {
	int n;
	vector<int64_t> t;

	int64_t query(int v, int l, int r, int ql, int qr) {
		if (ql >= qr) {
			return 0;
		}
		if (ql == l && qr == r) {
			return t[v];
		}
		int m = (l + r) / 2;
		int64_t vl = query(v * 2 + 1, l, m, ql, min(qr, m));
		int64_t vr = query(v * 2 + 2, m, r, max(m, ql), qr);
		return vl + vr;
	}

	void update(int v, int l, int r, int i, int x) {
		if (l + 1 == r) {
			t[v] += x;
			return;
		}
		int m = (l + r) / 2;
		if (i < m) {
			update(v * 2 + 1, l, m, i, x);
		} else {
			update(v * 2 + 2, m, r, i, x);
		}
		t[v] = t[v * 2 + 1] + t[v * 2 + 2];
	}

	SegTree(int n) : n(n), t(4 * n) {}

	int64_t query(int l, int r) {
		return query(0, 0, n, l, r);
	}

	void update(int i, int x) {
		update(0, 0, n, i, x);
	}
};

int main() {
	freopen("segtree1.in", "rt", stdin);
	freopen("segtree1.out", "wt", stdout);
	int n, q;
	cin >> n >> q;
	SegTree t(n);
	for (int i = 0; i < q; i++) {
		char c;
		cin >> c;
		if (c == '?') {
			int l, r;
			cin >> l >> r;
			cout << t.query(l - 1, r) << endl;
		} else {
			int i, x;
			cin >> i >> x;
			t.update(i - 1, x);
		}
	}
	return 0;
}