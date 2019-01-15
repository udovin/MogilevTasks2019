#include <bits/stdc++.h>

using namespace std;

int n, arr[100000];
long long ans = 0;

inline int solve(int a, int b) {
    set<int> x;
    for (int i = a; i <= b; i++) {
        x.insert(arr[i]);
    }
    return x.size();
}

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &arr[i]);
    }
    for (int i = 1; i <= n; i++) {
        for (int j = i; j <= n; j++) {
            ans += solve(i, j);
        }
    }
    print("%lld", ans);
}
