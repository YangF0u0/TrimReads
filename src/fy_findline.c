#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fy_findline.h"

int FindLine(char* filename,char* target,int i)
{
  int IfClosed=0,Number=0,Count=0;
  FILE *fp;
  char Oneline[100];
  fp=fopen(filename,"r");
  if (fp==NULL)
  {
    puts ("File open error");
    IfClosed=fclose(fp);
    if(IfClosed)
    puts ("File close error");
  }
  while(!feof(fp))
  {
    fgets(Oneline,100,fp);
    if(strstr(Oneline,target)!=NULL){
        Count++;
        if(Count==i){
          return (Number+i-1);
        }
    }
    else ++Number;
  }

  IfClosed=fclose(fp);
  if(IfClosed)
    puts ("File close error");
  return -1;
}

