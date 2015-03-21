#include "HashTable.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// SimpleIntHash and SimpleStringHash taken directly from midterm 2
unsigned char SimpleIntHash( int value, unsigned char range )
{
	int result;
	result = ( value % range );
	if ( result < 0 )
	{
		result = -result;
	}
	return (unsigned char) result;
}

unsigned char SimpleStringHash( char *value, unsigned char range )
{
	int total = 0;
	for (int i = 0; i < strlen( value ); i++ )
	{
		total = total + (int) value[i];
	}
	return (SimpleIntHash( total, range )); 
}

// Definitions of structs
struct HashTableObjectTag
{
        int sentinel;
        unsigned int range;
        struct HashTableBucket **bucket;
	int dynamicBehaviour;
        float expandUseFactor;
        float contractUseFactor;
};

typedef struct HashTableBucket
{
	struct HashTableEntry *entry;

} HashTableBucket;

typedef struct HashTableEntry
{
	char *key;
	void *data;
	struct HashTableEntry *left;
	struct HashTableEntry *right;

} HashTableEntry;


// Declarations of NON-API functions
int countTree(HashTableEntry *entryPtr);
struct HashTableEntry *FindItem(struct HashTableEntry *treeNodePtr, char *key);
float GetUseFactor(HashTablePTR hashTablePtr);
int keyTree(HashTableEntry *entryPtr, char **keysArray, int check);
struct HashTableEntry *FindParent(struct HashTableEntry* treeNodePtr, char *key);
int DeleteNode(struct HashTableEntry **treeNodeHandle, char *key);
int ResizeTable(HashTablePTR hashTablePtr, unsigned int size);
void DeleteAll(struct HashTableEntry *treeNodePtr);

// API functions

int CreateHashTable (HashTablePTR *hashTableHandle, unsigned int initialSize)
{
	HashTablePTR hashTablePtr;
	if (initialSize < 1)
	{
		*hashTableHandle = NULL;
		return(-1);
	}
	else
	{
		// mallocs enough size for the hashTable array
		hashTablePtr = malloc(sizeof(HashTableObject));
		if (NULL == hashTablePtr)
		{
			return(-1);
		}
		else
		{
			hashTablePtr->bucket = malloc(sizeof(HashTableBucket *) * initialSize);
			// Sets all sentinels, ranges and entries
			hashTablePtr->sentinel = (int) 0xDEADBEEF;
			hashTablePtr->range = initialSize;
			for (unsigned int i = 0; i < initialSize; i++)
			{
				(hashTablePtr->bucket)[i] = malloc(sizeof(HashTableBucket));
				(hashTablePtr->bucket)[i]->entry = NULL;
			}
			SetResizeBehaviour(hashTablePtr, 1, (float) 0.7, (float) 0.2);
			*hashTableHandle = hashTablePtr;
			return(0);
		}
	}
}

