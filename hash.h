#ifndef __HASHER__
#define __HASHER__
#include <math.h>
#include <stdio.h>
#include "cells.h"
  unsigned long get_hash(unsigned long index);
  unsigned long rehasher(struct coordinates *cell);
#endif