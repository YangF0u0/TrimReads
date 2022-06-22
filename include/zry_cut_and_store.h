/*zry_cut_and_store.h
Author: Ruoyin Zhou
Date:2022/5/17
Function:cut the bases below standard and store them into arrays
*/

#ifndef ZRY_CUT_AND_STORE_H_INCLUDED
#define ZRY_CUT_AND_STORE_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void cut_and_store(char name[],char seq[],char descri[],char quality[],int num,int value,int threshold,int stop,FILE *fres,FILE *ferr);

#endif // ZRY_CUT_AND_STORE_H_INCLUDED
