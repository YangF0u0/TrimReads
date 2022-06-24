#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "delete_space.h"
void delete_space(char *seq){
    int i,j = 0;
    for(i=0;i<strlen(seq);i++)
    {
        if(seq[i]!=' ')
        {
            seq[j++]=seq[i];
        }
    }
    seq[j]='\0';
}
