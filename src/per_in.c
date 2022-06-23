# include <stdio.h>
# include <string.h>
# include "wxj.h"

int per_in(double e,int in,char s[1000],char adapt[100],int least,int *loc){

    int alen=strlen(adapt);
    int slen=strlen(s)-1;
    int i,j;
    int k=per_wrong(e,s,adapt,least,loc);
    if(k==0||k==1) return 0;
    if(k==2)
    {
        int m[in+1],n,lc[in+1];		

        for(n=0;n<=in;n++){
            for(j=0;j<slen-alen;j++){
                m[n]=0;
                lc[n]=0;
                i=0;
                if(s[slen-alen-j]!=adapt[0]) continue;
                while(i<alen){
                    if(s[slen-alen-j+i]==adapt[m[n]])
                    m[n]++;
                    i++;
                }
                if(m[n]==alen-n) {
                    lc[n]=slen-alen-j;
                    break;
                }
            }
        alen++;
        }
        alen-=n;
       for(n=0;n<=in;n++)
        if(m[n]==alen) {
           s[lc[n]]='\0';
	   *loc=lc[n];
            return 1;
        }

        for(n=0;n<=in;n++){
           for(j=least+n;j<=alen+n;j++){
               if(s[slen-j]!=adapt[0]) continue;
               m[n]=0;
               lc[n]=0;
             for(i=0;i<j;i++){
                 if(s[slen-j+i]==adapt[m[n]])
                 m[n]++;
             }
              if(m[n]>=least) {
                  lc[n]=slen-j;
                  break;
              }
           }
		
         for(n=0;n<=in;n++)
         if(lc[n]!=0){
            s[lc[n]]='\0';
	    *loc=lc[n];
            return 1;
          }
      }
 
    }
 return 2;
}

