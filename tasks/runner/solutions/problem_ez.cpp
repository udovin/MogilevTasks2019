#include<iostream>
#include<cstdio>
#include<cmath>
#include<ctime>
#include<algorithm>
#include<vector> 
#include<cstring>
#include<string>
#include<map>
#define mp make_pair
#define scn second
#define frs first
#define pb push_back

using namespace std;
typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int> pi;

long long dst[500][500];
int x[500], y[500];
int n;

void make_dst() {
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j)
			dst[i][j] = (x[i] - x[j]) * (x[i] - x[j]) + (y[i] - y[j]) * (y[i] - y[j]);	
}
int used[500];

long long dfs(int v) {
	used[v] = 1;
	int to = -1;
	for (int i = 0; i < n; ++i) {
		if (used[i])
			continue;
		if (to == -1 || dst[v][to] > dst[v][i])
			to = i;
	}
	if (to == -1)
		return 0;
	return dfs(to) + dst[v][to];
}

int main(){
	freopen("input.txt", "r", stdin); 
	freopen("output.txt", "w", stdout); 
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) 
		scanf("%d%d", &x[i], &y[i]);
	make_dst();
	ll ans = 1000000000000000000LL;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j)
			used[j] = 0;
		ll tmp = dfs(i);
		ans = min(ans, tmp);		
	}
	printf("%I64d", ans);
			
	return 0;
}




