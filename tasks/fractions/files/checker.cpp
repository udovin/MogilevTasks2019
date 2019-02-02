#include <cctype>
#include <string>
#include "testlib.h"


bool read_solution(int n, InStream &in) {
    std::string result = lowerCase(in.readToken("[Yy][Ee][Ss]|[Nn][Oo]"));
    if (result == "no") {
        return false;
    }
    
    long long sum = 0;
    int cnt = in.readInt(1, 100000, "cnt");

    for (int i = 0; i < cnt; ++i) {
        int num = in.readInt(1, n, "numer");
        int den = in.readInt(1, n - 1, "denom");
        if (num >= den) {
            in.quitf(_wa, "Numer should be less than denom (%d/%d)", num, den);
        }
        if (n % den != 0) {
            in.quitf(_wa, "Denom should be divisor of n (denom=%d, n=%d)", den, n);
        }
        int q = n / den;
        sum += num * q;
        if (sum > n - 1) {
            in.quitf(_wa, "Sum of fractions is too large");
        }
    }
    
    if (sum != n - 1) {
        in.quitf(_wa, "Sum of fractions should be n - 1 (n=%d)", n);
    }
    return true;
}


int main(int argc, char *argv[]) {
    registerTestlibCmd(argc, argv);

    int n = inf.readInt();
    
    bool jury = read_solution(n, ans);
    bool part = read_solution(n, ouf);

    if (jury != part) {
        if (jury) {
            quitf(_wa, "Participant can't find partition but jury have found (n = %d)", n);
        } else {
            quitf(_fail, "Jury can't find partition but participant has found (n = %d)", n);
        }
    }
    quitf(_ok, "n = %d", n);
}
