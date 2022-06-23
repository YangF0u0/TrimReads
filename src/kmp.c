# include <stdio.h>
# include "wxj.h"

int kmp(char s[],char t[],int slen,int tlen){
    int next[tlen-1],i=0,j=0;
    Next(next,t,tlen);
    while(i<slen&&j<tlen){
        if(j==-1||s[i]==t[j]){
            i++;
            j++;
        }				
        else j=next[j];			
    }
    if(j==tlen) return (i-tlen); 
    else return -1;
}
