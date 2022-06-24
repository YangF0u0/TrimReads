#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "rando.h"
#include "tail.h"
#include "head.h"
#include "Pattern_select.h"
void Pattern_select(char *seq,int AddrN[],int NumN,int num){
    printf("which pattern do you want to use to remove N\n");
    printf("random:0 from_head:1 from_tail:2\n");
    int sign;
    scanf("%d",&sign);
    if(sign==0)
        rando(seq,AddrN,NumN,num);
    if(sign==1)
        head(seq,AddrN,NumN,num);
    if(sign==2){
        int len=strlen(seq);
        tail(seq,len,AddrN,NumN,num);
    return;
}}

