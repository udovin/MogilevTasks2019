#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

struct SegTree {
	int n;
	vector<int64_t> t;
	vector<int64_t> p;

	int64_t get(int v, int l, int r) {
		if (p[v] == 0) {
			return t[v];
		}
		return p[v] * (r - l);
	}

	void push(int v, int l, int r) {
		if (p[v] == 0) {
			return;
		}
		p[v * 2 + 1] = p[v];
		p[v * 2 + 2] = p[v];
		t[v] = get(v, l, r);
		p[v] = 0;
	}

	int64_t query(int v, int l, int r, int ql, int qr) {
		if (ql >= qr) {
			return 0;
		}
		if (ql == l && qr == r) {
			return get(v, l, r);
		}
		int m = (l + r) / 2;
		push(v, l, r);
		int64_t vl = query(v * 2 + 1, l, m, ql, min(qr, m));
		int64_t vr = query(v * 2 + 2, m, r, max(m, ql), qr);
		return vl + vr;
	}

	void update(int v, int l, int r, int ql, int qr, int x) {
		if (ql >= qr) {
			return;
		}
		if (ql == l && qr == r) {
			p[v] = x;
			return;
		}
		int m = (l + r) / 2;
		push(v, l, r);
		update(v * 2 + 1, l, m, ql, min(qr, m), x);
		update(v * 2 + 2, m, r, max(m, ql), qr, x);
		t[v] = get(v * 2 + 1, l, m) + get(v * 2 + 2, l, m);
	}

	SegTree(int n) : n(n), t(4 * n), p(4 * n) {}

	int64_t query(int l, int r) {
		return query(0, 0, n, l, r);
	}

	void update(int l, int r, int x) {
		update(0, 0, n, l, r, x);
	}
};

int main() {
	freopen("segtree2.in", "rt", stdin);
	freopen("segtree2.out", "wt", stdout);
	int n, q;
	cin >> n >> q;
	SegTree t(n);
	for (int i = 0; i < q; i++) {
		char c;
		int l, r;
		cin >> c >> l >> r;
		if (c == '?') {
			cout << t.query(l - 1, r) << endl;
		} else {
			int x;
			cin >> x;
			t.update(l - 1, r, x);
		}
	}
	return 0;
}