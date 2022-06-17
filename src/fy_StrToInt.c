#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int StrToInt(char* str)
{
  int i=0,sum=0;
  while(str[i]!='\0')
  {
    sum=sum*10+str[i]-'0';
    i++;
  }
  return sum;
}
