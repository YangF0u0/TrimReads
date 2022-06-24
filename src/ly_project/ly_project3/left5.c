#include <stdlib.h>
#include <stdio.h>
#include "delete_space.h"
void left5(char *seq,int bp){
    int i;
    for(i=0;i<bp;i++){
        seq[i]=' ';
    }
    delete_space(seq);
}
