#include "tree.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

static struct treeNode *NewTreeNode(int value)
{
	struct treeNode *newTree;
	newTree = malloc(sizeof(struct treeNode));
	newTree->data = value;
	newTree->left = NULL;
	newTree->right = NULL;
	return(newTree);
}

void Insert(struct treeNode** treeNodeHandle, int value)
{
	struct treeNode *newTree;
	struct treeNode *treeNodePtr;
	struct treeNode *prevNodePtr;
	int check;
	
	newTree = NewTreeNode(value);
	treeNodePtr = *treeNodeHandle;
	prevNodePtr = treeNodePtr;
	check = 0;

	// Checks if treeNodeHandle is uninitialized
	if (NULL == *treeNodeHandle)
	{
		fprintf(stdout, "Empty tree, creating\n");
		*treeNodeHandle = newTree;
	}
	// Check if value is in tree already
	else if (NULL != FindItem(treeNodePtr, value))
	{
		// Value collision
		fprintf(stdout, "Item found, not inserting\n");
		free(newTree);
	}
	else
	{
		while (NULL != treeNodePtr)
		{
			prevNodePtr = treeNodePtr;
			if (treeNodePtr->data > value)
			{
				fprintf(stdout, "Going left\n");
				treeNodePtr = treeNodePtr->left;
				check = 1;
			}
			else if (treeNodePtr->data < value)
			{
				fprintf(stdout, "Going right\n");
				treeNodePtr = treeNodePtr->right;
				check = 2;
			}
		}
		if (1 == check)
		{
			prevNodePtr->left = newTree;
		}
		else if (2 == check)
		{
			prevNodePtr->right = newTree;
		}
	}
}

/* int DeleteNode(struct treeNode **treeNodeHandle, int value)
{
	struct treeNode *deletePtr;
	deletePtr = FindItem(*treeNodeHandle, value);
	
	if (NULL != deletePtr)
	{
		struct treeNode *parentPtr;
		struct treeNode *prevNodePtr;
		
		parentPtr = *treeNodeHandle;
		prevNodePtr = *treeNodeHandle;

		// Delete head node
		if (value == (*treeNodeHandle)->data)
		{
			// Checking which case applies
			if (NULL == (*treeNodeHandle)->right && NULL == (*treeNodeHandle)->left)
			{
				// Last element, left and right are NULL
				free(*treeNodeHandle);
				*treeNodeHandle = NULL;
			}
			else if (NULL == (*treeNodeHandle)->right)
			{
				// Right is NULL
				*treeNodeHandle = (*treeNodeHandle)->left;
				free(prevNodePtr);
				prevNodePtr = NULL;
			}
			else if (NULL == (*treeNodeHandle)->left)
			{
				// Left is NULL
				*treeNodeHandle = (*treeNodeHandle)->right;
				free(prevNodePtr);
				prevNodePtr = NULL;
			}
			else 
			{
				// Neither are NULL
				struct treeNode *leftMostPtr;
				leftMostPtr = deletePtr->right;
				prevNodePtr = leftMostPtr;
				while (NULL != leftMostPtr->left)
				{
					prevNodePtr = leftMostPtr;
					leftMostPtr = leftMostPtr->left;
				}
				if (prevNodePtr != leftMostPtr)
				{
					prevNodePtr->left = leftMostPtr->right;
				}
				if (deletePtr->right != leftMostPtr)
				{
					leftMostPtr->right = deletePtr->right;
				}
				leftMostPtr->left = deletePtr->left;
				deletePtr->left = NULL;
				deletePtr->right = NULL;
				free(deletePtr);
				deletePtr = NULL;
				*treeNodeHandle = leftMostPtr;		
			}
			return(0);
		}

		// Find parentPtr
		while (parentPtr->right != NULL && parentPtr->left != NULL && parentPtr->right->data != deletePtr->data && parentPtr->left->data != deletePtr->data)
		{
			if (parentPtr->data > deletePtr->data)
			{
				parentPtr = parentPtr->left;
			}
			else if (parentPtr->data < deletePtr->data)
			{
				parentPtr = parentPtr->right;
			}
		}
		
		// Checking which case applies
		if (NULL == deletePtr->left && NULL == deletePtr->right)
		{
			// No children case
			if (NULL != parentPtr->right && value == parentPtr->right->data)
			{
				fprintf(stdout, "No children, parent right is node\n");
				parentPtr->right = NULL;
			}
			else if (NULL != parentPtr->left && value == parentPtr->left->data)
			{
				fprintf(stdout, "No children, parent left is node\n");
				parentPtr->left = NULL;
			}
		}
		else if (NULL == deletePtr->right)
		{
			// Single child to the left
			struct treeNode *rightMostPtr;
			rightMostPtr = deletePtr->left;
			prevNodePtr = rightMostPtr;
			while (NULL != rightMostPtr->right)
			{
				prevNodePtr = rightMostPtr;
				rightMostPtr = rightMostPtr->right;
			}
			parentPtr->left = rightMostPtr;
			prevNodePtr->right = rightMostPtr->left;
			rightMostPtr->left = deletePtr->left;
			rightMostPtr->right = deletePtr->right;
		}
		else
		{
			//Single child to the right or both children exist
			struct treeNode *leftMostPtr;
			leftMostPtr = deletePtr->right;
			prevNodePtr = leftMostPtr;
			while (NULL != leftMostPtr->left)
			{
				prevNodePtr = leftMostPtr;
				leftMostPtr = leftMostPtr->left;
			}
			parentPtr->right = leftMostPtr;
			prevNodePtr->left = leftMostPtr->right;
			leftMostPtr->right = deletePtr->right;
			leftMostPtr->left = deletePtr->left;
		}
		free(deletePtr);
		deletePtr = NULL;
		return(0);
	}

	// Value not found
	else
	{
		return(-1);
	}
} */

