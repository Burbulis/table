#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "mem.h"
#include "cells.h"

void set_cell_(char *str_)
{
	struct _cell cell ;
  	cell = CELL(str_);
//	printf("__:[%c:%ld]\n",cell.c.name,cell.c.index);
	SET_CELL(cell);
}


unsigned long
get_min_max_by_num(char name,char min_token)
{
	unsigned int min = 10;
	unsigned int max = 0;
	unsigned int ret_ = 0;
	struct _cell cell;
    cell.value = 0;

	for (unsigned char  i = 1; i < 6; ++i)
	{
       char str[10];
	   sprintf(str,"%c%d:0\n",name,i);
	   cell = CELL(str);
	   GET_CELL(cell);
 	   printf("cell.value == %d\n",cell.value);

 	   if (cell.value < min)
	       {min = cell.value;}
	   if (cell.value > max)
	       {max = cell.value;}
  	   printf("%d:%d\n",min,max);
  	}
    printf("%d:%d:%d\n",min_token,min,max);
   ret_ = ( min_token )?min:max;
   printf("ret_=%d\n",ret_);
}

unsigned long
get_min_max_by_name(unsigned int index,char min_token)
{
	unsigned int min = 10;
	unsigned int max = 0;
	unsigned int ret_ = 0;
	struct _cell cell;
    cell.value = 0;
	const char names[] = "ABCDEF";

	for (unsigned char  i = 0; i < 5; ++i)
	{
       char str[10];
	   sprintf(str,"%c%d:0\n",names[i],index);
	   printf("str = %s\n",str);
	   cell = CELL(str);
	   GET_CELL(cell);
 	   printf("cell.value == %d\n",cell.value);

 	   if (cell.value < min)
	       {min = cell.value;}
	   if (cell.value > max)
	       {max = cell.value;}
  	   printf("%d:%d\n",min,max);
  	}
    printf("%d:%d:%d\n",min_token,min,max);
   ret_ = ( min_token )?min:max;
   printf("ret_=%d\n",ret_);

}


int main(int argc, char* argv[])
{
 printf("TEST!!!\n");

  /* if (argc > 1)
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
*/
const unsigned long cell_count = 5;
	const unsigned int values[] = {1,2,3,4,5};
	const char names[] = "ABCDEF";

	set_cell_("A0:2");
	set_cell_("B0:1");
	set_cell_("C0:3");
	set_cell_("D0:2");
	set_cell_("E0:3");

	set_cell_("A1:2");
	set_cell_("A2:1");
	set_cell_("A3:2");
	set_cell_("A4:4");
	set_cell_("A5:3");

	set_cell_("A6:3");
	set_cell_("B6:4");
	set_cell_("C6:3");
	set_cell_("D6:1");
	set_cell_("E6:2");

	set_cell_("F1:3");
	set_cell_("F2:4");
	set_cell_("F3:2");
	set_cell_("F4:1");
	set_cell_("F5:2");

get_min_max_by_name(0,1);
//get_min_max_by_num('A',0);

}

