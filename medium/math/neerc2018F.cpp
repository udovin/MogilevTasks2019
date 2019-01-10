#include <iostream>
using namespace std;
typedef long long ll;

ll gcd(ll a, ll b) {
	ll c;
	while (a > 0) {
		c = a;
		a = b % a;
		b = c;
	}
	return b;
}

int main() {
	ll n;
	cin >> n;
	ll a = -1, b = -1;
	for (ll i = 2; i * i <= n; i++) {
		if (n % i != 0)
			continue;
		ll j = n / i;
		if (gcd(i, j) == 1) {
			a = i, b = j;
		}
	}
	if (a == -1 && b == -1) {
		cout << "NO" << endl;
		return 0;
	}
	cout << "YES" << endl << 2 << endl;
	for (ll i = 0; i * b < n; i++) {
		if ((n - 1 - i * b) % a != 0)
			continue;
		ll j = (n - 1 - i * b) / a;
		if (i >= a || j >= b)
			continue;
		cout << i << ' ' << a << endl;
		cout << j << ' ' << b << endl;
		return 0;
	}
	return 0;
}
