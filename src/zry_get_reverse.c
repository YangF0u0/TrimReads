/*zry_get_reverse.c
 * Author: Ruoyin Zhou
 * Date:2022/6/15
 * Function:get the reverse sequence
 * */

#include "zry_get_reverse.h"
void get_reverse(char a[],char b[]){
    int len=strlen(a);
    strcpy(b,"");
    int i,j;
    for(i=len-1;i>=0;i--){
        j=len-i-1;
        b[j]=a[i];
    }
b[len]='\0';
}                                                                                                                                                                                                        
