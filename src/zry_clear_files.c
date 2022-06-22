/*zry_clear_file.c
Author: Ruoyin Zhou
Date:2022/5/17
Function:clear the contents of files
*/

#include <stdio.h>
#include <stdlib.h>
#include "zry_clear_files.h"

void clear_files(char *file){
    FILE *fp=NULL;
    fp=fopen(file,"w");
    fprintf(fp,"%s","");
    fclose(fp);
}
