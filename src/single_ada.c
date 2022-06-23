# include <stdio.h>
# include <string.h>
# include "wxj.h"

int single_ada(char s[1000], char adapt[100],int least,int *loc){		
   
    int i,j;
    int slen=strlen(s)-1;
    int alen=strlen(adapt);
    int pos=kmp(s,adapt,slen,alen);
    if(pos<=slen-alen&&pos!=-1) {
	s[pos]='\0';
	*loc=pos;
	return 1;}
    if(pos==-1){
       for(j=alen;j>=least;j--){
           int flag=0;
          for(i=0;i<j;i++){
              if(s[slen-j+i]!=adapt[i])
              {flag=1;break;}
          }
           if(flag==0) {
		s[slen-j]='\0';
		*loc=slen-j;
		return 1;}
       }
    }
    return 0;
}
