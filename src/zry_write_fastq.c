

#include <stdlib.h>
#include <stdio.h>
#include "zry_write_contents.h"
void write_fastq(char name[],char base[],char descri[],char qual[],int outcome[],int num_cut,FILE *fres,FILE *ferr){
    int i,len_name,len_descri,new_length;
    len_name=strlen(name);
    len_descri=strlen(descri);
    char new_name[100],new_descri[100];
    for(i=0;i<len_name;i++){
        if(name[i-3]=='t' && name[i-2]=='h' && name[i-1]=='='){
	     memcpy(new_name,name,i);
             new_name[i]='\0';
        } 
    }
    for(i=0;i<len_name;i++){
        if(descri[i-3]=='t' && descri[i-2]=='h' && descri[i-1]=='='){
             memcpy(new_descri,descri,i);
             new_descri[i]='\0';
         } 
    }

   

    new_length=strlen(base);

    add_line(new_name,fres);
    write_length(new_length,fres);
    write_line(base,fres);
    add_line(new_descri,fres);
    write_length(new_length,fres);
    write_line(qual,fres);
    if(num_cut!=0){
        add_line(new_name,ferr);
        write_length(new_length,ferr);
        write_number(outcome,num_cut,ferr);
    }




}
