#include "testlib.h"
#include <string>
#include <set>
#include <cmath>
#include <cassert>

#define mp make_pair

using namespace std;
const int N = int(5e5) + 10;

int main (int argc, char* argv[]) {

    registerValidation(argc, argv);
    string g = validator.group();
    int n = inf.readInt(1,1000000, "N");
    inf.readEoln();
    for(int i = 1,x; i <= n; i++){
    	x = inf.readInt(1,1000000, "A_i");
    	if(i < n){
    		inf.readSpace();
    	}	
    	else inf.readEoln();
    }
    int q = inf.readInt(1,1000000, "Q");
    int mx = 0;
    inf.readEoln();
    for(int i = 1,x; i <= q; i++){
    	x = inf.readInt(0, n - 1, "K_i");
    	if(i < q){
    		inf.readSpace();
    	}	
    	else inf.readEoln();
    	mx = max(x, mx);
    }
    inf.readEof();
    if(g == "A"){
    	ensuref(n >= 1 && n <= 3, "Group A constraint N error");
    	ensuref(q >= 1 && q <= 1,"Group A constraint Q error");
    	ensuref(mx <= 0, "Group A costraint K_i error");
    }
    if(g == "B"){
    	ensuref(n >= 1 && n <= 100, "Group B constraint N error");
    	ensuref(q >= 1 && q <= 1,"Group B constraint Q error");
    	ensuref(mx <= 0, "Group B costraint K_i error");
    }
    if(g == "C"){
    	ensuref(n >= 1 && n <= 100000, "Group C constraint N error");
    	ensuref(q >= 1 && q <= 2,"Group C constraint Q error");
    	ensuref(mx <= 1, "Group C costraint K_i error");
    }
    if(g == "D"){
    	ensuref(n >= 1 && n <= 100000, "Group D constraint N error");
    	ensuref(q >= 1 && q <= 100000,"Group D constraint Q error");
    }
    if(g == "E"){
    	ensuref(n >= 1 && n <= 1000000, "Group E constraint N error");
    	ensuref(q >= 1 && q <= 1000000,"Group E constraint Q error");
    }
}
