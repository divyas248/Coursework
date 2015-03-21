#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include "stack.h"

int RPN(char *, float *);

int main()
{
	// Declarations
	char *c;
	char *expression;
	unsigned long count;
	float result;

	// Definitions
	c = malloc(sizeof(char));
	expression = malloc(sizeof(char));
	count = 1;
	
	printf("Expression: ");
	// Continuous scanning of characters
	do
	{
		scanf("%c", c);
		expression = realloc(expression, sizeof(char) * count);
		expression[count - 1] = *c;
		count++;
	}
	while ('\n' != *c);
	free(c);
	result = (float) count;

	if (0 == RPN(expression, &result))
	{
		printf("Result: %0.2f\n", result);
	}
	else
	{
		printf("Expression is NULL\n");
	}
	free(expression);
}

int RPN(char *exp, float *total)
{
	// Declarations
	char ch;
	float f1;
	float f2;
	unsigned long length;
	struct stackNode *stackPtr;

	if (NULL == exp)
	{
		return(-1);
	}
	else if ('\n' == exp[0])
	{
		return(-1);
	}

	length = (unsigned long) *total;

	for (unsigned int i = 0; i < length; i++)
	{
		// Checks each character of the expression
		ch = exp[i];
		if (isdigit(ch))
		{
			// Pushes the digit to the top of the stack
			*total = (float) atof(&ch);
			Push(&stackPtr, *total);
		}
		else if (' ' == ch)
		{
			continue;
		}
		else if ('\n' == ch)
		{
			break;
		}
		else
		{
			// Pops the first two digits
			Pop(&stackPtr, &f1);
			Pop(&stackPtr, &f2);
			// Applies the correct operation
			if ('+' == ch)
			{
				*total = f2 + f1;
			}
			else if ('-' == ch)
			{
				*total = f2 - f1;
			}
			else if ('/' == ch)
			{
				*total = f2 / f1;
			}
			else if ('*' == ch)
			{
				*total = f2 * f1;
			}
			// Pushes the total back onto the stack
			Push(&stackPtr, *total);
		}
	}
	Pop(&stackPtr, total);
	return(0);
}

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
