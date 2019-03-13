#include "testlib.h"
#include "parmpars.hpp"
using namespace std;

int main(int argc, char* argv[])
{
    initGenerator(argc, argv, 1);
    //freopen("text.c", "r", stdin);
    ios_base::sync_with_stdio(false);

    DECLARE_GEN(GenRange<int>, n);

    cout << n << '\n';
    for(int i = 0; i < n; i++)
    {
        switch(i % 3)
        {
        case 0:
            cout << "clone " << i / 3 + 1 << '\n';
            break;
        case 1:
            cout << "info " << i / 3 + 1 << " " << i / 3 + 1 << '\n';
            break;
        case 2:
            cout << "check " << i / 3 + 1 << '\n';
            break;
        }
    }
    return 0;
}
