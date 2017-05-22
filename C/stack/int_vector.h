#ifndef INT_VECTOR
#define INT_VECTOR 
#include "status.h"

typedef void* MY_VECTOR;

MY_VECTOR int_vector_init_default(void);

//push_back
Status int_vector_push_back(MY_VECTOR hVector, int item);

//Accessor functions
int int_vector_get_size(MY_VECTOR hVector);
int int_vector_get_capacity(MY_VECTOR hVector);

//clear
//set size to zero so that the vector appears to be empty

//
Boolean int_vector_empty(MY_VECTOR hVector);

//remove
Status int_vector_pop_back(MY_VECTOR hVector);

//look at items in the vector
int* int_vector_at(MY_VECTOR hVector, unsigned int index);


void int_vector_destroy(MY_VECTOR* phVector);

#endif