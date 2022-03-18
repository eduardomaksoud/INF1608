#include <stdio.h>
#include <math.h> 

#include "taylor.h"

double tan1(double x)
{
  return x + 1.0/3.0 * pow(x,3) + 2.0/15.0 * pow(x,5);
}

double tan2(double x)
{
  return (x - 1.0/6.0 * pow(x,3)) / (1.0 - 1.0/2.0 * pow(x,2) + 1.0/24.0 * pow(x,4));
}

