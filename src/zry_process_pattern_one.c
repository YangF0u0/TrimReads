/*zry_process_pattern_one.c
Author: Ruoyin Zhou
Date:2022/5/17
Function:process the fastq file, record the screened sequences and record the clipped bases
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "zry_process_pattern_one.h"
#include "zry_cut_and_store.h"
void process_pattern_one(FILE *file,int stop,int threshold,int phred_value,char *result_file,char *error_file){
    int count=0,num_name=0,num_seq=0,num_descri=0,num_quality=0,total=1;
    char name[200],seq[200],descri[200],quality[200];
    FILE *fresult=NULL;
    fresult=fopen(result_file,"a+");
    FILE *ferror=NULL;
    ferror=fopen(error_file,"a+");
    rewind(file);

    char temp[200];
    char *str;
    while((str=fgets(temp,200,file))!=NULL){
        count++;
        int flag=count%4;
        if (flag==1) {
            strcpy(name,str);
            num_name++;
        }
        if (flag==2) {
            strcpy(seq,str);
            num_seq++;
        }

        if (flag==3) {
            strcpy(descri,str);
            num_descri++;
        }
        if (flag==0) {
            strcpy(quality,str);
            num_quality++;

        }
        if (num_seq==total && num_quality==total &&  num_name==total){
            cut_and_store(name,seq,descri,quality,num_seq,phred_value,threshold,stop,fresult,ferror);
            total++;
        }
        strcpy(str,"");
    }
    fclose(fresult);
    fclose(ferror);

}
