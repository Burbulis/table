#include <stdlib.h>
#ifndef _MEM_ALLOCATOR_
#define _MEM_ALLOCATOR_

void add_to_list(char *data_ , unsigned int size_);


#define ADD_TABLE(data,size) add_to_list(data,size)
#define GET_BY_INDEX(index,out_)

struct list
{
  struct list *next;
  struct list *prev; 
  unsigned long count;
  char *data;
};

static struct list *first_list_obj = NULL;
static struct list *last_list_obj  = NULL;
static struct list *total_list_obj = NULL;

char list_started()
{
  return(!!total_list_obj);
}


void add_to_list(char *data_ , unsigned int size_)
{
  if ( !list_started() )
  {
    list_init(data_,size_);
  }
  else
  {
    list_next(data_,size_);
  }
  
}

void list_init(char *data_ , unsigned int size_)
{
  total_list_obj = (struct list*) malloc(sizeof(struct list));
  total_list_obj->data = (char *) malloc(size_*2);
  total_list_obj->count = 0;
  memcpy(total_list_obj->data,data_,size_);
  first_list_obj = total_list_obj;
  return ;
}

void list_add()
{
  total_list_obj->next =(struct list *) malloc(sizeof(struct list));
  total_list_obj->prev = total_list_obj;
  last_list_obj =  total_list_obj->next;
}

void list_next(char *data_,unsigned long size_)
{
  list_add();
  total_list_obj->next->count = total_list_obj->count;
  total_list_obj = total_list_obj->next;
  total_list_obj->data=(char *) malloc(size_);
  total_list_obj->count++;
  memcpy(total_list_obj->data,data_,size_);
} 

void list_prev(char **out)
{
 struct list *iterator = first_list_obj;

}

void get_by_index(unsigned int index_,char **out)
{
 struct list *iterator = first_list_obj;
 while(1) 
 {
   unsigned int counter_ = iterator->count;
   if (counter_ == index_)
   {
    (*out) = malloc(strlen(iterator->data));
    memcpy((*out),iterator->data,strlen(iterator->data));
    break;
  }
  iterator = iterator->next;
 }
}

unsigned int list_count()
{
  return( total_list_obj->count );
}

#endif



