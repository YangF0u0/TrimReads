/*zry_judge_phred.c
Author: Ruoyin Zhou
Date:2022/5/11
Function:Judge whether the fastq file uses Phred33 or Phred64
*/

#ifndef ZRY_JUDGE_PHRED_H_INCLUDED
#define ZRY_JUDGE_PHRED_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
int judge_phred(FILE *file);

#endif // ZRY_JUDGE_PHRED_H_INCLUDED
