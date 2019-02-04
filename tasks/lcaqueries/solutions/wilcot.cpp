#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;

const int N = 1e5 + 111;

int n, q;
vector<int> g[N];
int up[N][20];
int tin[N], tout[N];
int timer;
int count[N];

void dfs(int x, int p) {
    count[x] = 1;
    tin[x] = timer++;
    up[x][0] = p;
    for (int i = 1; i < 20; i++)
        up[x][i] = up[up[x][i - 1]][i - 1];
    for (int y : g[x]) {
        if (y != p) {
            dfs(y, x);
            count[x] += count[y];
        }
    }
    tout[x] = timer++;
}

bool upper(int x, int y) {
    return tin[x] <= tin[y] && tout[x] >= tout[y];
}

int closest(int p, int x) {
    for (int i = 19; i >= 0; i--)
        if (!upper(up[x][i], p))
            x = up[x][i];
    return x;
}

int main() {
    freopen("lcaqueries.in", "rt", stdin);
    freopen("lcaqueries.out", "wt", stdout);
    cin >> n >> q;
    for (int i = 1; i < n; i++) {
        int x, y;
        cin >> x >> y;
        x--, y--;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    dfs(0, 0);
    for (int i = 0; i < q; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        a--, b--, c--;
        if (upper(c, a) && upper(c, b)) {
            a = closest(c, a);
            b = closest(c, b);
            if (a == b)
                cout << 0;
            else
                cout << n - count[a] - count[b];
        } else if (upper(c, a) && !upper(c, b)) {
            a = closest(c, a);
            cout << count[c] - count[a];
        } else if (!upper(c, a) && upper(c, b)) {
            b = closest(c, b);
            cout << count[c] - count[b];
        } else {
            cout << 0;
        }
        cout << endl;
    }
    return 0;
}