int DeleteNode(struct treeNode **treeNodeHandle, int value)
{
	struct treeNode *parentPtr;
	struct treeNode *deletePtr;
	struct treeNode *leftMost;
	struct treeNode *prevPtr;

	if (NULL == (deletePtr = FindItem(*treeNodeHandle, value)))
	{
		return(-1);
	}
	else
	{
		parentPtr = FindParent(*treeNodeHandle, value);
		if (NULL == parentPtr)
		{
			// No parent, head
			if (NULL == deletePtr->right && deletePtr->left)
			{
				free(deletePtr);
				deletePtr = NULL;
			}
			else if (NULL == deletePtr->right)
			{
				parentPtr = deletePtr;
				deletePtr = deletePtr->left;
				parentPtr->left = NULL;
				parentPtr->data = (int) NULL;
				free(parentPtr);
				parentPtr = NULL;
			}
			else if (NULL == deletePtr->left)
			{
				parentPtr = deletePtr;
				deletePtr = deletePtr->right;
				parentPtr->right = NULL;
				parentPtr->data = (int) NULL;
				free(parentPtr);
				parentPtr = NULL;
			}
			else
			{
				leftMost = deletePtr->right;
				parentPtr = leftMost;
				while (NULL != leftMost->left)
				{
					parentPtr = leftMost;
					leftMost = leftMost->left;
				}
				parentPtr->left = leftMost->right;
				leftMost->left = deletePtr->left;
				leftMost->right = deletePtr->right;
				deletePtr->left = NULL;
				deletePtr->right = NULL;
				parentPtr->data = (int) NULL;
				free(deletePtr);
				deletePtr = NULL;
				deletePtr = leftMost;
			}
			(*treeNodeHandle) = deletePtr;
			return(0);
		}
		else if (NULL == (deletePtr)->right && NULL == (deletePtr)->left)
		{
			deletePtr->data = (int) NULL;
			free(deletePtr);
			deletePtr = NULL;
			if (parentPtr->data > value)
			{
				parentPtr->left = NULL;
			}
			else
			{
				parentPtr->right = NULL;
			}
		}
		else if (NULL == (deletePtr)->right)
		{
			parentPtr->left = deletePtr->left;
			deletePtr->left = NULL;
			deletePtr->data = (int) NULL;
			free(deletePtr);
			deletePtr = NULL;
		}
		else if (NULL == (deletePtr)->left)
		{
			parentPtr->right = deletePtr->right;
			deletePtr->right = NULL;
			deletePtr->data = (int) NULL;
			free(deletePtr);
			deletePtr = NULL;
		}
		else
		{
			
			leftMost = deletePtr->right;
			prevPtr = leftMost;
			while (NULL != leftMost->left)
			{
				prevPtr = leftMost;
				leftMost = leftMost->left;
			}
			if (prevPtr != leftMost)
			{
				prevPtr->left = leftMost->right;
			}
			leftMost->left = deletePtr->left;
			leftMost->right = deletePtr->right;
			deletePtr->left = NULL;
			deletePtr->right = NULL;
			deletePtr->data = (int) NULL;
			free(deletePtr);
			deletePtr = NULL;
			if (parentPtr->data > leftMost->data)
			{
				parentPtr->left = leftMost;
			}
			else
			{
				parentPtr->right = leftMost;
			}
		}
		return(0);
	}
}

