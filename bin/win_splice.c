#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fy_getline.h"
#include "fy_findline.h"
#include "fy_getword.h"
#include "fy_StrToInt.h"
#include "fy_WindowSplicing.h"
#include "fy_IntToStr.h"
#include "zry_write_line.h"

/*set the default values
 *Default step length of one window is 5
 *Default threshold value of quality is 20, which means those have quality lower than 20 would be cut off.
 *Default trimming depth is 20, which means when there are 20 high-quality bases in a row, the process of window-splicing would stop.
 */

#define DEFAULT_WIN 5
#define DEFAULT_Q 20
#define DEFAULT_STOP 20

int main(int argc,char** argv)
{
  char s[100];
  char* ch;
  int i=0,j=0,line=0;
  int Q=DEFAULT_Q,WIN=DEFAULT_WIN,STOP=DEFAULT_STOP;

  /*parameter initialization
   *a loop scanning all the arguments received is used to match all the patterns
   *If "-Q" is matched, the number right after "-Q" would be the quality to be set by user.
   *If "-s" is macthed, the number right after "-s" would be the trimming depth to be set by user.
   *If "+s" is matched, the trimming depth would be "infinite"--here in the program is 100.
   *If "-w" is matched, the number right after "-w" would be the step length per window to be set by user.
   */
  for(i=3;i<argc;i++){
    if(strstr(argv[i],"-Q")!=NULL){
      ch=strstr(argv[i],"-Q");
      Q=StrToInt(ch+2);
    }

    if(strstr(argv[i],"-s")!=NULL){
      ch=strstr(argv[i],"-s");
      if(strlen(ch)>2) STOP=StrToInt(ch+2);
    }
    else if(strstr(argv[i],"+s")!=NULL){
      STOP=100;
    }

    if(strstr(argv[i],"-w")!=NULL){
      ch=strstr(argv[i],"-w");
      WIN=StrToInt(ch+2);
    }
  }

  int sum=LineNum(argv[1]);
  cover_line("",argv[2]);
  while(line<sum){
    int flag[100]={0};
    GetLine(argv[1],line+3,s);
    s[strlen(s)-1]='\0';
    int before_len=strlen(s);
    WindowSplicing(s,flag,Q,WIN,STOP);

    int after_len=strlen(s);
    char* tmp;
    char r[100];
    IntToStr(after_len,tmp);
    GetLine(argv[1],line,r);
    ch=strstr(r,"length");
    strcpy(ch+7,tmp);
    write_line(r,argv[2]);	//recompute the length and write it as the first line into the output fastq file.

    GetLine(argv[1],line+1,r);
    r[before_len]='\0';
    for(i=0;i<before_len;i++){
      if(flag[i]<0) strcpy(r+i,r+i+1);
    }
    write_line(r,argv[2]);	//trim the sequence based on the previous array "flag" and the write into the output fastq file.

    GetLine(argv[1],line+2,r);
    ch=strstr(r,"length");
    strcpy(ch+7,tmp);
    write_line(r,argv[2]);	//rewrite the third line.

    write_line(s,argv[2]);	//write the last line, quality sequence into the output fastq file.

    line+=4;	//in a fastq file, every four lines are joint together showing the information of one piece of sequence.
  }

  return 0;
}
