#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fy_IntToStr.h"

void IntToStr(int num,char* str)
{
  char index[]="0123456789";
  int i=0;
  while(num>0)
  {
    str[i]=index[num%10];
    num/=10;
    i++;
  }
  str[i]='\0';
  int j=0;
  char tmp;
  for(j=0;j<=(i-1)/2;j++)
  {
    tmp=str[j];
    str[j]=str[i-j-1];
    str[i-j-1]=tmp;
  }
}

