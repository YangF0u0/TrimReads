# include <stdio.h>
# include <string.h>
# include "wxj.h"

int per_wrong(double e, char s[1000],char adapt[100],int least,int *loc){
    int n=e*strlen(adapt);  
    int alen=strlen(adapt);
    int slen=strlen(s)-1;
    int i,j;
    int k=single_ada(s,adapt,least,loc);
   if(k==1) return 0;
   if(k==0)
    {
        int m;
        for(j=0;j<slen-alen;j++){
            m=0;
            for(i=0;i<alen;i++){
                if(s[slen-alen-j+i]==adapt[i]) m++; 
    		}
            if(m>=alen-n) {
                s[slen-alen-j]='\0';
     		*loc=slen-alen-j;
                return 1;
            }
        }

        for(j=least;j<=alen;j++){
            m=0;
          for(i=0;i<j;i++){
              if(s[slen-j+i]!=adapt[i])
              m++;
          }
           if(m<=n) {
		s[slen-j]='\0';
		*loc=slen-j;
		return 1;}
       }
	return 2;
    }
    


}

