#include <stdlib.h>
#include <stdio.h>
#include "tail.h"
#include "delete_space.h"
void tail(char *seq,int len,int AddrN[],int NumN,int num){
    int i,k=NumN-1;
    for(i=len-1;i>=0;i--){  //删除num个
        if(i==AddrN[k]){
            seq[i]=' ';
            k--;
            if(k<num) break;
        }
    }
    delete_space(seq);
    return;
}
