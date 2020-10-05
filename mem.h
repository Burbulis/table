#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "hash.h"
#ifndef _MEM_ALLOCATOR_
#define _MEM_ALLOCATOR_

#define ADD_TABLE(coord_,data,size) add_to_list(coord_,data,size)
#define GET_BY_INDEX(index,out_)


struct list
{
  struct list *next;
  struct list *prev;
   
  unsigned long count;
  unsigned long hash;
  char *data;
};

static struct list *first_list_obj = NULL;
static struct list *last_list_obj  = NULL;
static struct list *total_list_obj = NULL;

 void __stdcall add_to_list(coordinates *coord_ , char *data_ , unsigned int size_);
 char __stdcall list_started();
 //void __stdcall list_init(char *data_ , unsigned int size_);
 void __stdcall list_init(coordinates *coord_,char *data_ , unsigned int size_);
 void __stdcall list_add();
void __stdcall list_next(coordinates *coord_,char *data_,unsigned long size_);
 void __stdcall list_prev(char **out);
 void __stdcall get_by_index(unsigned int index_,char **out);
 void __stdcall get_by_coord(coordinates *coord_,char **out);
 unsigned int __stdcall list_count();



#endif



