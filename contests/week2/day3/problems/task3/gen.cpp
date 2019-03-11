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
#include "testlib.h"
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

int a[N];

int main(int argc, char* argv[]) {

	registerGen(argc, argv, 1);
	int n = atoi(argv[1]), q = atoi(argv[2]), m = atoi(argv[3]), mn =  atoi(argv[4]), mx = atoi(argv[5]);
	printf("%d\n",n);
	for(int i = 1; i <= n; i++){
		int x = rnd.next(mn,mx);
		printf("%d%c", x, i == n ? '\n' : ' ');
	}
	printf("%d\n", q);
	for(int i = 0; i < q; i++){
		a[i] = i;
	}
	shuffle(a,a + q);
	for(int i = 0; i < q; i++){
		printf("%d%c", a[i] , i == q - 1 ? '\n' : ' ');
	}
	return 0;
}
