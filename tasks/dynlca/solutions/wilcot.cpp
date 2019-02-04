#include <bits/stdc++.h>
using namespace std;

class LinkCutTree {
private:
	struct Vertex {
		int left, right, parent;
		bool revert;

		Vertex()
			: left(-1), right(-1), parent(-1), revert() {}
	};

	vector<Vertex> t;

	bool isRoot(int x) const {
		int p = t[x].parent;
		return p == -1 || (t[p].left != x && t[p].right != x);
	}

	void push(int x) {
		if (t[x].revert) {
			if (t[x].left != -1)
				t[t[x].left].revert = !t[t[x].left].revert;
			if (t[x].right != -1)
				t[t[x].right].revert = !t[t[x].right].revert;
			swap(t[x].left, t[x].right);
			t[x].revert = false;
		}
	}

	void rotate(int x) {
		int p = t[x].parent;
		int g = t[p].parent;
		if (g != -1) {
			if (t[g].left == p)
				t[g].left = x;
			else if (t[g].right == p)
				t[g].right = x;
		}
		t[x].parent = g;
		if (t[p].left == x) {
			t[p].left = t[x].right;
			if (t[p].left != -1)
				t[t[p].left].parent = p;
			t[x].right = p;
		} else {
			t[p].right = t[x].left;
			if (t[p].right != -1)
				t[t[p].right].parent = p;
			t[x].left = p;
		}
		t[p].parent = x;
	}

	void splay(int x) {
		while (!isRoot(x)) {
			int p = t[x].parent;
			if (!isRoot(p)) {
				int g = t[p].parent;
				push(g), push(p), push(x);
				bool zigzig = (x == t[p].left) == (p == t[g].left);
				rotate(zigzig ? p : x);
			}
			push(p), push(x);
			rotate(x);
		}
		push(x);
	}

	int expose(int x) {
		int c = -1;
		for (int y = x; y != -1; y = t[y].parent) {
			splay(y);
			t[y].right = c;
			c = y;
		}
		splay(x);
		return c;
	}

public:
	LinkCutTree(int n) : t(n) {}

	void evert(int x) {
		expose(x);
		t[x].revert = !t[x].revert;
	}

	int root(int x) {
		expose(x);
		push(x);
		while (t[x].left != -1) {
			x = t[x].left;
			push(x);
		}
		expose(x);
		return x;
	}

	int parent(int x) {
		expose(x);
		if (t[x].left == -1)
			return -1;
		x = t[x].left;
		push(x);
		while (t[x].right != -1) {
			x = t[x].right;
			push(x);
		}
		return x;
	}

	bool path(int x, int y) {
		if (x == y)
			return true;
		expose(x);
		expose(y);
		return t[x].parent != -1;
	}

	void link(int x, int y) {
		if (path(x, y))
			throw exception();
		evert(x);
		t[x].parent = y;
	}

	void cut(int x) {
		expose(x);
		if (t[x].left == -1)
			throw exception();
		t[t[x].left].parent = -1;
		t[x].left = -1;
	}

	int lca(int x, int y) {
		if (!path(x, y))
			return -1;
		expose(x);
		return expose(y);
	}
};

int main() {
	freopen("dynlca.in", "rt", stdin);
	freopen("dynlca.out", "wt", stdout);
	int n, m;
	cin >> n >> m;
	LinkCutTree t(n);
	for (int i = 0; i < m; i++) {
		string s;
		cin >> s;
		if (s == "link") {
			int x, y;
			cin >> x >> y;
			x--, y--;
			t.link(x, y);
		}
		if (s == "cut") {
			int x;
			cin >> x;
			x--;
			t.cut(x);
		}
		if (s == "lca") {
			int x, y;
			cin >> x >> y;
			x--, y--;
			cout << t.lca(x, y) + 1 << endl;
		}
	}
	return 0;
}
