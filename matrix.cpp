#include <iostream>
#include <string>
#include <fcntl.h>
#include <sys/types.h>
#include <signal.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

using namespace std;

typedef struct matrix{
    int rows;
    int cols;
    int** vals;
} t_matrix;

void initMatrix(t_matrix* m){
    m->vals = (int**)malloc(m->rows*sizeof(int*));
    for(int i = 0; i<m->rows ; i++){
        m->vals[i] = (int*)malloc(m->cols*sizeof(int));
    }
}

void freeMatrix(t_matrix* m){
    for(int i = 0; i<m->rows ; i++){
       free(m->vals[i]);
    }
    free(m->vals);
}

void printMatrix(t_matrix m){
    for (int i =0; i < m.rows ; i++){
        for(int j = 0; j < m.cols ; j++){
            printf("%4d\t",m.vals[i][j]);
        }
        printf("\n");
    }
}

int getData(){
    int input;
    scanf("%d",&input);
    return input;
}

main(){
    t_matrix m;
    // m.rows = 3;
    // m.cols = 4;s
    cout << "please input the rows and cols" <<endl;
    scanf("%d,%d",&m.rows,&m.cols);
    initMatrix(&m);

    for (int i=0;i<m.rows;i++){
        for(int j=0;j<m.cols;j++){
            cout<<"input"<<i<<j<<endl;
            // printf("please input the %dth row, %dth cols\n",i,j);
            m.vals[i][j] = getData();
        }
    }
    // int input[][4] = {{1,2,3,4},{4,3,2,1},{5,6,8,9}};
    // mempcpy(m.vals[0],input[0],4*sizeof(int));
    // mempcpy(m.vals[1],input[1],4*sizeof(int));
    // mempcpy(m.vals[2],input[2],4*sizeof(int));
    printMatrix(m);

    return 0;
}