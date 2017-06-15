/*
 * main_vector.c
 *
 * @author: phdenzel
 *
 * Testing vector
 */

#include <stdio.h>
#include <stdlib.h>

#include "vector.h"

int main(void) {
  printf("Test VECTOR: w/ double, int, str\n");
  // TODO: figure out a way to
  // pass doubles directly
  VECTOR_INIT(f);
  double f1 = 1.5;
  double f2 = 2.5;
  double f3 = 3.5;
  double f4 = 4.5;
  VECTOR_APPEND(f, &f1);
  VECTOR_APPEND(f, &f2);
  VECTOR_APPEND(f, &f3);
  VECTOR_APPEND(f, &f4);
  VECTOR_PRINTASDOUBLE(f);
  VECTOR_FREE(f);

  VECTOR_INIT(d);
  VECTOR_APPEND(d, 1);
  VECTOR_APPEND(d, 2);
  VECTOR_APPEND(d, 3);
  VECTOR_APPEND(d, 5);
  VECTOR_APPEND(d, 8);
  VECTOR_APPEND(d, 13);
  VECTOR_PRINTASINT(d);
  
  VECTOR_DELETE(d, 3);
  VECTOR_SET(d, 4, 99);
  VECTOR_PRINTASINT(d);
  VECTOR_FREE(d);

  VECTOR_INIT(s);
  VECTOR_APPEND(s, "I, man,");
  VECTOR_APPEND(s, "regal;");
  VECTOR_APPEND(s, "a German");
  VECTOR_APPEND(s, "am I.");
  VECTOR_PRINTASSTR(s);
  VECTOR_FREE(s);

  return 0;
  
}
