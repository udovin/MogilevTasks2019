#include <iostream>
#include <vector>
#include "testlib.h"

using namespace std;

// Дерево Фенвика (sum)

class fenwick {
private :
	vector <int> v;
public :

	void modify(int i, int delta) {
		for (; i < (int) v.size(); i |= i + 1)
			v[i] += delta;
	}
	
	fenwick(int n) {
		v.assign(n, 0);
	}
	
	fenwick(vector <int> a) {
		v.assign(a.size(), 0);
		for (size_t i = 0; i < a.size(); i++)
			modify(i, a[i]);
	}
	
	int get_sum(int i) {
		int ans = 0;
		for (; i >= 0; i &= i + 1, i--)
			ans += v[i];
		return ans;
	}
	
	int sum(int l, int r) {
		if (l > r) return 0;
		return get_sum(r) - get_sum(l - 1);
	}
};

fenwick f(1000000);
vector <int> a, ans_val, ans_p;
vector <int> pos;
int n, k;

int main(int argc, char **argv) {
	registerTestlibCmd(argc, argv);

	n = inf.readInt();
	k = inf.readInt();
	a.resize(k);
	for (int i = 0; i < k; i++) {
		a[i] = inf.readInt(); a[i]--;
	}
	
	ans_p.resize(n);
	for (int i = 0; i < n; i++) {
		ans_p[i] = ouf.readInt(); ans_p[i]--;
		if (ans_p[i] < 0) {
			quitf(_pe, "Wrong output format");
		}
	}
	ans_val.resize(k);
	for (int i = 0; i < k; i++) {
		ans_val[i] = ouf.readInt();
		if (ans_val[i] < 0) {
			quitf(_pe, "Wrong output format");
		}
	}

	pos.assign(n, -1);
	pos[a[k - 1]] = 0;
	int cur_pos = 1, cnt = 1;
	for (int i = k - 2; i >= 0; --i) {
		if ((pos[a[i]] == -1) && (cnt <= ans_val[i])) {
			pos[a[i]] = cur_pos; cur_pos++; cnt++;
			continue;
		}
		if (cur_pos == pos[a[i]] + 1 + ans_val[i] + f.sum(pos[a[i]], cur_pos - 1)) {
			f.modify(pos[a[i]], 1);//cout << "edited" << pos[a[i]] << endl;
			pos[a[i]] = cur_pos; cur_pos++;
			continue;
		}
		quitf(_wa, "Wrong answer in cycle for 1 %d %d % d : %d %d", i, ans_val[i], cur_pos, pos[a[i]], f.sum(pos[a[i]], cur_pos - 1));
	}
	vector < pair <int, int> > z(n);
	for (int i = 0; i < n; i++) {
		z[i].first = pos[i];
		z[i].second = i;
	}
	sort(z.rbegin(), z.rend());
	/*
	for (int i = 0; i < n; i++) {
		cout << z[i].first << " " << z[i].second << " " << a[i] << endl;
	}
	*/
	for (int i = n - 1; (i >= 0) && (z[i].first != -1); i--) {
		if (z[i].second != a[i]) {
			quitf(_wa, "Wrong answer in cycle for 2");
		}
	}
	quitf(_ok, "ok");
}