int InsertEntry (HashTablePTR hashTablePtr, char *key, void *data, void **prevDataHandle)
{
	// 3 cases, no key, hash collision and key collision
	unsigned char bucket;
	char *keyCopy;
	HashTableEntry *entryPtr;
	HashTableEntry *prevEntry;
	float useFactor;
	unsigned int size;
	HashTableBucket *tempPtr;
	
	if (NULL == hashTablePtr || 0xDEADBEEF != (*((unsigned int *) hashTablePtr)))
	{
		return(-1);
	}
	else
	{
		// bucket is the return from the hash function
		bucket = SimpleStringHash(key, (unsigned char) hashTablePtr->range);
		keyCopy = malloc(sizeof(char) * (strlen(key) + 1));
		if (NULL == keyCopy)
		{
			return(-2);
		}
		strcpy(keyCopy, key);
		// Points towards the correct bucket address
		tempPtr = (hashTablePtr->bucket)[bucket];

		// Checking empty case
		if (NULL == tempPtr->entry)
		{
			tempPtr->entry = malloc(sizeof(HashTableEntry));
			if(NULL == tempPtr->entry)
			{
				return(-2);
			}
			entryPtr = tempPtr->entry;
			entryPtr->key = keyCopy;
			entryPtr->data = data;
			entryPtr->right = NULL;
			entryPtr->left = NULL;
			useFactor = GetUseFactor(hashTablePtr);
			if (1 == hashTablePtr->dynamicBehaviour && useFactor > hashTablePtr->expandUseFactor)
			{
				size = (unsigned int) ((1 + 9/8) * (float) hashTablePtr->range);
				fprintf(stdout, "size: [%u]\n", size);
				ResizeTable(hashTablePtr, size);
			}
			useFactor = GetUseFactor(hashTablePtr);
			fprintf(stderr, "Current useFactor: [%0.3f]\n", useFactor);
			return(0);
		}

		entryPtr = tempPtr->entry;
		// Key collision if found
		// FindEntry automatically points prevDataHandle to the old data
		if (0 == FindEntry(hashTablePtr, key, prevDataHandle))
		{
			while (NULL != entryPtr)
			{
				if (0 == strcmp(entryPtr->key, key))
				{
					// Points to new data, and frees the copy of the key
					// Since initially, would've had a copy already
					entryPtr->data = data;
					free(keyCopy);
					return(2);
				}
				else
				{
					if (0 < strcmp(entryPtr->key, key))
					{
						// Strcmp returns negative, key is less than current key
						entryPtr = entryPtr->left;
					}
					else
					{
						// Strcmp returns positive, key is greater than current key
						entryPtr = entryPtr->right;
					}
				}
			}
		}
		// Hash collision when not found
		else
		{
			while (NULL != entryPtr)
			{
				prevEntry = entryPtr;
				if (0 < strcmp(entryPtr->key, key))
				{
					entryPtr = entryPtr->left;
				}
				else
				{
					entryPtr = entryPtr->right;
				}
			}
			// Creates a new binary tree at the end
			entryPtr = malloc(sizeof(HashTableEntry));
			if (NULL == entryPtr)
			{
				return(-2);
			}
			entryPtr->data = data;
			entryPtr->key = keyCopy;
			entryPtr->left = NULL;
			entryPtr->right = NULL;
			if (0 < strcmp(prevEntry->key, entryPtr->key))
			{
				prevEntry->left = entryPtr;
			}
			else
			{
				prevEntry->right = entryPtr;
			}
		}
		return(1);
	}
}

int FindEntry (HashTablePTR hashTablePtr, char *key, void **prevDataHandle)
{
	unsigned char bucket;
	HashTableBucket *tempPtr;
	HashTableEntry *entryPtr;
	
	if (NULL == hashTablePtr || 0xDEADBEEF != (*((unsigned int *) hashTablePtr)))

	{
		return(-1);
	}
	else
	{
		bucket = SimpleStringHash(key, (unsigned char) hashTablePtr->range);
		tempPtr = (hashTablePtr->bucket)[bucket];
		entryPtr = tempPtr->entry;

		// Matching the key
		entryPtr = FindItem(entryPtr, key);
		if (NULL != entryPtr)
		{
			*prevDataHandle = entryPtr->data;
			return(0);
		}
		return(-2);
	}
}

int GetHashTableInfo(HashTablePTR hashTablePtr, HashTableInfo *HashTableInfoPtr)
{
	if (NULL == hashTablePtr || 0xDEADBEEF != (*((unsigned int *) hashTablePtr)))
	{
		return(-1);
	}
	else
	{
		// Giving all the data to GetHashTableInfo
		HashTableInfoPtr->bucketCount = hashTablePtr->range;
		GetLoadFactor(hashTablePtr, &(HashTableInfoPtr->loadFactor));
		HashTableInfoPtr->useFactor = GetUseFactor(hashTablePtr);
		HashTableInfoPtr->largestBucketSize = 0;
		for (int i = 0; i < HashTableInfoPtr->bucketCount; i++)
		{
			if (HashTableInfoPtr->largestBucketSize < countTree((hashTablePtr->bucket)[i]->entry))
			{
				HashTableInfoPtr->largestBucketSize = (unsigned int) countTree((hashTablePtr->bucket)[i]->entry);
			}
		}
		HashTableInfoPtr->dynamicBehaviour = hashTablePtr->dynamicBehaviour;
		HashTableInfoPtr->expandUseFactor = hashTablePtr->expandUseFactor;
		HashTableInfoPtr->contractUseFactor = hashTablePtr->contractUseFactor;
		return(0);
	}
}

