#include <iostream>

using namespace std;

struct node {
    int val;
    node* l;
    node* r;

    node(int l, int r) : val(r - l + 1), l(nullptr), r(nullptr) {

    }
};

int valL(node *p, int l, int r) {
    if (p->l == nullptr) {
        return (l+r)/2 - l + 1;
    }
    else {
        return p->l->val;
    }
}

int valR(node *p, int l, int r) {
    if (p->r == nullptr) {
        return r - (l+r)/2;
    }
    else {
        return p->r->val;
    }
}

void check(node*& p, int l, int r) {
    if (p == nullptr) {
        p = new node(l, r);
    }
}

void del(node*& p, int l, int r, int k) {
    check(p, l, r);
    if (l == r) {
        p->val = 0;
        return;
    }
    else if (k <= valL(p, l, r)) {
        del(p->l, l, (l+r)/2, k);
    }
    else {
        del(p->r, (l+r)/2+1, r, k - valL(p, l, r));
    }
    p->val = valL(p, l, r) + valR(p, l, r);
}

int que(node*& p, int l, int r, int k) {
    check(p, l, r);
    if (l == r) {
        return l;
    }
    else if (k <= valL(p, l, r)) {
        que(p->l, l, (l+r)/2, k);
    }
    else {
        que(p->r, (l+r)/2+1, r, k - valL(p, l, r));
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    node* p = new node(1, n);
    while (m--) {
        char type;
        int k;
        cin >> type >> k;
        if (type == 'D') {
            del(p, 1, n, k);
        }
        else {
            cout << que(p, 1, n, k) << '\n';
        }
    }
}
