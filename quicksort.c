// QUICKSORT ALGORITHM
#include <stdio.h>
#include <stdlib.h>
#include "quicksort.h"

struct data { //struct
	char color[10];
	char cntry[33];
	char **nb;
	int snb;
};


void quick(struct data *info,int up,int down){ //quicksort
  int start,end;
  start = up;
  end=down;
  struct data temp;
  while(up<down){
    while(info[down].snb >= info[up].snb && up<down){
      down--;
    }
    if(up!=down){
      temp=info[down];
      info[down]=info[up];
      info[up]=temp;
      up++;
    }
    while(info[up].snb <= info[down].snb && up<down){
      up++;
    }
    if(up!=down){
      temp=info[down];
      info[down]=info[up];
      info[up]=temp;
      down--;
    }
  }
  if(start<up-1){
    quick(info,start,up-1);
  }
  if(end>down+1){
    quick(info,down+1,end);
  }
}
