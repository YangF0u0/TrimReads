/*by Ying Liang
    for non-ATGC cutting in rate*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "Pattern_select.h"
#include "CountN.h"
#include "SiteN.h"

int main(int argc,char** argv){
    char seq[100];
	strcoy(seq,argv[1]); //DNA序列
    double rate=atof(argv[2]); //允许保留的最大N的比例
    int len=strlen(seq);
    int num=len*rate;//允许保留的最大N的数目
    int *AddrN;
    int NumN=CountN(seq,num);
    if(NumN!=0){
    AddrN=(int*)malloc(sizeof(int)*NumN);
    SiteN(seq,AddrN);
    printf("the origin seq: %s\n",seq);
    Pattern_select(seq,AddrN,NumN,num);
    printf("%s\n",seq);}
    return 0;
}
