/*zry_cut_and_store.c
 * Author: Ruoyin Zhou
 * Date:2022/5/17
 * Function:cut the bases below standard and store them into arrays
 * */



#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "zry_cut_and_store.h"
#include "zry_if_cut.h"
#include "zry_if_files_opened_correctly.h"
#include "zry_get_reverse.h"
#include "zry_write_fastq.h"
void cut_and_store(char name[],char seq[],char descri[],char quality[],int num,int phred_value,int threshold,int stop,FILE *fres,FILE *ferr){
    int len1,len2,length;
    len1=strlen(seq);
    len2=strlen(quality);

    if (len1!=len2) {
        printf("The data in FASTQ file isn't corret.Please check the fastq file.\n");
        exit (0);
    }
    else length=len1;

    int i,result,num_cut=0,num_base=0;
    int continue_base=0;
    int outcome[200]={};
    char base[200]={}; //store bases saved in base[1000]
    char qual[200]={};
    for (i=0;i<length;++i){
        result=if_cut(quality[i],phred_value,threshold);
        if (result==1) {
            base[num_base]=seq[i];
            qual[num_base]=quality[i];
            num_base++;
            continue_base++;
        }
            else if(continue_base>=stop) {
                continue_base=0;
                base[num_base]=seq[i];  
                qual[num_base]=quality[i];
                num_base++;  
            }
                else {
                    outcome[num_cut++]=i+1;
                    continue_base=0;
                }
    }          
                                           //Cut from left to right
    if(stop<100){
        strcpy(seq,"");
        strcpy(quality,"");
        continue_base=0;
        get_reverse(base,seq);
        get_reverse(qual,quality);

        length=strlen(base);
        for (i=0;i<length;++i){
            result=if_cut(quality[i],phred_value,threshold);
            if (result==1) {
                base[num_base]=seq[i];
                qual[num_base]=quality[i];
                num_base++;
                continue_base++;
            }
                else if(continue_base>=stop) {
                    continue_base=0;
                }
                    else {
                        outcome[num_cut++]=i+1;
                        continue_base=0;
                    }
            }                                                 //Cut from right to left

        char newbase[100]={};
        char newqual[100]={};
        get_reverse(seq,newbase);
        get_reverse(quality,newqual);
        write_fastq(name,newbase,descri,newqual,outcome,num_cut,fres,ferr);

    }
    else write_fastq(name,base,descri,qual,outcome,num_cut,fres,ferr);


}





