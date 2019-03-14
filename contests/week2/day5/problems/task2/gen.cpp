#include <bits/stdc++.h>
#include "testlib.h"

using namespace std;

#define pb push_back
#define ppb pop_back
#define mp make_pair
#define fs first
#define sc second
#define abs(a) ((a) < 0 ? -(a) : (a))
#define sqr(a) ((a) * (a))

typedef unsigned int uint;
typedef long long ll;
typedef unsigned long long ull;

const double eps = 1e-9;
const int mod = (int) 1e+9 + 7;
const double pi = acos(-1.);
const int maxn = 100100;

int main(int argc, char* argv[]) {

	registerGen(argc, argv, 1);
	ll mxn = stoll(argv[1]), mnn = max(1ll, mxn / 5);
	ll n = rnd.next(mnn, mxn);

	bool withans = stoll(argv[4]);

	set<ll> st;
	ll mxa = stoll(argv[2]);
	vector<ll> a;
	if(withans) {
		a.pb(1);
		st.insert(1);
	}
	for(int i = withans; i < n; i++) {
		ll x = rnd.next(2ll, mxa);
		while(st.count(x)) {
			x = rnd.next(2ll, mxa);
		}
		st.insert(x);
		a.pb(x);
	}
	shuffle(a.begin(), a.end());

	ll mxx = stoll(argv[3]), mnx = max(1ll, mxx / 5);
	ll x = rnd.next(mnx, mxx);

	printf("%lld\n", n);
	for(int i = 0; i < n; i++) {
		printf("%lld%c", a[i], " \n"[i == n - 1]);
	}
	printf("%lld\n", x);

	return (0);
}

//by Andrey Kim
