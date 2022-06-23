# include <stdio.h>
# include <string.h>
# include "wxj.h"

int single_pri(char s[1000], char primer[100],int least,int *loc){
   
    int i,j;
    int slen=strlen(s)-1;
    int alen=strlen(primer);
    int pos=kmp(s,primer,slen,alen);
  
    if(pos!=-1) {
	cuts(s,alen+pos);
	*loc=alen+pos;
	return 1;}
    if(pos==-1){
       for(j=least;j<=alen;j++){
           int flag=0;
          for(i=0;i<j;i++){
              if(s[i]!=primer[alen-j+i])
              {flag=1;break;}
          }
           if(flag==0) {
               cuts(s,j);
	       *loc=j;
               return 1;
       }
       }
    }
    return 0;
   
}

