#include <iostream>
#include "GenStack.h"
#include "RuntimeException.h"
#include "Checker.h"
using namespace std;

int main(int argc, char** argv){

cout<<argv[1]<<endl;
Checker check;
cout<<"checkermade"<<endl;
check.fileCheck(argv[1]);

}
