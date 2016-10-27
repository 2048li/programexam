#include <stdlib.h>
#include <stdio.h>

//the easiest one

int hash(char* key, int size)
{
	int rect = 0;
	while (*key != '\0')
	{
		rect += *key;
		key++;
	}
	return rect%size;
}


//implement using list to solve confiction

typedef struct HashNode{
	char* key;
	char* value;
	HashNode* next;
}HashNode;

typedef struct Hashtable{
	int size;
	int item_size;
	HashNode* head;
}Hashtable;


//init hashtable;
Hashtable* hashtable_init(int size)
{
	Hashtable* hashtable = (Hashtable*)calloc(1, sizeof(Hashtable));
	hashtable->size = size;
	hashtable->item_size = 0;
	HashNode* head = (HashNode *)calloc(size, sizeof(HashNode));
	hashtable->head = head;
	return hashtable;
}

//add a 
void hashtable_add(Hashtable *hashtable, char* key, char* value)
{
	int index = hash(key, hashtable->size);
	HashNode *hashnode = hashtable->head + index;
	while(true)
	{
		if (hashnode->key == NULL || *key == *(hashnode->key))
		{
			if (hashnode->key == NULL)
			{
				hashtable->item_size = hashtable->item_size + 1;
			}
			hashnode->key = key;
			hashnode->value = value;
			return;
		}
		if (hashnode->next != NULL)
		{
			hashnode = hashnode->next;
		}
		else
		{
			HashNode *newNode = (HashNode*)calloc(1, sizeof(HashNode));
			newNode->key = key;
			newNode->value = value;
			hashnode->next = newNode;
			hashtable->item_size = hashtable->item_size + 1;
			return;
		}
	}
}

//get a
char* hashtable_get(Hashtable *hashtable, char* key)
{
	int index = hash(key, hashtable->size);
	HashNode *hashnode = hashtable->head + index;
	while (hashnode != NULL)
	{
		if(hashnode->key != NULL && *key == *(hashnode->key))
			return hashnode->value;
		hashnode = hashnode->next;
	}
	return NULL;
}

//remove a
void hashtable_remove(Hashtable *hashtable, char* key)
{
	int index = hash(key, hashtable->size);
	HashNode *hashnode = hashtable->head + index;
	HashNode *tmp = hashnode;
	while(hashnode != NULL)
	{
		if (*key == *(hashnode->key))
		{
			if ((hashtable->head + index) == hashnode)
			{
				hashnode->key = NULL;
				hashnode->value = NULL;
			}
			else
			{
				temp->next = hashnode->next;
				free(hashnode);
			}
			hashtable->item_size = hashtable->item_size -1;
			return;
		}
		temp = hashnode;
		hashnode = hashnode->next;
	}
	return;
}

//delete 
void hashtable_destory(Hashtable *hashtable)
{
	HashNode *head = hashtable->head;
	for (int index =0; index<hashtable->size; index++)
	{
		HashNode *next = head->next;
		while(next != NULL)
		{
			HashNode *tmp = next;
			next = next->next;
			free(tmp);
		}
		head ++;
		free(hashtable->head);
		free(hashtable);
	}
}

//print a
void hashtable_print(Hashtable *hashtable)
{
	HashNode *head = hashtable->head;
	HashNode *next = NULL;
	for (int index =0; index < hashtable->size; index++)
	{
		printf("index:%d\t", index);
		if (head->key != NULL)
			printf("%s:%s\t", head->key, head->value);
		next = head->next;
		while(next != NULL)
		{
			if(next->key != NULL)
				printf("%s:%s\t", next->key, next->value);
			next = next->next;
		}
		printf("\n");
		head++;
	}
}



