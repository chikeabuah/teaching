//#include "stack.h"
//
//struct node;
//typedef struct node Node;
//
//struct node
//{
//	int data;
//	Node* next;
//};
//
////known type
//struct stack
//{
//	Node* head;
//};
//
//typedef struct stack Stack;
//
//
//STACK stack_init_default(void)
//{
//	Stack* pStack;
//
//	pStack = (Stack*) malloc(sizeof(Stack));
//	if (pStack != NULL)
//	{
//		pStack->head = NULL;
//	}
//	return pStack;
//}
//
//Status stack_push(STACK hStack, int item)
//{
//	Stack* pStack = (Stack*) hStack;
//	Node* temp;
//
//	temp = (Node*) malloc(sizeof(Node));
//	if (temp == NULL)
//	{
//		return FAILURE;
//	}
//	else
//	{
//		temp->data = item;
//		temp->next = pStack->head;
//		pStack->head = temp;
//	}
//	return SUCCESS;
//}
//
//Status stack_pop(STACK hStack)
//{
//	Stack* pStack = (Stack*)hStack;
//	Node* temp;
//
//	if (pStack->head == NULL)
//	{
//		return FAILURE;
//	}
//	else
//	{
//		temp = pStack->head;
//		pStack->head = pStack->head->next;
//		free(temp);
//	}
//	return SUCCESS;	
//}
//
//int stack_top(STACK hStack, Status* pStatus)
//{
//	Stack* pStack = (Stack*)hStack;
//
//	//if pStatus is NULL then ignore the status.
//	if (stack_empty(hStack))
//	{
//		if (pStatus != NULL)
//		{
//			*pStatus = FAILURE;
//		}
//		return -8887888;
//	}
//	
//	if (pStatus != NULL)
//	{
//		*pStatus = SUCCESS;
//	}
//
//	return pStack->head->data;
//}
//
//Boolean stack_empty(STACK hStack)
//{
//	Stack* pStack = (Stack*)hStack;
//
//	return (Boolean)(pStack->head == NULL);
//}
//
//void stack_destroy(STACK* phStack)
//{
//	Stack* pStack = (Stack*)*phStack;
//	Node* temp;
//	if (pStack != NULL)
//	{
//		while (pStack->head != NULL)
//		{
//			temp = pStack->head;
//			pStack->head = pStack->head->next;
//			free(temp);
//		}
//		free(pStack);
//		*phStack = NULL;
//	}
//}