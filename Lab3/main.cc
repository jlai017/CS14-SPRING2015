//  =============== BEGIN ASSESSMENT HEADER ================
/// Joshua Lai
/// 861163421
/// 4 May 2015
//  ================== END ASSESSMENT HEADER ===============
#include "lab3.h"

using namespace std;

int main( int argc, char* argv[] ) {
    int x = atoi(argv[1]);
    printPre(x);
    printPost(x);
    orderCoPrimePrint(x);
    
    return 0;
}