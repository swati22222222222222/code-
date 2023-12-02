#include <stdio.h>

#include <stdlib.h>

#define max 5

int queue[max];

int r = -1;

int f = -1;

int isfull()

{

if (r == max - 1)

return 1;

else

return 0;

}

int isempty()

{

if (r == -1 || f > r)

return 1;

else

return 0;

}

int enqueue(int x)

{

if (isfull())

printf("queue is full");

else

{

if (f == -1 && r == -1)

{

f = 0;

r = 0;

}

else

{

r++;

}

queue[r] = x;

printf("\nenqueue element is %d", x);

}

}

int dequeue()

{

int x;

if (isempty())

{

printf("queue is empty");

}

else

{

x = queue[f];

printf("\ndequeue element is: %d", x);

f++;

}

}

int display()

{

int i;

for (i = f; i <= r; i++)

{

printf("\n display element in queue:\n");

printf("\nelement at position %d is %d", i + 1, queue[i]);

}

}

int main()

{

enqueue(10);

enqueue(9);

enqueue(8);

enqueue(7);

enqueue(6);

dequeue();

dequeue();

display();
}