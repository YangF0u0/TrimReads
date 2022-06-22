/*zry_judge_phred.c
Author: Ruoyin Zhou
Date:2022/5/11
Function:Judge whether the fastq file uses Phred33 or Phred64
*/

#include "zry_judge_phred.h"
#include "zry_get_max_min.h"

int judge_phred(FILE *file){
    int count=0;
    char line[200];
    int extreme[2]={104,33};//store the max and min of ascii
    while(!feof(file)){
        count++;
        fgets(line,200,file);
        if (count%4==0) get_max_min(line,extreme);  //Record and update the maximum ascii value and maximum ascii value continuously
    }


    if (extreme[0]<59 && extreme[1]<=73) return 33;
    if (extreme[0]>=59 && extreme[1]>=64) return 64;
    return -1;
}
