/*zry_get_max_min.c
Author: Ruoyin Zhou
Date:2022/5/11
Function:get the max and min ascii of quality values
*/

#include <stdio.h>
#include <stdlib.h>
#include "zry_get_max_min.h"
#include "zry_get_ascii.h"

void get_max_min(char *l,int a[]){
    int num=0,value;
    while(l[num]!='\0'){
        value=get_ascii(l[num]);
        if (value<=a[0]) a[0]=value;
        if (value>=a[1]) a[1]=value;
        num++;
    }

}
