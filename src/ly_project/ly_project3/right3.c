#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "delete_space.h"
void right3(char *seq,int bp){
    int i;
    int len=strlen(seq);
    for(i=len-1;i>len-1-bp;i--){
        seq[i]=' ';
    }
    delete_space(seq);
}
