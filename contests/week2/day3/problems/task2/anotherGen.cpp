#include "testlib.h"
using namespace std;

int main(int argc, char* argv[])
{
    //freopen("text.c", "r", stdin);
    ios_base::sync_with_stdio(false);
    registerGen(argc, argv, 1);

    int n = rnd.next(200000, 500000);
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
