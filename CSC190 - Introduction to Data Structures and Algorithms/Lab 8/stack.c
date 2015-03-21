#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "stack.h"

static struct stackNode *NewStackNode(float item)
{
	// Create a new stack
	struct stackNode *newStack;
	newStack = malloc(sizeof(struct stackNode));
	newStack->data = item;
	newStack->next = NULL;
	return(newStack);
}

int Push(struct stackNode **stackHandle, float data)
{
	struct stackNode *newTop;
	// Calls static function to allocate memory
	newTop = NewStackNode(data);
	if (NULL == newTop)
	{
		return(-1);
	}
	else
	{
		// assigns newTop to the top of the stack, links it to the current stack
		// And reassigns stackHandle to the top
		newTop->next = *stackHandle;
		*stackHandle = newTop;
		return(0);
	}
}

int Pop(struct stackNode **stackHandle, float *dataPtr)
{
	struct stackNode *next;
	if (NULL == *stackHandle)
	{
		return(-1);
	}
	else
	{
		// Assigns next to the next in line of the stack
		// Assigns data to the old data
		// Then frees stackHandle and reassigns the stack to next
		next = (*stackHandle)->next;
		*dataPtr = (*stackHandle)->data;
		free(*stackHandle);
		*stackHandle = next;
		return(0);
	}
}

int Peek(struct stackNode *stackPtr, float *dataPtr)
{
	if (NULL == stackPtr)
	{
		return(-1);
	}
	else
	{
		*dataPtr = stackPtr->data;
		return(0);
	}
}

int PrintStack(struct stackNode *stackPtr)
{
	if (NULL == stackPtr)
	{
		return(-1);
	}
	else
	{
		fprintf(stdout, "Current Stack: ");
		while (NULL != stackPtr)
		{
			fprintf(stdout, "%0.2f ", stackPtr->data);
			stackPtr = stackPtr->next;
		}
		fprintf(stdout, "\n");
		return(0);
	}
}
