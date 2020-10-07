#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "hash.h"
#ifndef _MEM_ALLOCATOR_
#define _MEM_ALLOCATOR_

#define SET_CELL(cell) add_to_list(&cell.c,cell.value);
#define GET_CELL(cell) get_by_cell(&cell.c);

struct list
{
  struct list *next;
  struct list *prev;
  unsigned long count;
  unsigned long hash;
  unsigned int  value;
};

static struct list *first_list_obj = NULL;
static struct list *last_list_obj  = NULL;
static struct list *total_list_obj = NULL;

 void  add_to_list(struct coordinates *cell ,
               unsigned int value);
 char  list_started(void);
 void  list_init(struct coordinates *cell,unsigned int value);
 void  list_add(void);
 void  list_next(struct coordinates *cell,unsigned int value);
 unsigned long list_prev();
 unsigned int get_by_index(unsigned int index_);
 unsigned int get_by_cell(struct coordinates *cell);
 unsigned int list_count();
#endif



