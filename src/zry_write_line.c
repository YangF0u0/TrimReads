/*  zry_write_string.c
** Author: Ruoyin Zhou
** Date: 2022/5/12
** write a string into a file
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "zry_write_line.h"

void write_line(char arr[1000],char* file){
    FILE *fp=NULL;
    fp=fopen(file,"a+");
    if (fp==NULL)
    {
    puts ("File open error");
    fclose(fp);}   //open file

    int len=strlen(arr);
    int i,j=0,num=0;
    for(i=0;i<len;++i){
        fprintf(fp,"%c",arr[num]);
          num++;
        if(j<=60) j++;
        else{ j=0;
        fprintf(fp,"%c",'\n');
        }                                   //write contents into file
    }
    fprintf(fp,"%c",'\n');
    fclose(fp);
}

void cover_line(char arr[1000],char* file){
    FILE *fp=NULL;
    fp=fopen(file,"w+");
    if (fp==NULL)
    {
    puts ("File open error");
    fclose(fp);}   //open file

    int len=strlen(arr);
    int i,j=0,num=0;
    for(i=0;i<len;++i){
        fprintf(fp,"%c",arr[num]);
          num++;
        if(j<=60) j++;
        else{ j=0;
        fprintf(fp,"%c",'\n');
        }                                   //write contents into file covering the current line in the file
    }
    fclose(fp);
}


