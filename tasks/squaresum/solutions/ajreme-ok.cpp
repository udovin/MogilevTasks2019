#include <iostream>

using namespace std;

const __int128 mod = 1000*1000*1000+7;
__int128 N, L = 1, R = 1, ans = 0;

__int128 sqsum(__int128 x) {
    __int128 a = x*(x+1)/2;
    __int128 b = 2*x+1;
    if (a % 3 == 0) {
        return (((a/3)%mod)*b)%mod;
    }
    return ((a%mod)*((b/3)%mod))%mod;
}

int main() {
    uint64_t temp;
    cin >> temp;
    N = temp;
    while (R < N) {
        ans = (ans + ((sqsum(R) - sqsum(L-1) + mod) % mod)*(N/L)) % mod;
        L = R+1;
        R = N/(N/(R+1));
    }
    ans = (ans + sqsum(N) - sqsum(L-1) + mod) % mod;
    cout << uint64_t(ans);
}
