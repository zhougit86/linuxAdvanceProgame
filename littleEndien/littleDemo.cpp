#include <stdio.h>
#include <iostream>

typedef union{
    unsigned short int value;
    unsigned char byte[2];
} to;

using namespace std;

int main(int argc, char* argv[]){
    to typeOrder;
    typeOrder.value = 0xabcd;
    
    if (typeOrder.byte[0] == 0xcd)
        cout  << "haha" << endl;

    return 0;

}