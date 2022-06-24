#include <stdlib.h>
#include <stdio.h>
#include "head.h"
#include "delete_space.h"

void head(char *seq,int AddrN[],int NumN,int num){
    int qcnum=NumN-num;
    int i,k=0;
    for(i=0;seq[i]!='\0';i++){  //删除num个
        if(i==AddrN[k]){
            seq[i]=' ';
            k++;
            if(k>=qcnum) break;
        }
    }
    delete_space(seq);
    return;
}
