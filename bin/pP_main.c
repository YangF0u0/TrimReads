# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include "wxj.h"

int main(int argc, char **argv){
	char s[1000];
	char file[100];
	strcpy(file,argv[1]);
	char primer[100];
	strcpy(primer,argv[2]);
	int least=atoi(argv[3]);
	FILE *fp=fopen(file,"r");
        if(!fp) perror("can't read\n");
        int i=1,k;
        int loc;
        while(fgets(s,1000,fp)&&!feof(fp)){
                if(i%4==1||i%4==3)
                   printf("%s",s);
                if(i%4==2){
		   loc=0;
                   k=single_pri(s,primer,least,&loc);
                  if(k==0) printf("%s",s);
		  else printf("%s\n",s);
                }
                if(i%4==0){
                   cuts(s,loc);
                   printf("%s",s);
                }
                i++;
        }
return 0;
}
