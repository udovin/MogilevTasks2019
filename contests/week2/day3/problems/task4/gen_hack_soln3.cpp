#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;

inline int Rand() { return ((rand() & 1) << 30) ^ ((rand() & 0x7FFF) << 15) ^ (rand() & 0x7FFF); }

vector<pii> v;

int main() {
    //freopen("output.txt", "w", stdout);
    srand(424);
    cout << "100000" << endl;
    for (int i = 0; i < 100000; ++i)
        cout << (i ? " " : "") << 1;
    cout << endl;
    cout << "100000" << endl;
    int cnt = 0;
    for (int k = 1; cnt < 100000; ++k) {
        for (int i = 1; i <= k + 1 && cnt < 100000; ++i) {
            if (k >= 4)
                --i;
            ++cnt;
            v.push_back(make_pair(max(i, 1), k));
        }
    }
    for (int i = 0; i < 100000; ++i)
        swap(v[i], v[Rand() % (i + 1)]);
    for (int i = 0; i < 100000; ++i) {
        cout << v[i].first << " " << v[i].second << "\n";
    }
    return 0;
}
