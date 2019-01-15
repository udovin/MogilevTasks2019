#include <bits/stdc++.h>

using namespace std;

long long gcd(long long a, long long b) {
    return b == 0 ? a : gcd(b, a % b);
}

long long lcm(int K) {
    long long ret = 1;
    for (int i = 1; i <= K; i++) {
        ret = ret / gcd(ret, i) * i;
    }
    return ret;
}

int main() {
    long long N, K;
    cin >> N >> K;
    cout << (K > 100 ? 0 : (N-1)/lcm(K) - (N-1)/lcm(K+1)) << endl;
}
