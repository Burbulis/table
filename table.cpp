// table.cpp : Defines the entry point for the console application.
//

#include "mem.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <tchar.h>
#include "cell.h"



 
void set_cell_(char *str_)
{
	_cell cell ;
	cell = SET_CELL(str_);
	ADD_TABLE(cell);
}


int _tmain(int argc, _TCHAR* argv[])
{
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
	
	for (unsigned char  i = 1; i < 6; ++i)
	{
       char str[10];
	   sprintf_s(str,"A%d:0",i);
	   _cell cell = SET_CELL(str);
	   GET_CELL(cell);
	   printf(":%d\n",cell.value);
	}
	return (0);
}

