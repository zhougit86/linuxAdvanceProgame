#include <iostream>
#include <string>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <signal.h>
#include <stdio.h>
#include <errno.h>
#include <unistd.h>
// #include <sys/conf.h>
#include <stropts.h>
#include <stdlib.h>

using namespace std;
int main(int argc,char *argv[]){
    int fd,i,nmods;
    struct str_list list;

    fd = open(argv[i],O_RDONLY);
    nmods = ioctl(fd, I_LIST, (void *)0);
    cout << "# of modules:" << nmods << endl;

    list.sl_modlist = (str_mlist*)calloc(nmods,sizeof(struct str_mlist));
    list.sl_nmods = nmods;

    for (i = 1; i <= nmods ; i++){
        cout << list.sl_modlist++ << endl;
    }

}