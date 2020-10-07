#include "cell.h"

coordinates to_cell(char *cell_str)
{
	char cell_name[]="ABCDE";
	char cell_index[]="01234";
	unsigned int cell_idx[] = {0,1,2,3,4};
	char *x_name = NULL;
	char *x_index = NULL;
	unsigned int i_name , i_idx;
	for (unsigned int i = 0 ; i < strlen(cell_name);++i)
	{
		i_name = i;
		x_name = strchr(cell_str,cell_name[i]);
	  if (!!x_name)
	  {
		  break;
	  }
	}
    
	for (unsigned int i = 0 ; i < strlen(cell_index);++i)
	{
	  i_idx = i;
	  x_index = strchr(cell_str,cell_index[i]);
	  if (!!x_index)
	  {
		break;
	  }
	}
	coordinates cell;
	if ((!!x_name)&&(!!x_index))
	{
		cell.name  = cell_name[i_name];
		cell.index = cell_idx[i_idx];
	}
	return (cell);
}

_cell cell_normal(char *str)
{
  char *init_ = strchr(str,':');
  int  x_ = init_ - str;
  char out[10];
  int total_ = strlen (str) - x_;
  strncpy_s(out,str,x_);
  _cell cell;
  cell.c = CELL(out);
  memset(out,0,10);
  strncpy_s(out,&str[++x_],total_--);
  cell.value =atoi(out);
  return (cell);
}
