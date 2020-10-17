

#include "hash.h"



  
  
 
unsigned long 
  rehasher(struct coordinates *cell)
  {
    if (NULL == cell)
	{
	  return (0);	 
	}
	
	unsigned long count_ = cell->index; 
	unsigned long xt = get_hash(cell->index);
	count_ = (!count_)?xt % 8:count_; 
	double pw_x = get_hash(++count_)*(get_hash(++count_)*(++count_));
     
	 unsigned long hx_ = (count_ * (get_hash(cell->name) + get_hash(xt%4))+(cell->name * get_hash(cell->name + 3) ));
	 /*+(xt * get_hash(cell->name))+pw_x)/(get_hash(cell->name)*xt)*/
     return (hx_); 
  }

  unsigned long get_hash(unsigned long index)
  {

   if (index > 100)
   {
     index = index%3;
     //printf("___idx:%ld\n",index);
   }
   unsigned long table_[100] ={
    648687483  ,683824344 ,1495049347,709689785 ,1222405562,1881988445,134270440 ,1981503013,205812075 ,112108094 ,
    1662636853 ,557232430 ,996216384 ,1984887188,1070103423,950841699 ,1530098776,1253449776,960968108 ,1651253500,
    1900641    ,1747571880,1965510065,2016171082,1581591246,23838492  ,2128279176,746701910 ,235138301 ,724210199 ,
    1152468888 ,1719223625,31897183  ,535084016 ,825189753 ,992865291 ,38853868  ,1208671906,1516388664,2027679489,
    144220300  ,1587041638,1870014356,125015829 ,186259900 ,2105152657,849226028 ,81219492  ,1757581152,941113800 ,
    1987163734 ,419360198 ,504085975 ,1048351992,1935748862,384281817 ,845496170 ,329381087 ,789643976 ,726161969, 
    1158155504 ,1264885810,1724902827,2063598916,151121214 ,1435649504,1289977686,943446657 ,1555148503,19024482406,
    395218644  ,1770020189,453328422 ,1565328590,1919870484,404247283 ,1088681576,723024698 ,165343495 ,1870833484,
    1704336688 ,54329348  ,972021821 ,1419548525,1212484853,89423983  ,996967704 ,1128600121,240545197 ,285133561,
    271094160  ,1183991855,1840282064,26058752  ,439097819 ,507494165 ,319736765 ,1592252584,1229642666,77725806
    };
    return (table_[index]);
  }  

