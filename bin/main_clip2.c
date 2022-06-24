#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "left_right.h"

int main(int argc,char **argv){
    char file[100];
    strcpy(file,argv[1]);
    char tofile[100];
    strcpy(tofile,argv[3]);
    char s[1000][1000];
    char seq[1000];
    int bp=atoi(argv[2]);
    FILE *fp=fopen(file,"r");
        if(!fp) perror("can't read\n");
    FILE *fpp=fopen(tofile,"w");
        int i=1;
        while(fgets(s[i-1],1000,fp)&&!feof(fp)){
                if(i%4==1||i%4==3)
                   fprintf(fpp,"%s",s[i-1]);
                if(i%4==2){
                   strcpy(seq,s[i-1]);
                   left_right(seq,bp);
                   fprintf(fpp,"%s",seq);
                }
                if(i%4==0){
                   strcpy(seq,s[i-1]);
                   left_right(seq,bp);
                   fprintf(fpp,"%s",seq);
                }
                i++;}
    return 0;
}

