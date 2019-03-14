#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>
#include <random>
#include <climits>
#include <set>

using namespace std;

const int module = (int)1e9 + 7;

struct Matrix {
	int a, b, c, d;
	
	Matrix(int a = 0, int b = 0, int c = 0, int d = 0)
		: a(a), b(b), c(c), d(d) {
	}
};

inline Matrix operator*(const Matrix &a, const Matrix &b) {
	return Matrix (
		((int64_t)a.a * b.a + (int64_t)a.b * b.c) % module,
		((int64_t)a.a * b.b + (int64_t)a.b * b.d) % module,
		((int64_t)a.c * b.a + (int64_t)a.d * b.c) % module,
		((int64_t)a.c * b.b + (int64_t)a.d * b.d) % module
	);
}

inline Matrix makeMat(int delta) {
	delta--;
	if (delta & 1) {
		return Matrix(0, 1, module-1, delta/2 + 2);
	} else {
		return Matrix(0, 1, 0, delta/2 + 1);
	}
}

mt19937 rnd(42);

struct Treap {
	Treap *l, *r;
	int y, val, sum, mx, sz;
	Matrix mat;
	
	Treap(int val)
		: l(nullptr), r(nullptr), y(rnd()), val(val), sum(val), mx(val), sz(1), mat(makeMat(val)) {
	}
};
typedef Treap *pTreap;

inline int getSum(pTreap t) {
	return t ? t->sum : 0;
}

inline int getMx(pTreap t) {
	return t ? t->mx : INT_MIN;
}

inline int getSz(pTreap t) {
	return t ? t->sz : 0;
}

inline Matrix getMat(pTreap t) {
	return t ? t->mat : Matrix(1, 0, 0, 1);
}

inline void upd(pTreap t) {
	if (t) {
		t->sum = getSum(t->l) + t->val + getSum(t->r);
		t->mx = max(getMx(t->l), max(t->val, getMx(t->r)));
		t->sz = getSz(t->l) + 1 + getSz(t->r);
		t->mat = getMat(t->r) * makeMat(t->val) * getMat(t->l);
	}
}

inline bool find(pTreap t, int val) {
	if (!t) {
		return false;
	}
	int mid = getSum(t->l) + t->val;
	if (val < mid) {
		return find(t->l, val);
	} else if (mid == val) {
		return true;
	} else {
		return find(t->r, val - mid);
	}
}

// Left half contains all ones with the position <= x
// Right half contains all ones with the position > x
inline void splitPos(pTreap t, pTreap &l, pTreap &r, int x) {
	if (!t) {
		l = r = nullptr;
		return;
	}
	int mid = getSum(t->l) + t->val;
	if (mid <= x) {
		splitPos(t->r, t->r, r, x - mid);
		l = t;
	} else {
		splitPos(t->l, l, t->l, x);
		r = t;
	}
	upd(l); upd(r);
}

// Left half has exactly x elements
inline void splitSize(pTreap t, pTreap &l, pTreap &r, int x) {
	if (!t) {
		l = r = nullptr;
		return;
	}
	int lsz = getSz(t->l);
	if (x <= lsz) {
		splitSize(t->l, l, t->l, x);
		r = t;
	} else {
		splitSize(t->r, t->r, r, x - lsz - 1);
		l = t;
	}
	upd(l); upd(r);
}

// Right half contains only twos
inline void splitTwo(pTreap t, pTreap &l, pTreap &r) {
	if (!t) {
		l = r = nullptr;
		return;
	}
	if (max(getMx(t->r), t->val) == 2) {
		splitTwo(t->l, l, t->l);
		r = t;
	} else {
		splitTwo(t->r, t->r, r);
		l = t;
	}
	upd(l); upd(r);
}

inline void merge(pTreap &t, pTreap l, pTreap r) {
	if (!l || !r) {
		t = l ? l : r;
		return;
	}
	if (l->y > r->y) {
		merge(l->r, l->r, r);
		t = l;
	} else {
		merge(r->l, l, r->l);
		t = r;
	}
	upd(t);
}

