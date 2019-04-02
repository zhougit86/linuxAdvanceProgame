#include <iostream>
#include "add.h"
#include "sub.h"

using namespace std;

int main(void){
    int a = 1, b= 2;

    cout << add(a,b) << endl;
    cout << sub(a,b) << endl;

    return 0;
}