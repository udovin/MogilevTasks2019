#include <bits/stdc++.h>

using namespace std;

struct domino {
    int x, h, i;
    bool operator< (const domino &a) {
        return x < a.x;
    }
};

int a, n, r1, r2, ans[100010];
domino d[100010];
stack<int> q;

int main() {
    scanf("%d", &n); n++;
    for (a = 1; a < n; a++) {
        scanf("%d%d", &d[a].x, &d[a].h);
        d[a].i = a;
    }
    sort(d + 1, d + n);
    for (a = n - 1; a > 0; a--) {
        ans[d[a].i] = 1;
        while (!q.empty() && d[a].x + d[a].h > d[q.top()].x) {
            ans[d[a].i] += ans[d[q.top()].i];
            q.pop();
        }
        q.push(a);
    }
    for (a = 1; a < n; a++) {
        printf("%d ", ans[a]);
    }
}
