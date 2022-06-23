# include <stdio.h>

void Next(int next[],char s[],int slen){
    int j=0,k=-1;
    next[0]=-1;					
    while(j<slen-1){
        if(k==-1||s[j]==s[k]){		
            k++;
            j++;
            next[j]=k;
        }					
        else k=next[k];				
    }
}
