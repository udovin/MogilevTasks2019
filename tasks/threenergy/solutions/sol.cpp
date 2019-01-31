#include <bits/stdc++.h>


using namespace std;

ifstream fin("input.txt");
ofstream fout("output.txt");
ofstream ferr("error.txt");
int N, q = 0, arr[2000];

int GetN() {
    fin >> N;
    for (int i = 1; i <= N; i++) {
        fin >> arr[i];
    }
    return N;
}

bool corr(int x) {
    return 1 <= x && x <= N;
}

int Med3(int a, int b, int c) {
    if (++q > 10000) {
        fout << "a lot of query's!\n";
        exit(0);
    }
    if (corr(a) && corr(b) && corr(c)) {
        vector<pair<int, int>> p = { {arr[a],a}, {arr[b],b}, {arr[c],c} };
        sort(p.begin(), p.end());
        return p[1].second;
    }
    fout << "is not in boarders!\n";
    exit(0);
}

int Answer(int x) {
    if (arr[x] == N/2+1) {
        fout << "accepted\n";
    }
    else {
        fout << "wrong answer: " << x << endl;
    }
    //fout << q << endl;
    exit(0);
}


void ternary_insert(list<int>& lst, int x) {
    if (lst.size() >= 2) {
        int res = Med3(lst.front(), lst.back(), x);
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
            res = Med3(*ind1, *ind2, x);
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
    Answer(med_find(GetN()));
}
