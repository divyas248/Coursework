int ResizeTable(HashTablePTR *hashTableHandle, unsigned int size)
{
	char **keysArray;
	unsigned int keyCount;
	hashTablePTR *newTableHandle;
	hashTablePTR newTablePtr;
	HashTablePTR hashTablePtr = *hashTableHandle;
	void *dataPtr;

	if (NULL == hashTablePtr || 0xDEADBEEF != (*((unsigned int *) hashTablePtr)))
	{
		return(-1);
	}

	else if (0 == hashTablePtr[0].dynamicBehaviour)
	{
		return(-1);
	}
	else
	{
		GetKeys(hashTablePtr, &keysArray, &keyCount);
		if (0 == CreateHashTable(newTableHandle, size))
		{
			newTablePtr = *newTableHandle;
		}
		else
		{
			return(-2);
		}

		for (unsigned int i = 0; i < keyCount; i++)
		{
			FindEntry(hashTablePtr, keysArray[i], &dataPtr);
			InsertEntry(newTablePtr, keysArray[i], dataPtr, &dataPtr);
		}
		DestroyHashTable(hashTableHandle);
		hashTableHandle = newTableHandle;
		*hashTableHandle = newTablePtr;
	}
}
