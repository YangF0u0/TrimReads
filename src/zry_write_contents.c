/*zry_write_contents.c
Author: Ruoyin Zhou
Date:2022/5/17
Function:write differnt types of lines into a file
*/



#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "zry_write_contents.h"

void write_line(char arr[],FILE *file){

    fprintf(file,"%s",arr);
    fprintf(file,"%c",'\n');

}

void add_line(char arr[],FILE *file){

    fprintf(file,"%s",arr);

}

void write_length(int a,FILE *file){
    fprintf(file,"%d",a);
    fprintf(file,"%c",'\n');
}
void write_number(int arr[],int n,FILE *file){
    int i=0;
    fprintf(file,"%s","The bases below standard (which have been cut): ");
    for(i=0;i<n;i++){
        fprintf(file,"%s","NO.");
        fprintf(file,"%d",arr[i]);
        fprintf(file,"%s"," ");
    }

     fprintf(file,"%c",'\n');
}

