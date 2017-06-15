/*
 * vector.h
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

#ifndef VECTOR_H
#define VECTOR_H

#define INIT_CAPACITY 3

// Macros
#define VECTOR_INIT(v) vector_t v; \
  vector_init(&v)
#define VECTOR_APPEND(v, item) \
  vector_append(&v, (void *) item)
#define VECTOR_SET(v, id, item) \
  vector_set(&v, id, (void *) item)
#define VECTOR_GET(v, type, id) \
  (type) vector_get(&v, id)
#define VECTOR_DELETE(v, id) \
  vector_delete(&v, id)
#define VECTOR_LENGTH(v) \
  vector_length(&v)
#define VECTOR_FREE(v) \
  vector_free(&v)
#define VECTOR_PRINTASINT(v) \
  vector_printAsInt(&v)
#define VECTOR_PRINTASDOUBLE(v) \
  vector_printAsDouble(&v)
#define VECTOR_PRINTASSTR(v) \
  vector_printAsStr(&v)
#define VECTOR_PRINTASCHAR(v) \
  vector_printAsChar(&v)


typedef struct vector {
  void **data;  // content
  int capacity; // total capacity in memory
  int length;   // current length
} vector_t;


void vector_init(vector_t *);
int vector_capacity(vector_t *);
int vector_length(vector_t *);
void vector_resize(vector_t *, int);
void vector_append(vector_t *, void *);
void vector_set(vector_t *, int, void *);
void *vector_get(vector_t *, int);
void vector_delete(vector_t *, int);
void vector_free(vector_t *);

// dereferencers for debugging
void vector_printAsInt(vector_t *);
void vector_printAsDouble(vector_t *);
void vector_printAsStr(vector_t *);
void vector_printAsChar(vector_t *);

#endif

