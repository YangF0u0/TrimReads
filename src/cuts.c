# include <stdio.h>
# include <string.h>

void cuts(char s[1000],int n){
    int i;
    int len=strlen(s);
    for(i=0;i<len-n;i++) s[i]=s[n+i];
    s[i]='\0';

}
