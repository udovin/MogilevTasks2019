#include <bits/stdc++.h>

using namespace std;
long long n, x, k, y;
string t;
struct os
{
    vector <long long> s;
    vector <long long> sw;
};
os a[600000];
int main()

{
    //ios_base::sync_with_stdio(false);
    ifstream cin("input.txt");
    ofstream cout("output.txt");
    cin >> n;
    k = 2;
    for (int i = 0; i < n; i++)
        {
            cin >> t;
            if (t == "info")
                {
                    cin >> x >> y;
                    a[x].s.push_back(y);
                    vector < long long > v;
                    a[x].sw = v;
                    if (x - k == 0)
                        k++;
                }
            if (t == "rollback")
                {
                    cin >> x;
                    if (a[x].s.size() != 0)
                        {
                            a[x].sw.push_back(a[x].s[a[x].s.size() - 1]);
                            a[x].s.pop_back();
                        }
                }
            if (t == "undo")
                {
                    cin >> x;
                    if (a[x].sw.size() != 0)
                        {
                            a[x].s.push_back(a[x].sw[a[x].sw.size() - 1]);
                            a[x].sw.pop_back();
                        }
                }
            if (t == "clone")
                {
                    cin >> x;
                    a[k] = a[x];
                    k++;
                }
            if (t == "check")
                {
                    cin >> x;
                    if (a[x].s.size() == 0)
                        cout << "null" << endl;
                    else
                        cout << a[x].s[a[x].s.size() - 1] << endl;
                }
        }
    return 0;
}