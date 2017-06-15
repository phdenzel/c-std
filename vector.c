/*
 * vector.c
 *
 * @author: phdenzel
 *
 * A dynamic vector array struct of arbitrary type
 *
 * Note: dereferencing the void pointer might cost sightly more
 * in computation, but provides much more flexibility.
 * Be careful when reallocating large arrays; in some cases
 * the entire vector has to be copied to another place in memory.
 */

#include <stdio.h>
#include <stdlib.h>

#include "vector.h"


void vector_init(vector_t *v) {
  // initialize vector and allocate memory
  v->capacity = INIT_CAPACITY;
  v->length = 0;
  v->data = malloc(sizeof(void *) * v->capacity);
  
}

int vector_capacity(vector_t *v) {
  // get memory capacity of vector v
  return v->capacity;
  
}

int vector_length(vector_t *v) {
  // get length of vector v
  return v->length;
  
}

void vector_resize(vector_t *v, int capacity) {
  // resize vector v to capacity
  void **data = realloc(v->data, sizeof(void *) * capacity);
  if (data) {
    v->capacity = capacity;
    v->data = data;
  }
  
}

void vector_append(vector_t *v, void *item) {
  // append item to vector v
  // if capacity is reached the capacity is doubled
  // this should provide balance between memeory and computation time
  if (v->length == v->capacity)
    vector_resize(v, v->capacity*2);
  v->data[v->length++] = item;
  
}

void vector_set(vector_t *v, int index, void *item) {
  // set index of vector v to item
  if (index >= 0 && index < v->length)
    v->data[index] = item;
  
}

void *vector_get(vector_t *v, int index) {
  // get index of vector v
  if (index >= 0 && index < v->length)
    return v->data[index];
  return NULL;
  
}

void vector_delete(vector_t *v, int index) {
  // delete
  if (index < 0 || index >= v->length)
        return;
  v->data[index] = NULL;
  for (int i = index; i < v->length-1; i++) {
        v->data[i] = v->data[i+1];
        v->data[i+1] = NULL;
  }
  v->length--;
  if (v->length > 0 && v->length == v->capacity/4)
        vector_resize(v, v->capacity / 2);
  
}

void vector_free(vector_t *v) {
  // free the allocated memory
  free(v->data);

}

void vector_printAsInt(vector_t *v) {
  // prints all int elements of vector v
  for (int i = 0; i < v->length; i++)
    printf("%d ", (int *) vector_get(v, i));
  printf("\n");
  
}

void vector_printAsDouble(vector_t *v) {
  // prints all double elements of vector v
  for (int i = 0; i < v->length; i++)
    printf("%lf ", *(double *) vector_get(v, i));
  printf("\n");
  
}

void vector_printAsStr(vector_t *v) {
  // prints all str elements of vector v
  for (int i = 0; i < v->length; i++)
    printf("%s ", (char *) vector_get(v, i));
  printf("\n");
  
}

void vector_printAsChar(vector_t *v) {
  // print all char elements of vector v
  for (int i = 0; i < v->length; i++)
    printf("%c ", (char *) vector_get(v, i));
  printf("\n");

}
