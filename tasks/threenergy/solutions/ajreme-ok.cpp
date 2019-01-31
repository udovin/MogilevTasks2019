#include <bits/stdc++.h>

using namespace std;

int get_N() {
    int N;
    cin >> N;
    return N;
}

int med3(int a, int b, int c) {
    cout << "? " << a << ' ' << b << ' ' << c << endl;
    int ans;
    cin >> ans;
    return ans;
}

int answer(int x) {
    cout << "! " << x << endl;
}

void ternary_insert(list<int>& lst, int x) {
    if (lst.size() >= 2) {
        int res = med3(lst.front(), lst.back(), x);
        if (lst.front() == res) {
            lst.push_front(x);
            return;
        }
        else if (lst.back() == res) {
            lst.push_back(x);
            return;
        }
        auto L = lst.begin();
        auto R = lst.end();
        while (distance(L, R) > 1) {
            auto ind1 = next(L, distance(L, R)/3);
            auto ind2 = next(L, 2*distance(L, R)/3);
            res = med3(*ind1, *ind2, x);
            if (res == *ind1) {
                R = ind1;
            }
            else if (res == *ind2) {
                L = ind2;
            }
            else {
                L = ind1;
                R = ind2;
            }
        }
        lst.insert(R, x);
    }
    else {
        lst.push_back(x);
    }
}

int med_find(int N) {
    list<int> lst;
    int drop = 0;
    for (int i = 1; i <= N; i++) {
        ternary_insert(lst, i); 
        if (i > N/2+1) {
            lst.pop_front();
            lst.pop_back();
            drop++;
        }
    }
    return *next(lst.begin(), N/2-drop);
}

int main() {
    answer(med_find(get_N()));
}
