#include <iostream>
#include <string.h>

using namespace std;

int main(int argc,char* argv[]){
    char myChar[5];
    memset(myChar,'c',5);
    
    myChar[4] = '\0';

    cout << myChar << endl;

    return 0;
}