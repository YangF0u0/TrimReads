#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "Pattern_select.h"
#include "CountN.h"
#include "SiteN.h"


int main(int argc,char** argv){
    //char seq[100]="CTACATTTGATACCTAAACATTCTAATTTCCTTCCTAAAGTCTGAAAGATGAGGAAANNANGAATCNNCNNN";                   //DNA序列
    //int num=1; //允许保留的最大N
    char seq[100]; //DNA序列
    strcpy(seq,argv[1]);
    int num=atoi(argv[2]); //允许保留的最大N
    int *AddrN;
    int NumN=CountN(seq,num);
    if(NumN!=0){
    AddrN=(int*)malloc(sizeof(int)*NumN);
    SiteN(seq,AddrN);
    printf("the origin seq:\n%s\n",seq);
    Pattern_select(seq,AddrN,NumN,num);
    printf("%s\n",seq);}
    return 0;
}
