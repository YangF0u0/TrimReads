/*zry_process_pattern_one.h
Author: Ruoyin Zhou
Date:2022/5/17
Function:process the fastq file, record the screened sequences and record the clipped bases
*/
#ifndef ZRY_PROCESS_FASTQ_H_INCLUDED
#define ZRY_PROCESS_FASTQ_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void process_pattern_one(FILE *file,int stop,int threshold,int phred_value,char *result_file,char *error_file);

#endif // ZRY_PROCESS_FASTQ_H_INCLUDED
