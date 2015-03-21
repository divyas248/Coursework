#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "linkedList.h"

static struct node *NewNode(int value)
{
	struct node *newNode;
	newNode = malloc(sizeof(struct node));
	newNode->next = NULL;
	newNode->data = value;
	return(newNode);
}

void SortedInsert(struct node **nodeHandle, int value)
{
	struct node *nodePtr;
	struct node *nextNode;
	struct node *prevNode;
	struct node *nodeHead;

	nodePtr = NewNode(value);

	nodeHead = *nodeHandle;
	nextNode = *nodeHandle;
	
	do
	{
		prevNode = nextNode;
		if (NULL != nextNode)
		{
			nextNode = nextNode->next;
		}
	}
	while ((NULL != nextNode && value >= nextNode->data));
	
	if (NULL != prevNode && prevNode->data <= nodePtr->data)
	{
		prevNode->next = nodePtr;
		nodePtr->next = nextNode;
	}
	else
	{
		nodePtr->next = nodeHead;
	}

	if ( (NULL == *nodeHandle) || ( (NULL != nodeHead) && (nodeHead->data > nodePtr->data) ) )
	{
		*nodeHandle = nodePtr;
	}
}

int DeleteNode(struct node **nodeHandle, int value)
{
	struct node *nodePtr;
	struct node *nextNode;
	struct node *prevNode;
	int found = 0;
	
	nodePtr = *nodeHandle;
	
	if (NULL == nodePtr)
	{
		return(-1);
	}
	else
	{
		while(NULL != nodePtr) 
		{
			if (value != nodePtr->data)
			{
				prevNode = nodePtr;
				nodePtr = nodePtr->next;
			}
			else
			{
				found = 1;
				break;
			}
		}
		if (1 == found)
		{
			nextNode = nodePtr->next;
			if (nodePtr != *nodeHandle)
			{
				prevNode->next = nextNode;
			}
			else if (nodePtr == *nodeHandle)
			{
				*nodeHandle = nextNode;
			}
			free(nodePtr);
			return(0);
		}
		else
		{
			return(-1);
		}
	}

}

struct node *FindItem(struct node* nodeHead, int value)
{
	struct node* nodePtr;
	nodePtr = nodeHead;
	while (NULL != nodePtr)
	{
		if (value == nodePtr->data)
		{
			return(nodePtr);
		}
		else
		{
			nodePtr = nodePtr->next;
		}
	}
	return(NULL);
}

int PrintList(struct node* nodeHead)
{
	struct node* nodePtr;
	nodePtr = nodeHead;

	if (NULL == nodePtr)
	{
		return(-1);
	}
	else
	{
		fprintf(stdout, "Current List: ");
		while (NULL != nodePtr)
		{
			fprintf(stdout, "%d  ", nodePtr->data);
			nodePtr = nodePtr->next;
		}
		fprintf(stdout, "\n");
		return(0);
	}
}
