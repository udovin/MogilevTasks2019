#include "testlib.h"


int main(int argc, char* argv[]){
    registerValidation(argc, argv);
    inf.readInt(2, 1000000000, "n");
    inf.readEoln();
    inf.readEof();
}
