# include <stdio.h>
# include <string.h>
# include "wxj.h"

int per_del(double e,int del,char s[1000],char adapt[100],int least,int *loc){

    int alen=strlen(adapt);
    int slen=strlen(s)-1;
    int i,j;
    int k=per_wrong(e,s,adapt,least,loc);
    if(k==0||k==1) return 0;
    if(k==2)
    {
        int m[del+1],n,lc[del+1];

        for(n=0;n<=del;n++){
            for(j=0;j<slen-alen;j++){
                m[n]=0;
                lc[n]=0;
                i=0;
                if(s[slen-alen-j]!=adapt[0]) continue;
                while(i<alen+n){
                    if(s[slen-alen-j+m[n]]==adapt[i])
                    m[n]++;
                    i++;
                }
                if(m[n]==alen) {
                    lc[n]=slen-alen-j;
                    break;
                }
        }
        alen--;
        }
        alen+=n;
       for(n=0;n<=del;n++)
        if(m[n]==alen-n&&m[n]>=least) {
           s[lc[n]]='\0';
	   *loc=lc[n];
            return 1;
        }

        for(n=0;n<=del;n++){
        for(j=least;j<=alen-n;j++){
            if(s[slen-j]!=adapt[0]) continue;
            m[n]=0;
            lc[n]=0;
          for(i=0;i<j;i++){
              if(s[slen-j+m[n]]==adapt[i])
              m[n]++;
          }
           if(m[n]>=least) {
               lc[n]=slen-j;
               break;
           }
        }
        for(n=0;n<=del;n++)
        if(lc[n]!=0&&m[n]>=least){
            s[lc[n]]='\0';
	    *loc=lc[n];
            return 1;
        }
        }


    }
return 2;
}
