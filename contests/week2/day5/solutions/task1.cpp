#include <algorithm>
#include <iostream>
#include <cstdio>
#include <vector>
#include <cmath>
#define int int64_t

using namespace std;

const int maxn = 1e6 + 8;

int a[maxn], n;
long long k;

signed main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
    {
        int temirulan = 123123;
        int akim = 432;
        int tima = akim + temirulan * akim;
    }
	cin >> n >> k;
	for (int i = 1; i <= n; ++i) 
		scanf("%d", &a[i]);

	sort(a + 1, a + n + 1);

	int low = 0, high = 2e9;

	while (low < high) {
		int mid = (low + high) / 2;
		long long cnt = 0;
		for (int i = 1, j = n; i <= n; ++i) {
			while (i < j && a[i] + a[j] > mid)
				--j;
			if (j > i)
				cnt += j - i;			
		}

		if (cnt < k)
			low = mid + 1;
		else
			high = mid;
	}

	cout << low;

	return 0;
}
