#include <bits/stdc++.h>

using namespace std;

int N, arr[110];
long long ans = 0;

int main() {
    scanf("%d", &N);
    for (int i = 1; i <= N; i++) {
        scanf("%d", &arr[i]);
    }
    for (int i = 1; i <= N; i++) {
        bool used[110] = {};
        int temp = 0;
        for (int j = i; j <= N; j++) {
            if (!used[arr[j]]) {
                used[arr[j]] = 1;
                temp++;
            }
            ans += temp;
        }
    }
    printf("%lld\n", ans);
}
