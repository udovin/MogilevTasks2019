#include <bits/stdc++.h>

using namespace std;

long long n;
bool isprime[20000] = {};
vector<int> prime;

void sieve() {
    for (int i = 2; i < 20000; i++) {
        if (!isprime[i]) {
            prime.push_back(i);
            for (int j = i*i; j < 20000; j += i) {
                isprime[j] = 1;
            }
        }
    }
}

long long powll(long long a, long long b) {
    if (b == 0) {
        return 1;
    }
    long long temp = powll(a, b/2);
    return temp * temp * (b % 2 != 0 ? a : 1);
}

bool cant_mul(long long cur, int p, int s) {
    return 1.0l*cur*pow(1.0l*prime[p], s) > n;
}

int solve(long long cur = 1, int ptr = 0, int need4 = 0) {
    int ret = 1 - need4;
    for (int i = ptr; i < prime.size(); i++) {
        if (cant_mul(cur, i, (need4 == 1 ? 4 : 6))) {
            break;
        }
        for (int j = 6; j < 60; j += 6) {
            if (cant_mul(cur, i, j)) {
                break;
            }
            ret += solve(cur*powll(prime[i], j), i+1, need4);
        }
        for (int j = 4; j < 60; j += 6) {
            if (cant_mul(cur, i, j)) {
                break;
            }
            ret += solve(cur*powll(prime[i], j), i+1, 1 - need4);
        }
    }
    return ret;
}

int main() {
    cin >> n;
    sieve();
    cout << solve();
}
