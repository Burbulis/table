

#ifndef __HASHER__
#define __HASHER__
#include <math.h>
#include <stdio.h>

struct coordinates
{
  char name;
  unsigned long count;
};

  unsigned long get_hash(unsigned long index);
  unsigned long rehasher(coordinates *coord_/*,unsigned long count_*/);
#endif
