/*by Ying Liang
    for flitering short seqs*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
int main(int argc,char** argv){
    char file[100];
    strcpy(file,argv[1]);
    char tofile[100];
    strcpy(tofile,argv[3]);
    char s[1000][1000];
    char seq0[1000],seq1[1000],seq2[1000],seq3[1000];
    int minlen=atoi(argv[2]);
    FILE *fp=fopen(file,"r");
        if(!fp) perror("can't read\n");
    FILE *fpp=fopen(tofile,"w");
    int i=1;
     while(fgets(s[i-1],1000,fp)&&!feof(fp)){
                //if(i%4==1||i%4==3)
                  // fprintf(fpp,"%s",s[i-1]);
                if(i%4==2){
                    strcpy(seq1,s[i-1]);
                    if(strlen(seq1)<minlen){
                    strcpy(seq0,s[i-2]);
                    seq0[0]='\0';
                    fprintf(fpp,"%s",seq0);
                    seq1[0]='\0';
                    fprintf(fpp,"%s",seq1);}
                   else {
			fprintf(fpp,"%s",s[i-2]);
			fprintf(fpp,"%s",seq1);}
			
                }
		if(i%4==0){
                    strcpy(seq3,s[i-1]);
                    if(strlen(seq1)<minlen){
                   strcpy(seq2,s[i-2]);
                    seq2[0]='\0';
                    fprintf(fpp,"%s",seq2);
                    seq3[0]='\0';
                    fprintf(fpp,"%s",seq3);}
		    else {
			fprintf(fpp,"%s",s[i-2]);
			fprintf(fpp,"%s",seq3);}}
                i++;}
    return 0;
}
