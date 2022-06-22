/* zry_if_files_opened_correctly.c
Author: Ruoyin Zhou
Date:2022/5/10
Function:Judge if a file is opened correctly
*/
#include "zry_if_files_opened_correctly.h"

int if_files_opened_correctly(FILE *fp){
    if(fp==NULL){
        printf("File open error\n");
        fclose(fp);
        exit (0);
    }
    else return 0;

}
