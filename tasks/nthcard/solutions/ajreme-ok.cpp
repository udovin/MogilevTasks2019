#include <stdio.h>
#include <algorithm>
#include <math.h>

using namespace std;

const int N = 100010;
int n, k, block, a[N] = {}, last[N] = {};
bool is[N] = {};

struct query {
    int l, r, ind, ans;

    inline bool operator< (const query& cmp) const {
        return make_pair(l / block, r) < make_pair(cmp.l / block, cmp.r);
    }
} arr[N];

int ptr1 = 0, ptr2 = 0;
int cur[N] = {}, val = 0;

inline void del(const int x) {
    if (--cur[x] == 0) {
        val--;
    }
}

inline void add(const int x) {
    if (++cur[x] == 1) {
        val++;
    }
}

inline void precalc(int l, int r) {
    ptr1 = l, ptr2 = r;
    while (l <= r) {
        add(a[l++]);
    }
}

inline int calc(const int l, const int r) {
    if (ptr1 == 0) {
        precalc(l, r);
    }
    else {
        while (l < ptr1) {
            add(a[--ptr1]);
        }
        while (ptr1 < l) {
            del(a[ptr1++]);
        }
        while (r < ptr2) {
            del(a[ptr2--]);
        }
        while (ptr2 < r) {
            add(a[++ptr2]);
        }
    }
    return val;
}

inline bool cmp(const query& a, const query& b) {
    return a.ind < b.ind;
}

inline void solve() {
    block = int(sqrt(k)) + 1;
    for (int i = 1; i <= k; i++) {
        arr[i].ind = i;
        if (last[a[i]] != 0) {
            arr[last[a[i]]].l = last[a[i]] + 1;
            arr[last[a[i]]].r = i - 1;
        }
        else {
            printf("%d ", a[i]);
            is[a[i]] = 1;
        }
        last[a[i]] = i;
    }
    sort(arr + 1, arr + 1 + k);
    for (int i = 1; i <= k; i++) {
        if (arr[i].l == 0) {
            arr[i].ans = n - 1;
        }
        else if (arr[i].l <= arr[i].r) {
            arr[i].ans = calc(arr[i].l, arr[i].r);
        }
        else {
            arr[i].ans = 0;
        }
    }
    sort(arr + 1, arr + 1 + k, cmp);
    for (int i = 1; i <= n; i++) {
        if (!is[i]) {
            printf("%d ", i);
        }
    }
    printf("\n");
}

int main() {
    scanf("%d%d", &n, &k);
    for (int i = 1; i <= k; i++) {
        scanf("%d", &a[i]);
    }
    solve();
    for (int i = 1; i <= k; i++) {
        printf("%d\n", arr[i].ans);
    }
}