int SetResizeBehaviour(HashTablePTR hashTablePtr, int dynamicBehaviour, float expandUseFactor, float contractUseFactor)
{
	if (contractUseFactor >= expandUseFactor)
	{
		return(1);
	}
	else if (NULL == hashTablePtr || 0xDEADBEEF != (*((unsigned int *) hashTablePtr)))
	{
		return(-1);
	}
	else
	{
		if (0 == dynamicBehaviour)
		{
			// No dynamic behaviour, no resizing needed
			hashTablePtr->dynamicBehaviour = 0;
		}
		else
		{
			hashTablePtr->dynamicBehaviour = dynamicBehaviour;
			hashTablePtr->expandUseFactor = expandUseFactor;
			hashTablePtr->contractUseFactor = contractUseFactor;
		}
		return(0);
	}
}

int GetKeys(HashTablePTR hashTablePtr, char ***keysArrayHandle, unsigned int *keyCount)
{
	HashTableBucket *tempPtr;
	float loadFactor;

	if (NULL == hashTablePtr || 0xDEADBEEF != (*((unsigned int *) hashTablePtr)))
	{
		return(-1);
	}
	else
	{
		// Counting keys with GetKeys
		GetLoadFactor(hashTablePtr, &loadFactor);
		// Add 0.5 in case of rounding, as C (language) rounds to floor
		*keyCount = (unsigned int) ((loadFactor * (float) hashTablePtr->range) + 0.5);
		// Keys counted, allocating space for keysArray, and inserting keys
		*keysArrayHandle = malloc(sizeof(char *) * (*keyCount));
		
		if (NULL == keysArrayHandle)
		{
			return(-2);
		}
		for (int i = 0; i < hashTablePtr->range; i++)
		{
			tempPtr = (hashTablePtr->bucket)[i];
			if (NULL == tempPtr->entry)
			{	
				continue;
			}
			else
			{
				keyTree(tempPtr->entry, *keysArrayHandle, i);
			}
		}
		return(0);
	}
}

int GetLoadFactor(HashTablePTR hashTablePtr, float *loadFactor)
{
	int count = 0;
	if (NULL == hashTablePtr || 0xDEADBEEF != (*((unsigned int *) hashTablePtr)))
	{
		return(-1);
	}
	else
	{
		for (int i = 0; i < hashTablePtr->range; i++)
		{
			count += countTree((hashTablePtr->bucket)[i]->entry);
		}
		*loadFactor = (float) count / (float) hashTablePtr->range;
		return(0);
	}
}

int DeleteEntry(HashTablePTR hashTablePtr, char *key, void **dataHandle)
{
	// Should ask if key should be reassigned to address of key within hashTable
	unsigned char bucket;
	HashTableBucket *tempPtr;
	HashTableEntry *entryPtr;
	float useFactor;
	unsigned int size;

	if (NULL == hashTablePtr || 0xDEADBEEF != (*((unsigned int *) hashTablePtr)))
	{
		return(-1);
	}
	// Note: If FindEntry returns 0, that means the key has been found within
	// And dataHandle is automatically assigned the data corresponding to the key
	else if (0 > FindEntry(hashTablePtr, key, dataHandle))
	{
		return(-2);
	}
	else
	{
		bucket = SimpleStringHash(key, (unsigned char) hashTablePtr->range);
		tempPtr = (hashTablePtr->bucket)[bucket];
		entryPtr = tempPtr->entry;
		DeleteNode(&entryPtr, key);
		useFactor = GetUseFactor(hashTablePtr);
		if (useFactor < hashTablePtr->contractUseFactor)
		{
			size = ((hashTablePtr->range) / 2) + 1;
			ResizeTable(hashTablePtr, size);
		}
		return(0);
	}
	return(-1);
}

