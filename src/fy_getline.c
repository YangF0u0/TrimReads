#include <stdio.h>
#include <stdlib.h>
#include "fy_getline.h"

void GetLine(char* filename,int i,char* line)
{
  FILE *pFile;
  int currentline=0;
  int IfClosed=0;

  pFile=fopen(filename,"r");

  while(fgets(line,1000,pFile)!=NULL)
  {
    if(currentline==i)  break;
    else  currentline++;
  }
  
  IfClosed=fclose(pFile);
  if(IfClosed)
    puts ("File close error"); 
  return;
}

int LineNum(char* filename)
{
  FILE *fp;
  int flag = 0, file_row = 0, count = 0;
  if((fp = fopen(filename,"r")) == NULL)
    return -1;
  while(!feof(fp))
  {
    flag = fgetc(fp);
    if(flag == '\n')
      count++;
  }

  fclose(fp);
  return count;
}
