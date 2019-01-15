#include <bits/stdc++.h>

using namespace std;

int N, cnt = 0, temp, p[1000010];
long long ans = 0;

int main() {
    scanf("%d", &N);
    for (int i = 1; i <= N; i++) {
        scanf("%d", &temp);
        ans -= 1ll * (i - p[temp] - 1) * (i - p[temp]) / 2;
        p[temp] = i;
    }
    for (int i = 1; i <= N; i++) {
        if (p[i] != 0) {
            ans -= 1ll * (N - p[i]) * (N - p[i] + 1) / 2;
            cnt++;
        }
    }
    ans += 1ll * cnt * N * (N + 1) / 2;
    printf("%lld\n", ans);
}
