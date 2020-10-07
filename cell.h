#ifndef _CELL_
#define _CELL_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define CELL( cell_ ) to_cell( cell_ )
#define SET_CELL(cell) cell_normal(cell)

struct coordinates
{
  char name;
  unsigned long index;
};

struct _cell
{
  coordinates c;
  unsigned int value;
};


coordinates to_cell(char *cell_str);
_cell cell_normal(char *str);

#endif

