/*
 * main_vector4.c
 *
 * @author: phdenzel
 *
 * Testing vector4
 */

#include <stdio.h>
#include <stdlib.h>

#include "vector4.h"


int main(void) {
  printf("Test VECTOR4\n");

  // init
  double s[] = {0.0, 1.0, 1.0, 1.0};
  vector4_create(v1, s);
  printf("v1\t ");
  vector4_print(&v1);

  vector4_t v2 = {0.0, 100.0, 200.0 , 300.0};
  printf("v2\t ");
  vector4_print(&v2);

  { // addition
    vector4_add(&v2, &v1);
    printf("v2\t ");
    vector4_print(&v2);

    vector4_t v3 = vector4_addcpy(&v1, &v2);
    printf("v3\t ");
    vector4_print(&v3);
  }
  
  { // scaling
    vector4_scale(&v2, 4);
    printf("v2\t ");
    vector4_print(&v2);

    vector4_t v3 = vector4_scalecpy(&v1, 4);
    printf("v3\t ");
    vector4_print(&v3);
  }
  
  { // length
    printf("v2 r %lf \n", vector4_length(&v1));
    printf("v2 r2 %lf\n", vector4_length2(&v1));
  }
  
  { // normalize
    vector4_normalize(&v2);
    vector4_print(&v2);

    vector4_t v3 = vector4_normalizecpy(&v1);
    vector4_print(&v3);
  }
  
  
  return 0;
  
}
