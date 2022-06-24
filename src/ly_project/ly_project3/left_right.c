#include <stdlib.h>
#include <stdio.h>

void left_right(char *seq,int bp){
    printf("which side do you want to clip?\n");
    printf("5'end : 5\n3'end : 3\n");
    int end;
    scanf("%d",&end);
    if(end==5)
        left5(seq,bp);
    if(end==3)
        right3(seq,bp);
    return;
}