int DestroyHashTable(HashTablePTR *hashTableHandle)
{
	HashTableBucket *tempPtr;

	if (NULL == hashTableHandle || NULL == (*hashTableHandle))
	{
		return(-1);
	}
	else if (0xDEADBEEF != (*((unsigned int *) *hashTableHandle)))
	{
		return(-1);
	}
	else
	{
		for (int i = 0; i < (*hashTableHandle)[0].range; i++)
		{
			tempPtr = ((*hashTableHandle)->bucket)[i];
			if (NULL != tempPtr->entry)
			{
				DeleteAll(tempPtr->entry);
			}
		}
		free(*hashTableHandle);
		*hashTableHandle = NULL;
		return(0);
	}
}

////////////////// NON API FUNCTION DEFINITIONS ////////////////////
////////////////// NON API FUNCTION DEFINITIONS ////////////////////
////////////////// NON API FUNCTION DEFINITIONS ////////////////////
////////////////// NON API FUNCTION DEFINITIONS ////////////////////

int DeleteNode(struct HashTableEntry **treeNodeHandle, char *key)
{
	struct HashTableEntry *parentPtr;
	struct HashTableEntry *deletePtr;
	struct HashTableEntry *leftMost;
	struct HashTableEntry *prevPtr;

	if (NULL == (deletePtr = FindItem(*treeNodeHandle, key)))
	{
		return(-1);
	}
	else
	{
		parentPtr = FindParent(*treeNodeHandle, key);
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
				free(parentPtr->key);
				parentPtr->key = NULL;
				free(parentPtr);
				parentPtr = NULL;
			}
			else if (NULL == deletePtr->left)
			{
				parentPtr = deletePtr;
				deletePtr = deletePtr->right;
				parentPtr->right = NULL;
				free(parentPtr->key);
				parentPtr->key = NULL;
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
				free(parentPtr->key);
				parentPtr->key = NULL;
				free(deletePtr);
				deletePtr = NULL;
				deletePtr = leftMost;
			}
			(*treeNodeHandle) = deletePtr;
			return(0);
		}
		else if (NULL == (deletePtr)->right && NULL == (deletePtr)->left)
		{
			free(deletePtr->key);
			deletePtr->key = NULL;
			free(deletePtr);
			deletePtr = NULL;
			if (0 < strcmp(parentPtr->key, key))
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
			free(deletePtr->key);
			deletePtr->key = NULL;
			free(deletePtr);
			deletePtr = NULL;
		}
		else if (NULL == (deletePtr)->left)
		{
			parentPtr->right = deletePtr->right;
			deletePtr->right = NULL;
			free(deletePtr->key);
			deletePtr->key = NULL;
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
			free(deletePtr->key);
			deletePtr->key = NULL;
			free(deletePtr);
			deletePtr = NULL;
			if (0 < strcmp(parentPtr->key, leftMost->key))
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

int ResizeTable(HashTablePTR hashTablePtr, unsigned int size)
{
	char **keysArray;
	unsigned int keyCount;
	HashTablePTR newPtr = NULL;
	HashTableBucket *tempPtr;
	void *dataPtr;

	if (NULL == hashTablePtr || 0xDEADBEEF != (*((unsigned int *) (hashTablePtr))))
	{
		return(-1);
	}

	else if (0 == hashTablePtr->dynamicBehaviour)
	{
		return(-1);
	}
	else
	{
		GetKeys(hashTablePtr, &keysArray, &keyCount);
		if (0 == CreateHashTable(&newPtr, size))
		{
			for (unsigned int i = 0; i < keyCount; i++)
			{
				FindEntry(newPtr, keysArray[i], &dataPtr);
				InsertEntry(newPtr, keysArray[i], dataPtr, &dataPtr);
				free(keysArray[i]);
			}
			free(keysArray);
			
			for (unsigned int j = 0; j < hashTablePtr->range; j++)
			{
				tempPtr = (hashTablePtr->bucket)[j];
				DeleteAll(tempPtr->entry);
			}
			free(hashTablePtr->bucket);
			hashTablePtr->bucket = newPtr->bucket;
			hashTablePtr->range = size;
			free(newPtr);
			return(0);
		}
		else
		{
			return(-2);
		}
	}
}

int countTree(HashTableEntry *entryPtr)
{
	int counter = 0;
	// Recursively counts the number of entries
	if (NULL != entryPtr)
	{
		counter++;
		counter += countTree(entryPtr->left);
		counter += countTree(entryPtr->right);
	}
	return(counter);
}

struct HashTableEntry *FindItem(struct HashTableEntry *treeNodePtr, char *key)
{
	if (NULL == treeNodePtr)
	{
		return(NULL);
	}
	else
	{
		while (treeNodePtr != NULL)
		{
			if (0 == strcmp(treeNodePtr->key, key))
			{
				return(treeNodePtr);
			}
			else if (0 < strcmp(treeNodePtr->key, key))
			{
				treeNodePtr = treeNodePtr->right;
			}
			else if (0 > strcmp(treeNodePtr->key, key))
			{
				treeNodePtr = treeNodePtr->left;
			}
		}
		return(NULL);
	}
}

float GetUseFactor(HashTablePTR hashTablePtr)
{
	int count;
	unsigned int range;

	count = 0;
	range = hashTablePtr->range;
	
	// Goes through the tree and counts the total Usage
	for (int i = 0; i < range; i++)
	{
		if (NULL != (hashTablePtr->bucket)[i]->entry)
		{
			count++;
		}
	}
	return ((float) count / (float) hashTablePtr->range);
}

struct HashTableEntry *FindParent(struct HashTableEntry* treeNodePtr, char *key)
{
	if (NULL != treeNodePtr)
	{
		if (0 == strcmp(treeNodePtr->key, key) || NULL == FindItem(treeNodePtr, key))
		{
			return(NULL);
		}
		else if (0 < strcmp(treeNodePtr->key, key))
		{
			if (0 == strcmp(treeNodePtr->left->key, key))
			{
				return(treeNodePtr);
			}
			else
			{
				return(FindParent(treeNodePtr->left, key));
			}
		}
		else if (0 > strcmp(treeNodePtr->key, key))
		{
			if (0 == strcmp(treeNodePtr->right->key, key))
			{
				return(treeNodePtr);
			}
			else
			{
				return(FindParent(treeNodePtr->right, key));
			}
		}
	}
	return(NULL);
}

int keyTree(HashTableEntry *entryPtr, char **keysArray, int check)
{
	// Put all keys of a single bucket into the keysArray
	// By traversing the tree
	static int count = 0;
	
	if (0 == check)
	{
		count = 0;
	}

	if (NULL == entryPtr)
	{
		return(-1);
	}
	else
	{
		keysArray[count] = malloc(sizeof(char) * (strlen(entryPtr->key) + 1));
		if (NULL == keysArray[count])
		{
			return(-2);
		}
		else
		{
			// Copies the string into the array
			strcpy(keysArray[count], entryPtr->key);
			count++;
			keyTree(entryPtr->right, keysArray, 1);
			keyTree(entryPtr->left, keysArray, 1);
		}
		return(0);
	}
}

void DeleteAll(struct HashTableEntry *treeNodePtr)
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
		free(treeNodePtr->key);
		treeNodePtr->key = NULL;
		treeNodePtr->data = NULL;
		free(treeNodePtr);
		treeNodePtr = NULL;
	}
}
