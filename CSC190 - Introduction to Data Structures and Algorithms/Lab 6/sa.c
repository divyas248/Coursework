#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "smartArray.h"

int main()
{
	struct smartArray* sA;
	unsigned int i = 10;
	int* pI = malloc(sizeof(int));
	int j;
	
	sA = createSmartArray(i);
	setPosition(sA, 10, 9);
	setPosition(sA, 4, 3);
	readPosition(sA, pI, 9);
	insertPosition(sA, 5, 12);
	deletePosition(sA, 12);
	printSmartArray(sA);
	j = getSmartArraySize(sA);
	fprintf(stdout, "size from getSize: [%d]\n", j);
	free(pI);
	destroySmartArray(&sA);
}

struct smartArray* createSmartArray(unsigned int value)
{
	struct smartArray* pSmartArray;
	if (0 == value)
	{
		pSmartArray = NULL;
		return(pSmartArray);
	}
	else if (value > 0)
	{
		pSmartArray = malloc(sizeof(struct smartArray*));
		pSmartArray->size = value;
		pSmartArray->a = malloc(sizeof(int) * value);
		for (unsigned int i = 0; i < value; i++)
		{
			pSmartArray->a[i] = 0;
		}
		return(pSmartArray);
	}
	else if (value < 0)
	{
		return(NULL);
	}
	return(NULL);
}

void destroySmartArray(struct smartArray** ppSmartArray)
{
	free((*ppSmartArray)->a);
	free(*ppSmartArray);
	*ppSmartArray = NULL;
}

int setPosition(struct smartArray* sA, int value, unsigned int position)
{
	if ( (position >= sA->size) || (NULL == sA) || (0 == sA->size) )
	{
		return(-1);
	}
	else
	{
		sA->a[position] = value;
		return(0);
	}
}

int readPosition(struct smartArray* sA, int* pInt, unsigned int position)
{
	if ( ( (position + 1) > sA->size) || (NULL == sA) || (0 == sA->size) )
	{
		return(-1);
	}
	else
	{
		*pInt = (sA->a[position]);
		return(0);
	}
}

int insertPosition(struct smartArray* sA, int value, unsigned int position)
{
	if (NULL == sA)
	{
		return(-1);
	}
	else if (position <= sA->size)
	{
		sA->a = realloc(sA->a, sizeof(int) * (sA->size + 1));
		sA->size++;
		for (unsigned int i = position + 1; i < sA->size; i++)
		{
			sA->a[i] = sA->a[i - 1];
		}
		sA->a[position] = value;
		return(0);
	}
	else if (position > sA->size)
	{
		sA->a = realloc(sA->a, sizeof(int) * (position + 1));
		for (unsigned int i = sA->size; i < position; i++)
		{
			sA->a[i] = 0;
		}
		sA->size = (position + 1);
		sA->a[position] = value;
		return(0);
	}
	else
	{
		return(-1);
	}
}

int deletePosition(struct smartArray* sA, unsigned int position)
{
	if ( (NULL == sA) || (0 == sA->size) || (position >= sA->size) )
	{
		return(-1);
	}
	else
	{
		struct smartArray* sB;
		unsigned int count = 0;
		
		sB = malloc(sizeof(struct smartArray));
		sB->size = (sA->size - 1);
		sB->a = malloc(sizeof(int) * sB->size);

		for (unsigned int i = 0; i < sA->size; i++)
		{
			if (position == i)
			{
				i++;
				count++;
			}
			sB->a[i - count] = sA->a[i];
		}

		sA->a = realloc(sA->a, sizeof(int) * (sA->size - 1));
		sA->size = (sA->size - 1);
		
		for (unsigned int j = 0; j < sA->size; j++)
		{
			sA->a[j] = sB->a[j];
		}
		destroySmartArray(&sB);
		return(0);
	}

}

void printSmartArray(struct smartArray* sA)
{
	if (NULL == sA)
	{
		fprintf(stdout, "Array is uninitialized!\n");
	}
	else if (sA->size == 0)
	{
		fprintf(stdout, "Array is empty\n");
	}
	else
	{
		for (int i = 0; i < sA->size; i++)
		{
			fprintf(stdout, "%d  ", sA->a[i]);
		}
		fprintf(stdout, "\n");
	}
}

int getSmartArraySize(struct smartArray* sA)
{
	if (NULL == sA)
	{
		return (-1);
	}
	else
	{
		return((int) sA->size);
	}
}
