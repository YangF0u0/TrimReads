#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fy_WindowSplicing.h"
#include "zry_get_max_min.h"

void WindowSplicing(char* s,int* flag,const int Q,const int WIN,const int STOP)
{
  int len=strlen(s);
  int score[100],i=0;
  int phred=33;
  int extreme[2];
  get_max_min(s,extreme);
  if (extreme[0]<59 && extreme[1]<=73) phred=33;
  if (extreme[0]>=59 && extreme[1]>=64) phred=64;
  for(i=0;i<len;i++) {score[i]=s[i]-phred-Q;}	//record the quality score of the sequence.
  int sum=0,negative=0,count=0,j=0;i=0;
  int* win=score;

  /*principle for window-splice
 *WIN is the default or set-by-user step length of a single window.
 *In each window, once there are more than 2 lower than the threshold Q, and the average is also lower than Q,
those lower tahn Q in this specific window may be cut off. Then the window pointer will slide one base.
 *Otherwise, this window would be saved, and "count" would add itself. Then the pointer for locating the window will slide the whole window.
 *When there are more than STOP(trimming depth default or set-by-user) saved, the splicing process would stop.
 */
  while(i<len){
    sum=0;negative=0;
    for(j=0;j<WIN && i+j<len;j++){
      sum+=*(win+j);
      if(*(win+j)<=0) negative++;
    }
    
    if(sum<=0 && negative>=2){
      for(j=0;j<WIN && i+j<len;j++) {if(flag[i+j]==0) flag[i+j]=-1;}
      i++;win=score+i;count=0;
    }
    else{
      for(j=0;j<WIN && i+j<len;j++) {if(flag[i+j]==0) flag[i+j]=1;}
      i+=WIN;win=score+i;count++;
    }

    if(count*WIN>=STOP) break;
  }
  for(i=0;i<len;i++){
    if(flag[i]<0) strcpy(s+i,s+i+1);
  }
}
