#include <stdlib.h>
#include <stdio.h>
#include "CountN.h"
int CountN(char *seq,int num){
    int i=0;
    int NumN=0;
    while(seq[i]!='\0'){
        if(seq[i]=='N'){
            NumN++;
        }
        i++;
    }              //获取N总个数
    if(NumN<=num){
        printf("the oirginal seq meets requirement\n");
        return 0;
    }               //如果实际N的个数比输入的允许最大值小（无需处理
   return NumN;
}
