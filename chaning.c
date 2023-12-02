#include <stdio.h>

#include <stdlib.h>

struct Node

{

int data;

struct Node *next;

};

struct HashTable

{

int tableSize;

struct Node **table;

};

struct Node *addSortedNode(int data, struct Node *currentHead)

{

struct Node *newnode = (struct Node *)malloc(sizeof(struct Node));

newnode->data = data;

newnode->next = NULL;

if (currentHead == NULL)

{

currentHead = newnode;

return currentHead;

}

// Handle the case where the new node's data is less than the head's data

if (newnode->data < currentHead->data)

{

newnode->next = currentHead;

currentHead = newnode;

return currentHead;

}

struct Node *temp = currentHead;

struct Node *prev = NULL;

while (temp != NULL && temp->data < newnode->data)

{

prev = temp;

temp = temp->next;

}

// now prev is either at the tail node or the node whose next has to be newnode

prev->next = newnode;

newnode->next = temp;

return currentHead;

}

void printList(struct Node *currentHead)

{

if (currentHead == NULL)

{

printf("X");

return;

}

struct Node *temp = currentHead;

while (temp != NULL)

{

printf("%d-->", temp->data);

temp = temp->next;

}

printf("X");

}

struct HashTable *createTable(int size)

{

struct HashTable *ht = (struct HashTable *)malloc(sizeof(struct HashTable));

ht->tableSize = size;

ht->table = (struct Node **)malloc(sizeof(struct Node *) * size);

for (int i = 0; i < size; i++)

{

ht->table[i] = NULL;

}

return ht;

}

void insertNodeinTable(int data, struct HashTable *ht)

{

int modData = data % 10;

int index = modData;

// ht->table[index] will point to the head of linked list at correct index

ht->table[index] = addSortedNode(data, ht->table[index]);

}

void printHashTable(struct HashTable *ht)

{

for (int i = 0; i < ht->tableSize; i++)

{

struct Node *currentHead = ht->table[i];

printf("%d==>", i);

printList(ht->table[i]);

printf("\n");

}

}

int main()

{

struct HashTable *ht = createTable(10);

insertNodeinTable(10, ht);

insertNodeinTable(11, ht);

insertNodeinTable(17, ht);

insertNodeinTable(20, ht);

insertNodeinTable(25, ht);

insertNodeinTable(35, ht);

insertNodeinTable(45, ht);

printHashTable(ht);
}