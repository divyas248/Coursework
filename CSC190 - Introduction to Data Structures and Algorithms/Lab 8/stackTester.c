#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "stack.h"

int main()
{
	char *command;
	float data;
	int check = 1;
	struct stackNode *stackPtr;
	stackPtr = NULL;

	while (0 != check)
	{
		command = malloc(sizeof(char) * 10);
		fprintf(stdout, "Command: ");
		fscanf(stdin, "%s", command);

		if (0 == strcmp(command, "push"))
		{
			fprintf(stdout, "Number: ");
			fscanf(stdin, "%f", &data);

			if (0 == Push(&stackPtr, data))
			{
				fprintf(stdout, "Push successful\n");
			}
			else
			{
				fprintf(stdout, "Push failed\n");
			}
		}
		else if (0 == strcmp(command, "pop"))
		{
			if (0 == Pop(&stackPtr, &data))
			{
				fprintf(stdout, "Element popped: %0.2f\n", data);
			}
			else
			{
				fprintf(stdout, "Nothing to pop - stack is empty\n");
			}
		}
		else if (0 == strcmp(command, "peek"))
		{
			if (0 == Peek(stackPtr, &data))
			{
				fprintf(stdout, "Top element is: %0.2f\n", data);
			}
			else
			{
				fprintf(stdout, "Nothing to peek at - stack is empty\n");
			}
		}
		else if (0 == strcmp(command, "print"))
		{
			if (-1 == PrintStack(stackPtr))
			{
				fprintf(stdout, "Cannot print an empty stack!\n");
			}
		}	
		else if (0 == strcmp(command, "quit"))
		{
			check = 0;
		}
		free(command);
	}
}
