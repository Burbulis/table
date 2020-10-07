#ifndef _CELL_
#define _CELL_

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define _CELL( cell_ ) to_cell( cell_ )
#define CELL(cell) cell_normal(cell)

struct coordinates
{
  char name;
  unsigned long index;
};

struct _cell
{
  struct coordinates c;
  unsigned int value;
};


struct coordinates to_cell(char *cell_str);
struct _cell cell_normal(char *str);

#endif