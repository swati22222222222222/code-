#include <stdio.h>

#include <stdlib.h>

#define max 999

int i, j, a, b, min, n, ne = 0;

int parent[10];

int FindParent(int x)

{

while (x != parent[x])

x = parent[x];

return x;

}

void Union(int a, int b)

{

i = FindParent(a);

j = FindParent(b);

parent[j] = i;

}

void kruskals(int adjMatrix[n][n], int n)

{

int mst = 0;

for (i = 0; i < n; i++)

{

parent[i] = i;

}

printf("\n\tMST: \n");

while (ne < n - 1)

{

for (i = 0, min = 999; i < n; i++)

{

for (j = 0; j < n; j++)

{

if (parent[i] != parent[j] && adjMatrix[i][j] < min)

{

min = adjMatrix[i][j];

a = i;

b = j;

}

}

}

Union(a, b);

ne++;

printf("Edge %d : %d - %d = %d \n", ne, a, b, adjMatrix[a][b]);

adjMatrix[a][b] = adjMatrix[b][a] = 999;

mst += min;

}

printf("\n %d is min dist\n", mst);

}

int main()

{

printf("Enter number of vertices: ");

scanf("%d", &n);

int adjMatrix[n][n];

printf("Enter edges & weight : \n");

for (int i = 0; i < n; i++)

{

adjMatrix[i][i] = 999;

}

for (int i = 0; i < n; i++)

{

for (int j = i + 1; j < n; j++)

{

printf("weight of %d-%d : ", i, j);

scanf("%d", &adjMatrix[i][j]);

adjMatrix[j][i] = adjMatrix[i][j];

}

}

printf("\nEntered matrix is : \n");

for (i = 0; i < n; i++)

{

for (j = 0; j < n; j++)

{

printf("%d\t", adjMatrix[i][j]);

}

printf("\n");

}

kruskals(adjMatrix, n);

return 0;

}

//kruskals using list:

#include <stdio.h>

#include <stdlib.h>

// mst

int n, ne = 0, i, j, min, parent[10], a, b;

struct node

{

int vertex;

int weight;

struct node *next;

};

void create(struct node *A[], int v1, int v2, int weight)

{

struct node *p;

struct node *temp = (struct node *)malloc(sizeof(struct node));

temp->vertex = v2;

temp->weight = weight;

temp->next = NULL;

p = A[v1];

if (p == NULL)

{

A[v1] = temp;

}

else

{

while (p->next != NULL)

p = p->next;

p->next = temp;

}

temp = (struct node *)malloc(sizeof(struct node));

temp->vertex = v1;

temp->weight = weight;

temp->next = NULL;

p = A[v2];

if (p == NULL)

{

A[v2] = temp;

}

else

{

while (p->next != NULL)

p = p->next;

p->next = temp;

}

}

int findparent(int x)

{

if (x != parent[x])

x = parent[x];

return x;

}

void Union(int a, int b)

{

i = findparent(a);

j = findparent(b);

parent[j] = i;

}

void kruskal(struct node *A[], int n)

{

int mst = 0;

struct node *p = (struct node *)malloc(sizeof(struct node));

for (i = 0; i < n; i++)

{

parent[i] = i;

}

while (ne < n - 1)

{

for (i = 0, min = 999; i < n; i++)

{

p = A[i];

while (p != NULL)

{

if (p->weight < min && parent[i] != parent[p->vertex])

{

min = p->weight;

b = p->vertex;

a = i;

}

p = p->next;

}

}

if (parent[b] != b)

{

parent[a] = parent[b];

}

else

Union(a, b);

printf("%d-%d = %d\n", a, b, min);

mst += min;

ne++;

}

printf("MST is = %d", mst);

}

int main()

{

int w, n;

struct node *A[n];

printf("Enter no of vertices:");

scanf("%d", &n);

for (i = 0; i < n; i++)

{

A[i] = NULL;

}

for (i = 0; i < n; i++)

{

for (j = i + 1; j < n; j++)

{

printf("Enter weight for edge %d-%d ", i, j);

scanf(" %d", &w);

if (w != 999)

create(A, i, j, w);

}

}

kruskal(A, n);

}