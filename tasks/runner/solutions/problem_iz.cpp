#include <iostream>
#include <cstdio>
#include <memory.h>

using namespace std;

const int maxn = 333;

int n, x[maxn], y[maxn];
bool vis[maxn];

int d(int u, int v) {
    int ans = 0;
    ans += (x[u] - x[v]) * (x[u] - x[v]);
    ans += (y[u] - y[v]) * (y[u] - y[v]);
    return ans;
}

int rec(int v) {
    vis[v] = 1;
    int u = -1;
    for (int i = 0; i < n; i++) {
        if (!vis[i] && (u == -1 || d(v, u) > d(v, i))) {
            u = i;
        }
    }
    if (u == -1) return 0;
    return rec(u) + d(v, u);
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    cin >> n;
    for (int i = 0; i < n; i++) cin >> x[i] >> y[i];
    
    int ans = 2e9;
    for (int i = 0; i < n; i++) {
        memset(vis, 0, sizeof(vis));
        ans = min(ans, rec(i));
    }
    cout << ans << endl;

    return 0;
}
