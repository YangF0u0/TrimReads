#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "rando.h"
#include "delete_space.h"
void rando(char *seq,int AddrN[],int NumN,int num){ 
    srand((unsigned)time(NULL));
    int a,i,j,k=1;
    int flag=0;
    int rec[NumN-num];
    while(1){
        a=rand()%NumN; 
        rec[k-1]=a;
        while(flag==1){
        for(j=0;j<k-1;j++){
            if(a==rec[j]){
                flag=1;
                a=rand()%NumN;
                break;
            }
            else
                flag=0;
        }
        }
        flag=1;
        i=AddrN[a];
        seq[i]=' ';
        k++;
        if(k>NumN-num)
        break;
    }
    delete_space(seq);
    return;
}

