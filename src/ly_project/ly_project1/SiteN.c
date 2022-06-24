#include <stdlib.h>
#include <stdio.h>
#include "SiteN.h"
void SiteN(char *seq,int *AddrN){
    int i=0,k=0;
    while(seq[i]!='\0'){
        if(seq[i]=='N'){
            AddrN[k]=i;
            k++;
        }
        i++;
    }              
   return;
}
