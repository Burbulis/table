#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "mem.h"


void main (void)
{
  char x[]="test!!!!";
  unsigned int size = strlen(x); 
  ADD_TABLE(x,size);
  char *out_;
  get_by_index(0,&out_);
  printf("test:%s\n",out_);
}

