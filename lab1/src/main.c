#include <stdio.h>
#include <math.h> 

#include "taylor.h"

int main(void) {
  
  printf("Teste PI/3\n");
  printf("tan: %16g\n",tan(M_PI/3.0));
  printf("tan1: %16g\n",tan1(M_PI/3.0));
  printf("tan2: %16g\n\n",tan2(M_PI/3.0));

  printf("Diferença:\n");
  printf("tan1: %16g\n",fabs(tan1(M_PI/3.0) - tan(M_PI/3.0)));
  printf("tan2: %16g\n\n",fabs(tan2(M_PI/3.0) - tan(M_PI/3.0)));

  printf("----------------------------------------------------\n");

  printf("Teste PI/4\n");
  printf("tan: %16g\n",tan(M_PI/4.0));
  printf("tan1: %16g\n",tan1(M_PI/4.0));
  printf("tan2: %16g\n\n",tan2(M_PI/4.0));

  printf("Diferença:\n");
  printf("tan1: %16g\n",fabs(tan1(M_PI/4.0) - tan(M_PI/4.0)));
  printf("tan2: %16g\n\n",fabs(tan2(M_PI/4.0) - tan(M_PI/4.0)));

  printf("----------------------------------------------------\n");

  printf("Teste PI/6\n");
  printf("tan: %16g\n",tan(M_PI/6.0));
  printf("tan1: %16g\n",tan1(M_PI/6.0));
  printf("tan2: %16g\n\n",tan2(M_PI/6.0));

  printf("Diferença:\n");
  printf("tan1: %16g\n",fabs(tan1(M_PI/6.0) - tan(M_PI/6.0)));
  printf("tan2: %16g\n\n",fabs(tan2(M_PI/6.0) - tan(M_PI/6.0)));

  printf("----------------------------------------------------\n");

  printf("Teste PI/8\n");
  printf("tan: %16g\n",tan(M_PI/8.0));
  printf("tan1: %16g\n",tan1(M_PI/8.0));
  printf("tan2: %16g\n\n",tan2(M_PI/8.0));

  printf("Diferença:\n");
  printf("tan1: %16g\n",fabs(tan1(M_PI/8.0) - tan(M_PI/8.0)));
  printf("tan2: %16g\n\n",fabs(tan2(M_PI/8.0) - tan(M_PI/8.0)));

  printf("----------------------------------------------------\n");

  printf("Teste PI/10\n");
  printf("tan: %16g\n",tan(M_PI/10.0));
  printf("tan1: %16g\n",tan1(M_PI/10.0));
  printf("tan2: %16g\n\n",tan2(M_PI/10.0));

  printf("Diferença:\n");
  printf("tan1: %16g\n",fabs(tan1(M_PI/10.0) - tan(M_PI/10.0)));
  printf("tan2: %16g\n",fabs(tan2(M_PI/10.0) - tan(M_PI/10.0)));

  return 0;
}