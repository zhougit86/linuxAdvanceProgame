#include <sys/types.h>
#include <dirent.h>
#include <iostream>

using namespace std;

int main(int argc, char *argv[]){
    DIR *dp;
    dirent *dirp;

    if ((dp = opendir(argv[1])) == NULL){
        cout << "can not open" <<endl;
    }
    while ((dirp = readdir(dp))!=NULL){
        cout << dirp->d_name;
    }
    closedir(dp);
    return 0;
}