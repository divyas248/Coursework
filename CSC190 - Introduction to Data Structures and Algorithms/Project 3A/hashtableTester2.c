// hashtableTester.c

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hashtable.h"

int main()
{
	char *command;
	int check = 0;
	char *key;
	HashTablePTR hashTablePtr;
	char *data;
	char *prevDataPtr;
	unsigned int *keyCount;
	float *loadFactor;
	int quit = 0;
	
	do
	{
		key = malloc(sizeof(char) * 30);
		command = malloc(sizeof(char) * 20);
		fprintf(stdout, "Command: ");
		fscanf(stdin, "%s", command);

		if (0 == strcmp(command, "create"))
		{
			int size;
			fprintf(stdout, "Size: ");
			fscanf(stdin, "%d", &size);
			check = CreateHashTable(&hashTablePtr, (unsigned int) size);
			if (0 == check)
			{
				fprintf(stdout, "Create returned non-NULL\n");
			}
			else if (-1 == check)
			{
				fprintf(stdout, "Create returned NULL\n");
			}
		}
		else if (0 == strcmp(command, "insert"))
		{
			data = malloc(sizeof(char) * 50);
			fprintf(stdout, "Key: ");
			fscanf(stdin, "%s", key);
			fprintf(stdout, "Data: ");
			fscanf(stdin, "%s", data);
			
			check = InsertEntry(hashTablePtr, key, data, (void **) &prevDataPtr);
			if (0 == check)
			{
				fprintf(stdout, "Insertion was successful\n");
			}
			else if (1 == check)
			{
				fprintf(stdout, "Hash collsion, insertion was successful\n");
			}
			else if (2 == check)
			{
				fprintf(stdout, "Key collision\n");
				free(prevDataPtr);
			}
			else if (-1 == check)
			{
				fprintf(stdout, "Does not point to a HashTableObject\n");
				free(data);
			}
		}
		else if (0 == strcmp(command, "delete"))
		{
			fprintf(stdout, "Key: ");
			fscanf(stdin, "%s", key);
			check = -1;
			DeleteEntry(hashTablePtr, key, (void **) &prevDataPtr);
			if (0 == check)
			{
				fprintf(stdout, "Entry deleted\n");
				free(prevDataPtr);
			}
			else if (-1 == check)
			{
				fprintf(stdout, "Does not point to a HashTableObject\n");
			}
			else if (-2 == check)
			{
				fprintf(stdout, "Key not found\n");
			}
			
		}
		else if (0 == strcmp(command, "find"))
		{
			fprintf(stdout, "Key: ");
			fscanf(stdin, "%s", key);
			check = FindEntry(hashTablePtr, key, (void **) &prevDataPtr);
			if (0 == check)
			{
				fprintf(stdout, "Entry found\n");
				fprintf(stdout, "Address of entry: [%p]\n", prevDataPtr);
			}
			else if (-1 == check)
			{
				fprintf(stdout, "Does not point to a HashTableObject\n");
			}
			else if (-2 == check)
			{
				fprintf(stdout, "Key not found\n");
			}
			
		} 	
		else if (0 == strcmp(command, "destroy"))
		{
			check = DestroyHashTable(&hashTablePtr);
			if (0 == check)
			{
				fprintf(stdout, "Destruction was successful\n");
			}
			else if (-1 == check)
			{
				fprintf(stdout, "Does not point to a HashTableObject\n");
			}
		}
		else if (0 == strcmp(command, "keys"))
		{
			char **keysArrayPtr;
			keyCount = malloc(sizeof(unsigned int));
			check = GetKeys(hashTablePtr, &keysArrayPtr, keyCount);
			if (0 == check)
			{
				fprintf(stdout, "Keys are: ");
				for (int i = 0; i < (int) *keyCount; i++)
				{
					fprintf(stdout, "[%s] ", keysArrayPtr[i]);
					free(keysArrayPtr[i]);
				}
				free(keysArrayPtr);
				fprintf(stdout, "\n");
			}
			else if (-1 == check)
			{
				fprintf(stdout, "Does not point to a HashTableObject\n");
			}

			free(keyCount);
		}
		else if (0 == strcmp(command, "load"))
		{
			loadFactor = malloc(sizeof(float));
			*loadFactor = 0.0;
			check = GetLoadFactor(hashTablePtr, loadFactor);
			if (0 == check)
			{
				fprintf(stdout, "Load factor: [%0.2f]\n", *loadFactor);
			}
			else if (-1 == check)
			{
				fprintf(stdout, "Does not point to a HashTableObject\n");
			}
			free(loadFactor);
		}
		else if (0 == strcmp(command, "quit"))
		{
			quit = 1;
		}
		else
		{
			fprintf(stdout, "Invalid command\n");
		}

		free(key);
		free(command);
	}
	while (0 == quit);
}
