#include <stdlib.h>
#include "int_vector.h"

//The KNOWN TYPE
struct vector
{
	int size;
	int capacity;
	int* data;
};
typedef struct vector Vector;

MY_VECTOR int_vector_init_default(void)
{
	Vector* pVector = (Vector*) malloc(sizeof(Vector));
	if (pVector != NULL)
	{
		//worked
		pVector->size = 0;
		pVector->capacity = 1;
		pVector->data = (int*)malloc(sizeof(int) * pVector->capacity);
		if (pVector->data == NULL)
		{
			//object is half created and we have an error
			free(pVector);
			pVector = NULL;
		}
	}
	return (MY_VECTOR)pVector;
}

Status int_vector_push_back(MY_VECTOR hVector, int item)
{
	Vector* pVector = (Vector*) hVector;
	int* temp;
	int i;

	if (pVector->size >= pVector->capacity) //no room
	{
		temp = (int*) malloc(sizeof(int)* pVector->capacity * 2);
		if (temp == NULL)
		{
			return FAILURE;
		}
		for (i = 0; i < pVector->size; i++)
		{
			temp[i] = pVector->data[i];
		}
		free(pVector->data);
		pVector->data = temp;
		pVector->capacity *= 2;
	}
	pVector->data[pVector->size] = item;
	pVector->size++;
	return SUCCESS;
}

int int_vector_get_size(MY_VECTOR hVector)
{
	//cast to the known type
	Vector* pVector = (Vector*)hVector;
	return pVector->size;
}
int int_vector_get_capacity(MY_VECTOR hVector)
{
	Vector* pVector = (Vector*)hVector;
	return pVector->capacity;
}

Boolean int_vector_empty(MY_VECTOR hVector)
{
	Vector* pVector = (Vector*)hVector;

	return (Boolean) (pVector->size == 0);
}

int* int_vector_at(MY_VECTOR hVector, unsigned int index)
{
	Vector* pVector = (Vector*)hVector;

	if (index >= pVector->size) //out of bounds!
	{
		//printf("vector subscript out of range.\n");
		return NULL;
	}

	return &(pVector->data[index]);
}

Status int_vector_pop_back(MY_VECTOR hVector)
{
	Vector* pVector = (Vector*)hVector;

	if (pVector->size == 0)
	{
		return FAILURE;
	}

	pVector->size--;
	return SUCCESS;
}

void int_vector_destroy(MY_VECTOR* phVector)
{
	Vector* pVector = (Vector*) *phVector;

	free(pVector->data);
	free(pVector);
	*phVector = NULL;
}