inline void print(pTreap t) {
	if (t) {
		print(t->l);
		cout << t->val << " ";
		print(t->r);
	}
}

inline pTreap alloc(int val) {
	return new Treap(val);
}

inline void dealloc(pTreap &t) {
	delete t;
	t = nullptr;
}

class LongFib {
private:
	pTreap t;
	
	inline bool m_HasBit(int x) {
		return find(t, x);
	}
	
	inline void m_DelBit(int x) {
		assert(m_HasBit(x));
		pTreap l, m, r;
		splitPos(t, l, r, x);
		assert(getSum(l) == x);
		splitPos(l, l, m, x-1);
		assert(m);
		int add = m->val;
		dealloc(m);
		if (r) {
			splitSize(r, m, r, 1);
			m->val += add;
			upd(m);
			merge(r, m, r);
		}
		merge(t, l, r);
	}
	
	inline void m_InsBit(int x) {
		assert(!m_HasBit(x));
		pTreap l, r;
		splitPos(t, l, r, x);
		int add = x - getSum(l);
		assert(add > 0);
		pTreap m = alloc(add);
		merge(l, l, m);
		if (r) {
			splitSize(r, m, r, 1);
			m->val = m->val - add;
			assert(m->val > 0);
			upd(m);
			merge(r, m, r);
		}
		merge(t, l, r);
	}
	
	inline void m_AddZero(int x) {
		if (m_HasBit(x+1)) {
			assert(!m_HasBit(x+2));
			m_DelBit(x+1);
			m_AddZero(x+2);
		} else if (m_HasBit(x-1)) {
			m_DelBit(x-1);
			m_AddZero(x+1);
		} else {
			m_InsBit(x);
		}
	}
	
	inline void m_AddOne(int x) {
		assert(!m_HasBit(x+1));
		if (m_HasBit(x-2)) {
			
			m_DelBit(x);
			m_AddZero(x+1);
			
			pTreap l, m, r; splitPos(t, l, r, x-2);
			assert(r);
			splitSize(r, m, r, 1);
			m->val--;
			assert(m->val > 1);
			upd(m);
			merge(r, m, r);
			splitTwo(l, l, m);
			merge(r, m, r);
			int add = getSum(l) - 2;
			assert(l);
			splitSize(l, l, m, getSz(l) - 1);
			m->val++;
			upd(m);
			merge(l, l, m);
			merge(t, l, r);
			
			assert(!m_HasBit(add));
			m_AddZero(add);
			
		} else {
			m_DelBit(x);
			m_AddZero(x+1);
			m_AddZero(x-2);
		}
	}
	
	inline void m_AddBit(int x) {
		m_HasBit(x) ? m_AddOne(x) : m_AddZero(x);
	}
public:
	inline bool hasBit(int x) {
		return m_HasBit(x + 3);
	}
	
	inline void addBit(int x) {
		m_AddBit(x + 3);
		if (!m_HasBit(1)) {
			m_AddZero(1);
		}
		if (m_HasBit(1)) {
			m_DelBit(1);
		}
		assert(!m_HasBit(1) && !m_HasBit(2));
	}
	
	inline int getAns() {
		if (!m_HasBit(3)) {
			m_InsBit(2);
		}
		pTreap m;
		splitSize(t, m, t, 1);
		int res = 1;
		if (t) {
			pTreap m;
			splitSize(t, m, t, 1);
			Matrix mat = getMat(t);
			mat = mat * Matrix(1, 0, (m->val + 1) / 2, 0);
			res = mat.c;
			merge(t, m, t);
		}
		merge(t, m, t);
		if (m_HasBit(2)) {
			m_DelBit(2);
		}
		return res;
	}
	
	LongFib()
		: t(nullptr) {
	}
};

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	ios_base::sync_with_stdio(false);
	LongFib q;
	int n; cin >> n;
	for (int i = 0; i < n; i++) {
		int a; cin >> a; a--;
		q.addBit(a);
		cout << q.getAns() << "\n";
	}
	return 0;
}
