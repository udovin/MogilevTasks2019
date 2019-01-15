#include <bits/stdc++.h>

using namespace std;

int N, K, ans = 0;

int streak(int x) {
    for (int k = 1; k <= K; k++) {
        if ((x + k) % (k + 1) != 0) {
            return k;
        }
    }
    return 1000000000;
}

int main() {
    cin >> N >> K;
    for (int i = 2; i <= N; i++) {
        ans += (streak(i) == K);
    }
    cout << ans << endl;
}
