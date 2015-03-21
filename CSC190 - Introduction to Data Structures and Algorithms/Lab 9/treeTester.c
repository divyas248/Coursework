#include "tree.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void DeleteAll(struct treeNode *);

int main()
{
	struct treeNode *treeNodePtr;
	struct treeNode *tempPtr;
	char *command;
	int check;
	void *checkPtr;
	int value;
	treeNodePtr = NULL;
	command = malloc(sizeof(char) * 10);
	do
	{
		fprintf(stdout, "Command: ");
		fscanf(stdin, "%s", command);
		if (0 == strcmp(command, "insert"))
		{
			fprintf(stdout, "Inserting\n");
			fprintf(stdout, "Item: ");
			fscanf(stdin, "%d", &value);
			Insert(&treeNodePtr, value);
		}
		else if (0 == strcmp(command, "delete"))
		{
			fprintf(stdout, "Deleting\n");
			fprintf(stdout, "Item: ");
			fscanf(stdin, "%d", &value);
			check = DeleteNode(&treeNodePtr, value);
			if (0 == check)
			{
				fprintf(stdout, "Node deleted\n");
			}
			else if (-1 == check)
			{
				fprintf(stdout, "Node not found - not deleted\n");
			}
		}
		else if (0 == strcmp(command, "find"))
		{
			fprintf(stdout, "Finding\n");
			fprintf(stdout, "Item: ");
			fscanf(stdin, "%d", &value);
			checkPtr = FindItem(treeNodePtr, value);
			if (NULL == checkPtr)
			{
				fprintf(stdout, "Item not found - not in tree\n");
			}
			else
			{
				fprintf(stdout, "Item found - address of item is: [%p]\n", checkPtr);
			}
		
		}
		else if (0 == strcmp(command, "print"))
		{
			fprintf(stdout, "Printing\n");
			fprintf(stdout, "Order (1-PreOrder; 2-InOrder; 3-PostOrder): ");
			fscanf(stdin, "%d", &check);
			if (1 == check)
			{
				check = PrintPreOrder(treeNodePtr);
			}
			else if (2 == check)
			{
				check = PrintInOrder(treeNodePtr);
			}
			else if (3 == check)
			{
				check = PrintPostOrder(treeNodePtr);
			}
			
			// See if tree is empty
			if (-1 == check)
			{
				fprintf(stdout, "Cannot print an empty tree!\n");
			}
		}
		else if (0 == strcmp(command, "quit"))
		{
			fprintf(stdout, "Quitting\n");
			DeleteAll(treeNodePtr);
			continue;
		}
		else if (0 == strcmp(command, "parent"))
		{
			fprintf(stdout, "Item: ");
			fscanf(stdin, "%d", &check);
			tempPtr = FindParent(treeNodePtr, check);
			fprintf(stdout, "The parent is at [%p]\n", (void *)tempPtr);
		}
	}
	while (0 != strcmp(command, "quit"));
	free(command);
	command = NULL;
}

void DeleteAll(struct treeNode *treeNodePtr)
{
	// Recursively delete EVERYTHING
	if (NULL == treeNodePtr)
	{
		return;
	}
	else
	{
		DeleteAll(treeNodePtr->right);
		treeNodePtr->right = NULL;
		DeleteAll(treeNodePtr->left);
		treeNodePtr->left = NULL;
		free(treeNodePtr);
		treeNodePtr = NULL;
	}
}
