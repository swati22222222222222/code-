#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct stack {
    int top;
    int size;
    char *arr;
};

int isFull(struct stack *s) {
    if (s->top == s->size - 1) {
        return 1;
    } else {
        return 0;
    }
}

int isEmpty(struct stack *s) {
    if (s->top == -1) {
        return 1;
    } else {
        return 0;
    }
}

void push(struct stack *s, char data) {
    if (isFull(s)) {
        printf("Stack is full\n");
    } else {
        s->top++;
        s->arr[s->top] = data;
    }
}

char pop(struct stack *s) {
    if (isEmpty(s)) {
        printf("Stack is empty\n");
        return -1;
    } else {
        char value = s->arr[s->top];
        s->top--;
        return value;
    }
}

int isOperator(char ch) {
    if (ch == '+' || ch == '-' || ch == '*' || ch == '/') {
        return 1;
    }
    return 0;
}

int precedence(char ch) {
    if (ch == '*' || ch == '/') {
        return 3;
    }
    if (ch == '+' || ch == '-') {
        return 2;
    } else {
        return 0;
    }
}

int stackTop(struct stack *s) {
    return s->arr[s->top];
}

char *infixToPrefix(char *infix) {
    struct stack *s = (struct stack *)malloc(sizeof(struct stack));
    s->top = -1;
    s->size = 50;
    s->arr = (char *)malloc((s->size) * sizeof(char));
    char *prefix = (char *)malloc((strlen(infix) + 1) * sizeof(char));
    int i = strlen(infix) - 1; // Track the infix from the end
    int j = 0;                 // Track prefix addition

    while (i >= 0) {
        if (!isOperator(infix[i])) {
            prefix[j] = infix[i];
            j++;
            i--;
        } else {
            if (precedence(infix[i]) > precedence(stackTop(s))) {
                push(s, infix[i]);
                i--;
            } else {
                prefix[j] = pop(s);
                j++;
            }
        }
    }

    while (!isEmpty(s)) {
        prefix[j] = pop(s);
        j++;
    }

    prefix[j] = '\0';

    // Reverse the obtained prefix expression to get the correct order
    int start = 0;
    int end = j - 1;
    while (start < end) {
        char temp = prefix[start];
        prefix[start] = prefix[end];
        prefix[end] = temp;
        start++;
        end--;
    }

    return prefix;
}

int main() {
    char *infix = "x-y/z-k*d";
    printf("Prefix is %s", infixToPrefix(infix));
    return 0;
}
