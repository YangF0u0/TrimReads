/*zry_if_cut.c
Author: Ruoyin Zhou
Date:2022/5/17
Function:Judge if a base should be cut.If a base need be cut, return 0,otherwise return 1.
*/
#include "zry_if_cut.h"
#include "zry_get_ascii.h"
int if_cut(char q,int phred_value,int threshold){
    int q_ascii,quality;
    q_ascii=get_ascii(q);
    quality=q_ascii-phred_value;
    if(quality>=threshold) return 1;
        else return 0;

}
