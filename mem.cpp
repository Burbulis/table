#include "mem.h"


char __stdcall list_started()
{
  return(!!total_list_obj);
}

void __stdcall add_to_list(coordinates *coord_,char *data_ , unsigned int size_)
{
  if ( !list_started() )
  {
    list_init(coord_,data_,size_);
  }
  else
  {
    list_next(coord_,data_,size_);
  }
  
}

void __stdcall list_init(coordinates *coord_,char *data_ , unsigned int size_)
{
  total_list_obj = (struct list*) malloc(sizeof(struct list));
  total_list_obj->data = (char *) malloc(size_*2);
  total_list_obj->count = 0;
  total_list_obj->hash = rehasher(coord_);
  memcpy(total_list_obj->data,data_,size_);
  first_list_obj = total_list_obj;
  return ;
}


void  __stdcall list_add()
{
  total_list_obj->next =(struct list *) malloc(sizeof(struct list));
  total_list_obj->prev = total_list_obj;
  last_list_obj =  total_list_obj->next;
}

void __stdcall list_next(coordinates *coord_,char *data_,unsigned long size_)
{
  list_add();
  total_list_obj->next->count = total_list_obj->count;
  total_list_obj = total_list_obj->next;
  total_list_obj->data=(char *) malloc(size_);
  total_list_obj->count++;
  total_list_obj->hash = rehasher(coord_/*,total_list_obj->count*/);
  memcpy(total_list_obj->data,data_,size_);
} 

void __stdcall list_prev(char **out)
{
	total_list_obj = total_list_obj->prev;

}

void __stdcall get_by_index(unsigned int index_,char **out)
{
 struct list *iterator = first_list_obj;
 while(1) 
 {
   unsigned int counter_ = iterator->count;
   if (counter_ == index_)
   {
    (*out) = (char *) malloc(strlen(iterator->data));
    memcpy((*out),iterator->data,strlen(iterator->data));
    break;
  }
  iterator = iterator->next;
 }
}


void __stdcall get_by_coord(coordinates *coord_,char **out)
{
 unsigned long hash_x = rehasher(coord_); 
 struct list *iterator = first_list_obj;
 while(1) 
 {
   unsigned int hash_ = iterator->hash;
   if (hash_ == hash_x)
   {
    memcpy((*out),iterator->data,strlen(iterator->data));
    break;
  }
  iterator = iterator->next;
 }
}


unsigned int __stdcall  list_count()
{
  return( total_list_obj->count );
}
