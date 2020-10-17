#include "mem.h"

char list_started()
{
  return(!!total_list_obj);
}

void  add_to_list(struct coordinates *cell,unsigned int value)
{
  if ( !list_started() )
  {
    list_init(cell,value);
  }
  else
  {
    list_next(cell,value);
  }
}

void list_init(struct coordinates *cell,unsigned int value)
{
  total_list_obj = (struct list*) malloc(sizeof(struct list));
  total_list_obj->value = value;
  total_list_obj->count = 0;
  total_list_obj->hash = rehasher(cell);
  //printf("[%c,%ld](hash_x=%ld)=%d\n",cell->name,cell->index,total_list_obj->hash,total_list_obj->value);
  first_list_obj = total_list_obj;
  return ;
}


void list_add()
{
  total_list_obj->next =(struct list *) malloc(sizeof(struct list));
  total_list_obj->prev = total_list_obj;
  last_list_obj =  total_list_obj->next;
}

void  list_next(struct coordinates *cell,unsigned int value)
{
  list_add();
  total_list_obj->next->count = total_list_obj->count;
  total_list_obj = total_list_obj->next;
  total_list_obj->value = value;
  total_list_obj->count++;
  total_list_obj->hash = rehasher(cell);
 //printf("[%c,%ld](hash_x=%ld)=%d\n",cell->name,cell->index,total_list_obj->hash,total_list_obj->value);
  last_list_obj=total_list_obj;
} 

unsigned long list_prev(char **out)
{
	total_list_obj = total_list_obj->prev;
	return (total_list_obj->count);
}

unsigned int  get_by_index(unsigned int index_)
{
 struct list *iterator = first_list_obj;
 unsigned int value = 0;
 while(1)
 {
   unsigned int counter_ = iterator->count;
   if (counter_ == index_)
   {
    value = iterator->value;
    break;
  }
  iterator = iterator->next;
 }
 return (value);
}


unsigned int get_by_cell(struct coordinates *cell)
{
 unsigned long hash_x = rehasher(cell); 
 //printf("hash_x=%zd\n",hash_x);
 unsigned int value = 0;
 struct list *iterator = first_list_obj;
 unsigned long counter_ = last_list_obj->count;
 while(1) 
 {
   unsigned long hash_ = iterator->hash;
   if (iterator->count == counter_)
   {
    // printf("not detected!!!\n\n");
     break;
   }
   if (hash_ == hash_x)
   {
     value = iterator->value;
     printf("detected!!! = %d\n\n",value);
     break;
  }
  iterator = iterator->next;
 }
 printf("val_ = %d\n",value);
 return (value);
}


unsigned int list_count()
{
  return( total_list_obj->count );
}
