#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fy_getword.h"

void DeleteBlanks(char* str)
{
  while(str[0]==' '){
    strcpy(str,str+1);
  }
}

void DeleteWord(char* str)
{
  while(str[0]!=' '&&str[0]!='\n'&&str[0]!='\0'){
    strcpy(str,str+1);
  }
}

void GetWord(char* str,char* dest)
{
  int i;
  DeleteBlanks(str);
  for(i=0;str[i]!=' '&&str[i]!='\n'&&str[i]!='\0';i++){
    dest[i]=str[i];
  }
  dest[strlen(dest)]='\0'; 
  DeleteWord(str);
}
