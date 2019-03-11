//Solution by Tima
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <cstring>
#include <map>
#include <cstdlib>
#include <ctime>
#include <cassert>
#include <bitset>
#define f first
#define s second
#define ll long long
#define ull unsigned long long
#define mp make_pair
#define pb push_back
#define vi vector <int>
#define ld long double
#define pii pair<int, int>
#define y1 sda
using namespace std;    
const int N = int(1e6) + 10, mod = int(1e9)  + 7; 

int n,q, a[N];

int mx, pref[N], suf[N], ans[N];

int main () {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	scanf("%d", &n);
	for(int i = 1; i <= n; i++){
		scanf("%d", &a[i]);
	}
	mx = 0;
	for(int i = 1; i <= n; i++){
		for(int j = mx + 1; j <= a[i]; j++){
		    pref[j] = i;
		}
		mx = max(mx, a[i]);
	}
	mx = 0;
	for(int i = n; i > 0; i--){
		for(int j = mx + 1; j <= a[i]; j++){
			suf[j] = i;
		}
		mx = max(mx, a[i]);
	}

	for(int i = 1, len; i <= mx; i++){
		len = pref[i] - 1  + n - suf[i];
		ans[len] = i;
	}
	for(int i = 1; i <= n; i++){
		ans[i] = max(ans[i - 1], ans[i]);
	}
	scanf("%d", &q);
	for(int i = 1,k; i <= q; i++){
		scanf("%d", &k);
		printf("%d", ans[k]);
		if(i < q) printf(" ");
	}


return 0;
}
