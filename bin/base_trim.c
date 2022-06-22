/* base_trim.c
Function: cut the bases below standard base by base
Author:Ruoyin Zhou
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "zry_base_trim.h"
/* argv[1] is the path of fastq file*/


int main(int argc, char **argv)
{

    int i,flag=0;
    for (i=1;i<argc;i++){
    if(strcmp(argv[i],"--base-threshold")==0)
        flag=1;
    }
    if(!flag) return 0;  //Judge if it is --base-thereshold pattern.If not,then exit the program.


    FILE *ffastq=NULL;
    ffastq=fopen(argv[1],"r");
    if_files_opened_correctly(ffastq);//judge if the fastq file is correctly opened

    int phred;
    phred=judge_phred(ffastq);

    int flag_outcome=0,flag_error=0,flag_Q=0,flag_s=0;
    char result_file[100],error_file[100];
    int threshold;
    int stop_len;
    int len_argv_Q,len_argv_s;
    char stop[2]={},Q[2]={};
    for (i=2;i<argc;i++){        //Matches the parameter to the input value, if the match is successful, the value is assigned, otherwise the default value is used
        if(strstr(argv[i],"fastq")!=0){
             strcpy(result_file,argv[i]);
             flag_outcome=1;
        }
        if(strstr(argv[i],"txt")!=0){
             strcpy(error_file,argv[i]);
             flag_error=1;
        }

        if(strstr(argv[i],"-Q")!=0){
             strcpy(Q,argv[i]+2);
             len_argv_Q=strlen(Q);
             flag_Q=1;
             if (len_argv_Q!=0)   threshold=atoi(Q);
                else threshold=20;
        }

        if(strcmp(argv[i],"+s")==0){
            flag_s=1;
            threshold=20;
        }

        if(strstr(argv[i],"-s")!=0){
             strcpy(stop,argv[i]+2);
             len_argv_s=strlen(stop);
             flag_s=1;
             if (len_argv_s!=0)   stop_len=atoi(stop);
                else stop_len=20;
        }
    }

    if(!flag_outcome)   strcpy(result_file,"outcome.fastq");
    if(!flag_error)   strcpy(error_file,"error.txt");
    if(!flag_Q)   threshold=20;
    if(!flag_s)  stop_len=200;

    clear_files(result_file);
    clear_files(error_file);


    process_pattern_one(ffastq,stop_len,threshold,phred,result_file,error_file);
    fclose(ffastq);
    return 0;
}
