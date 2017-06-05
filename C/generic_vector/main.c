#include <stdio.h> 
#include <stdlib.h>
#include "int_vector.h"

void bubble_sort(GENERIC_VECTOR hVector);
void my_swap(int* a, int* b);

Status integer_assignment(ITEM* phLeft, ITEM hRight);
void integer_destroy(ITEM* phItem);

int main(int argc, char* argv[])
{
	GENERIC_VECTOR hVector;
	int i;

	hVector = generic_vector_init_default(integer_assignment, integer_destroy); //first book-end
	if (hVector == NULL)
	{
		printf("Failed to allocate object.\n");
		exit(1);
	}

	//happy fun time

	for (i = 0; i < 100; i++)
	{
		int temp;
		temp = rand();
		if (generic_vector_push_back(hVector, &temp) == FAILURE)
		{
			printf("oh noes\n");
			exit(1);
		}
		printf("%d/%d\n", generic_vector_get_size(hVector), generic_vector_get_capacity(hVector));
	}

	for (i = 0; i < generic_vector_get_size(hVector); i++)
	{
		printf("%d\n", *(int*)generic_vector_at(hVector, i));
	}
	printf("****\n\n");

	bubble_sort(hVector);


	for (i = 0; i < generic_vector_get_size(hVector); i++)
	{
		printf("%d\n", *(int*)generic_vector_at(hVector, i));
	}

	generic_vector_destroy(&hVector);//last book-end
	if (hVector == NULL)
	{
		printf("VICTORY!\n");
	}



	return 0;
}

void bubble_sort(GENERIC_VECTOR hVector)
{
	int i;
	int j;
	for (i = 0; i < generic_vector_get_size(hVector) - 1; i++)
	{
		for (j = 0; j < generic_vector_get_size(hVector)-1; j++)
		{
			if (*(int*)generic_vector_at(hVector, j) > *(int*)generic_vector_at(hVector, j+1))
			{
				my_swap(generic_vector_at(hVector, j), generic_vector_at(hVector, j + 1));
			}
		}
	}
}

void my_swap(int* a, int* b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

Status integer_assignment(ITEM* phLeft, ITEM hRight)
{
	int* pLeft = (int*)*phLeft;
	int* pRight = (int*)hRight;

	//init copy branch
	if (pLeft == NULL)
	{
		*phLeft = (int*)malloc(sizeof(int));
		if (*phLeft == NULL)
		{
			return FAILURE;
		}
		pLeft = (int*)*phLeft;
	}
	*pLeft = *pRight;
	return SUCCESS;
}

void integer_destroy(ITEM* phItem)
{
	int* pInteger = (int*)*phItem;

	free(pInteger);
	*phItem = NULL;
}

