#include "testlib.h"
#include <sstream>
#include <cassert>

using namespace std;

inline double cube(double a) {
    return a*a*a;
}

int main(int argc, char **argv) {
    registerTestlibCmd(argc, argv);
    
    inf.readInt();
    int n = inf.readInt(), m = inf.readInt(), l = inf.readInt(), h = inf.readInt();
    vector<string> v(n);
    for (int i = 0; i < n; ++i) {
        v[i] = inf.readToken();
    }
    
    auto readAns = [&](InStream &is) {
        int k = is.readInt(0, n*m, "k");
        vector< vector<char> > used(n, vector<char>(m, false));
        int ans = 0;
        for (int i = 0; i < k; ++i) {
            int x1 = is.readInt(1, n, "x_1," + vtos(i+1)) - 1;
            int y1 = is.readInt(1, m, "y_1," + vtos(i+1)) - 1;
            int x2 = is.readInt(x1, n, "x_2," + vtos(i+1)) - 1;
            int y2 = is.readInt(y1, m, "y_2," + vtos(i+1)) - 1;
            int sq = (x2-x1+1) * (y2-y1+1);
            if (sq > h) {
                is.quitf(_wa, "mine %d has square %d, which is against the law!", i+1, sq);
            }
            int cuprum = 0, ferrum = 0;
            for (int j = x1; j <= x2; ++j) {
                for (int k = y1; k <= y2; ++k) {
                    if (used[j][k]) {
                        is.quitf(_wa, "cell (%d, %d) is used by two or more mines", j+1, k+1);
                    }
                    used[j][k] = true;
                    if (v[j][k] == 'C') {
                        ++cuprum;
                    } else if (v[j][k] == 'F') {
                        ++ferrum;
                    } else {
                        assert(false);
                    }
                }
            }
            if (cuprum < l || ferrum < l) {
                is.quitf(_wa, "mine %d doesn't have enough resources (C = %d, F = %d)", i+1, cuprum, ferrum);
            }
            ans += sq;
        }
        return ans;
    };
    
    int pans = readAns(ouf);
    int jans = readAns(ans);
    
    quitp(10.0 * cube(1.0 * jans / (n * m)), "found = %d, possible best = %d", pans, n*m);
    
    return 0;
}
