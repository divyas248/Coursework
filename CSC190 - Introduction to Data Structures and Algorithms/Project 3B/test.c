#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
	char *mainKey = "Bananas";
	char *key;
	int check;
	key = malloc(sizeof(char) * 10);
	fscanf(stdin, "key: %s", key);
	check = strcmp(key, mainKey);
	fprintf(stdout, "check: [%d]\n", check);
}
