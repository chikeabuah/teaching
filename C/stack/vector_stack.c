#include "stack.h"
#include "int_vector.h"

//Known type
struct stack
{
	MY_VECTOR hVector;
};

typedef struct stack Stack;


STACK stack_init_default(void)
{
	Stack* pStack;
	pStack = (Stack*) malloc(sizeof(Stack));
	if (pStack != NULL)
	{
		pStack->hVector = int_vector_init_default();
		if (pStack->hVector == NULL)
		{
			free(pStack);
			pStack = NULL;
		}
	}
	return pStack;
}

Status stack_push(STACK hStack, int item)
{
	Stack* pStack = (Stack*) hStack;
	
	return int_vector_push_back(pStack->hVector, item);
}

Status stack_pop(STACK hStack)
{
	Stack* pStack = (Stack*)hStack;

	return int_vector_pop_back(pStack->hVector);
}

int stack_top(STACK hStack, Status* pStatus)
{
	Stack* pStack = (Stack*)hStack;
	int* temp;
	temp = int_vector_at(pStack->hVector, int_vector_get_size(pStack->hVector) - 1);
	if (temp == NULL)
	{
		if (pStatus != NULL)
		{
			*pStatus = FAILURE;
		}
		return -8675309;
	}
	if (pStatus != NULL)
	{
		*pStatus = SUCCESS;
	}
	//more work needed
	return *temp;
}

Boolean stack_empty(STACK hStack)
{
	Stack* pStack = (Stack*)hStack;

	return int_vector_empty(pStack->hVector);
}

void stack_destroy(STACK* phStack)
{
	Stack* pStack = (Stack*)*phStack;

	if (pStack != NULL)
	{
		int_vector_destroy(&(pStack->hVector));
		free(pStack);
		*phStack = NULL;
	}
}