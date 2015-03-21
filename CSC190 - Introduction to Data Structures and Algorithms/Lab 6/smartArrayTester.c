// smartArrayTester.c
// Not a lot of comments in this since it's the tester

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "smartArray.h"

int main()
{
	// Declaring all variables to be used
	char *input;
	struct smartArray* sA;
	unsigned int size;
	unsigned int position;
	int value;
	int trial;
	int* read;

	// Largest input size will be destroy, which has 8 bytes (1 for each character, and terminating 0)
	input = malloc(sizeof(char) * 8);

	do
	{
		fprintf(stdout, "Command: ");
		fscanf(stdin, "%s", input);

		// Couldn't use switch-case as input isn't an integer :(

		if (0 == strcmp(input,"create"))
		{
			fprintf(stdout, "Size: ");
			fscanf(stdin, "%u", &size);
			sA = createSmartArray(size);
			if (NULL != sA)
			{
				fprintf(stdout,"create returned non-NULL\n");
			}
			else
			{
				fprintf(stdout, "create returned NULL\n");
			}
		}
		else if (0 == strcmp(input,"size"))
		{
			size = (unsigned int) getSmartArraySize(sA);
			fprintf(stdout, "Size: [%u]\n", size);	
		}
		else if (0 == strcmp(input,"set"))
		{
			fprintf(stdout, "Value and Position: ");
			fscanf(stdin, "%d %u", &value, &position);
			trial = setPosition(sA, value, position);
			if (0 == trial)
			{
				fprintf(stdout, "setPosition returned success\n");
			}
			else
			{
				fprintf(stdout, "setPosition returned failure\n");
			}
		}
		else if (0 == strcmp(input,"read"))
		{
			fprintf(stdout, "Position: ");
			fscanf(stdin, "%u", &position);
			read = malloc(sizeof(int));
			trial = readPosition(sA, read, position);
			if (0 == trial)
			{
				fprintf(stdout, "%d\n", *read);
			}
			free(read);
		}
		else if (0 == strcmp(input,"print"))
		{
			printSmartArray(sA);
		}
		else if (0 == strcmp(input,"insert"))
		{
			fprintf(stdout, "Value and Position: ");
			fscanf(stdin, "%d %u", &value, &position);
			trial = insertPosition(sA, value, position);
			if (0 == trial)
			{
				fprintf(stdout, "insertPosition returned success\n");
			}
			else
			{
				fprintf(stdout, "insertPosition returned faiure\n");
			}
		}
		else if (0 == strcmp(input,"delete"))
		{
			fprintf(stdout, "Position: ");
			fscanf(stdin, "%u", &position);
			trial = deletePosition(sA, position);
			if (0 == trial)
			{
				fprintf(stdout, "deletePosition returned success\n");
			}
			else
			{
				fprintf(stdout, "deletePosition returned failure\n");
			}
		}
		else if (0 == strcmp(input,"destroy"))
		{
			destroySmartArray(&sA);
		}
		else if (0 == strcmp(input,"quit"))
		{
			free(input);
			break;
		}
		else
		{
			continue;
		}
	}
	while(1);
}