struct treeNode *FindParent(struct treeNode* treeNodePtr, int value)
{
	if (NULL != treeNodePtr)
	{
		if (treeNodePtr->data == value || NULL == FindItem(treeNodePtr, value))
		{
			return(NULL);
		}
		else if (treeNodePtr->data > value)
		{
			if (value == treeNodePtr->left->data)
			{
				return(treeNodePtr);
			}
			else
			{
				return(FindParent(treeNodePtr->left, value));
			}
		}
		else if (treeNodePtr->data < value)
		{
			if (value == treeNodePtr->right->data)
			{
				return(treeNodePtr);
			}
			else
			{
				return(FindParent(treeNodePtr->right, value));
			}
		}
	}
	return(NULL);
}

struct treeNode *FindItem(struct treeNode* treeNodePtr, int value)
{
	if (NULL == treeNodePtr)
	{
		return(NULL);
	}
	else
	{
		while (treeNodePtr != NULL)
		{
			if (value == treeNodePtr->data)
			{
				return(treeNodePtr);
			}
			else if (treeNodePtr->data < value)
			{
				treeNodePtr = treeNodePtr->right;
			}
			else if (treeNodePtr->data > value)
			{
				treeNodePtr = treeNodePtr->left;
			}
		}
		return(NULL);
	}
}

int PrintPreOrder(struct treeNode *treeNodePtr)
{
	if (NULL == treeNodePtr)
	{
		return(-1);
	}
	else
	{
		fprintf(stdout, "%d\n", treeNodePtr->data);
		PrintPreOrder(treeNodePtr->left);
		PrintPreOrder(treeNodePtr->right);
		return(0);
	}
}

int PrintInOrder(struct treeNode *treeNodePtr)
{
	if (NULL == treeNodePtr)
	{
		return(-1);
	}
	else
	{
		PrintInOrder(treeNodePtr->left);
		fprintf(stdout, "%d\n", treeNodePtr->data);
		PrintInOrder(treeNodePtr->right);
		return(0);
	}

}

int PrintPostOrder(struct treeNode *treeNodePtr)
{
	if (NULL == treeNodePtr)
	{
		return(-1);
	}
	else
	{
		PrintPostOrder(treeNodePtr->left);
		PrintPostOrder(treeNodePtr->right);
		fprintf(stdout, "%d\n", treeNodePtr->data);
		return(0);
	}

}

int traverseTree(struct treeNode *treeNodePtr, int count)
{
	if (NULL != treeNodePtr)
	{
		count++;
		count = traverseTree(treeNodePtr->left, count);
		count = traverseTree(treeNodePtr->right, count);
	}
	return(count);
	
}
