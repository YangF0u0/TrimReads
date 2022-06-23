# include <stdio.h>
# include <string.h>
# include "wxj.h"

int main(int argc,char **argv){
	double e=atof(argv[1]);
	int in=atoi(argv[2]);	
 	char s[1000];
        char adapt[100],file[100];
	strcpy(adapt,argv[3]);
	strcpy(file,argv[4]);
        int least=atoi(argv[5]);
        FILE *fp=fopen(file,"r");
        if(!fp) perror("can't read\n");
        int i=1,k;
        int loc;
        while(fgets(s,1000,fp)&&!feof(fp)){
                if(i%4==1||i%4==3)
                   printf("%s",s);
                if(i%4==2){
		   loc=0;
                   k=per_in(e,in,s,adapt,least,&loc);
		   if(k==2) printf("%s",s);
                   else printf("%s\n",s);
                }
                if(i%4==0){
		   if(loc==0) loc=strlen(s);
                   s[loc]='\0';
                   printf("%s",s);
                }
                i++;
        }

return 0;
}

