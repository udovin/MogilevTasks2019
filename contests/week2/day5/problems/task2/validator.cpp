#include "testlib.h"
#include <string.h>

using namespace std;

typedef long long ll;

ll a[100100];

int main(int argc, char * argv[]) {
	registerValidation(argc, argv);
	string g = validator.group();
	ll n = inf.readLong(1ll, 100000ll, "n");
	inf.readEoln();

	for (int i = 0; i < n; i++) {
		a[i] = inf.readLong(1ll, 1000000000000ll, "a_i");
		if(i < n - 1) {
			inf.readSpace();
		} else {
			inf.readEoln();
		}
	}

	ll x = inf.readLong(1, 1000000000000ll, "x");
	inf.readEoln();
	inf.readEof();

    if(g == "aa"){
		ensuref(1 <= n && n <= 1, "First testset constraint error (n)");
		for(int i = 0; i < n; i++) {
			ensuref(1 <= a[i] && a[i] <= 25, "First testset constraint error (a_i)");
		}
		ensuref(1 <= x && x <= 25, "First testset constraint error (x)");
	} else
	if(g == "bb"){
		ensuref(1 <= n && n <= 3, "First testset constraint error (n)");
		for(int i = 0; i < n; i++) {
			ensuref(1 <= a[i] && a[i] <= 25, "First testset constraint error (a_i)");
		}
		ensuref(1 <= x && x <= 25, "First testset constraint error (x)");
	} else
	if(g == "cc"){
		ensuref(1 <= n && n <= 5, "First testset constraint error (n)");
		for(int i = 0; i < n; i++) {
			ensuref(1 <= a[i] && a[i] <= 25, "First testset constraint error (a_i)");
		}
		ensuref(1 <= x && x <= 25, "First testset constraint error (x)");
	}else if(g == "dd"){
		ensuref(1 <= n && n <= 100000ll, "Second testset constraint error (n)");
		for(int i = 0; i < n; i++) {
			ensuref(1 <= a[i] && a[i] <= 100000ll, "Second testset constraint error (a_i)");
		}
		ensuref(1 <= x && x <= 100000ll, "Second testset constraint error (x)");
	}
	else if(g == "ee") {
		ensuref(1 <= n && n <= 100000ll, "First testset constraint error (n)");
		for(int i = 0; i < n; i++) {
			ensuref(1 <= a[i] && a[i] <= 1000000000000ll, "First testset constraint error (a_i)");
		}
		ensuref(1 <= x && x <= 1000000000000ll, "First testset constraint error (x)");
	}
}
