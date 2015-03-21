typedef struct HashTableObject
{
	int sentinel;
	unsigned int range;
	struct HashTableBucket **bucket;

} HashTableObject;
typedef HashTableObject *HashTablePTR;
int CreateHashTable( HashTablePTR *hashTableHandle, unsigned int initialSize );
int DestroyHashTable( HashTablePTR *hashTableHandle );
int InsertEntry( HashTablePTR hashTable, char *key, void *data, void **previousDataHandle );
int DeleteEntry( HashTablePTR hashTable, char *key, void **dataHandle );
int FindEntry( HashTablePTR hashTable, char *key, void **dataHandle );
int GetKeys( HashTablePTR hashTable, char ***keysArrayHandle, unsigned int *keyCount );
int GetLoadFactor( HashTablePTR hashTable, float *loadFactor );
int ResizeTable(HashTablePTR hashTablePtr, unsigned int size);
