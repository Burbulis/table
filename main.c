#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "mem.h"
#include "cells.h"

int main(int argc, char* argv[])
{

   if (argc > 1)
   {
     for (int i = 1; i < argc ; ++i)
     {
        printf("%s\n",argv[i]);
        struct _cell cell = CELL(argv[i]);
        SET_CELL(cell);
     }
   }
   struct _cell cell = CELL("C0:0");
   unsigned int x = GET_CELL(cell);
   printf("(%c,%ld)=%d\n",cell.c.name,cell.c.index,x);

}

