#ifndef ZRY_WRITE_FASTQ_H_INCLUDED
#define ZRY_WRITE_FASTQ_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
void write_fastq(char name[],char base[],char descri[],char qual[],int outcome[],int num_cut,FILE *fres,FILE *ferr);

#endif // ZRY_WRITE_FASTQ_H_INCLUDED
