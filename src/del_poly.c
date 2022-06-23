# include <stdio.h>
# include <string.h>

int del_poly(char s[1000],int *loc){
    int len=strlen(s)-1;
    int i;
    for(i=len-2;i>=0;i--){
        if(s[i]!='P') break;
    }
    s[i+1]='\0';
   if(loc!=0) *loc=i+1;
if(loc==0) return 0;
if(loc!=0) return 1;
}
