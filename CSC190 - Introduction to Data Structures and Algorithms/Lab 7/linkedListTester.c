#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <readline/readline.h>
#include <readline/history.h>
#include "linkedList.h"

int main()
{
	int item, test, check = 0;
	char *command;
	struct node *nodePtr, *address;
	nodePtr = NULL;

	do
	{
		command = malloc(sizeof(char) * 10);

		if (NULL == command)
		{
			fprintf(stdout, "Out of memory\n");
			break;
		}

		fprintf(stdout, "Command: ");
		fscanf(stdin, "%s", command);
		
		if (0 == strcmp(command, "insert"))
		{
			fprintf(stdout, "Item: ");
			fscanf(stdin, "%d", &item);
			SortedInsert(&nodePtr, item);
		}
		else if (0 == strcmp(command, "print"))
		{
			item = PrintList(nodePtr);
			if (-1 == item)
			{
				fprintf(stdout, "Cannot print an empty list\n");
			}
		}
		else if (0 == strcmp(command, "find"))
		{
			fprintf(stdout, "Item: ");
			fscanf(stdin, "%d", &item);
			address = FindItem(nodePtr, item);
			if (NULL == address)
			{
				fprintf(stdout, "Item not found - not in list\n");
			}
			else
			{
				fprintf(stdout, "Item found - address of item is: [%p]\n", (void *) address);
			}
		}
		else if (0 == strcmp(command, "delete"))
		{
			fprintf(stdout, "Item: ");
			fscanf(stdin, "%d", &item);
			test = DeleteNode(&nodePtr, item);
			if (-1 == test)
			{
				fprintf(stdout, "Node not found - not deleted\n");
			}
			else if (0 == test)
			{
				fprintf(stdout, "Node deleted\n");
			}
		}
		else if (0 == strcmp(command, "quit"))
		{
			address = nodePtr;
			while (NULL != nodePtr)
			{
				address = nodePtr->next;
				free(nodePtr);
				nodePtr = address;
			}
			check = -1;
		}
		else
		{
			fprintf(stdout, "Invalid command\n");
		}

		free(command);
	}
	while (-1 != check);
}
