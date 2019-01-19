#include <bits/stdc++.h>

using namespace std;

priority_queue<int, vector<int>, greater<int>> q;
int n, b[1000010], cnt = 0, ptr;
pii a[1000010];

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i].first);
        a[i].second = i;
    }
    sort(a, a + n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &b[i]);
    }
    int ptr = n-1;
    int cur_time = a[ptr].first;
    while (cnt < n) {
        if (!q.empty() && q.top() > cur_time) {
            printf("-1\n");
            return 0;
        }
        else if (a[ptr].first == cur_time) {
            q.push(b[a[ptr].second]);
            ptr--;
        }
        else {
            cnt++;
            q.pop();
        }
        cur_time--;
    }
    printf("%d\n", cur_time+1);
}
