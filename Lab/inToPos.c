#include <stdio.h>
#include <stdbool.h>

#define SIZE 20

char array[100];
char stack[100];
int top = -1;
int INDEX = -1;

void addArr(char c) {
    array[++INDEX] = c;
}

void push(char c) {
    stack[++top] = c;
}

char pop() {
    char ch = stack[top--];
    return ch;
}

bool isOp(char c) {
    switch (c) {
        case '+':
        case '-':
        case '*':
        case '/':
        case '^':
        case '(':
        case ')':
            return true;
        default:
            return false;
    }
}

int prior(char c) {
    switch (c) {
        case '^':
            return 3;
        case '*':
        case '/':
            return 2;
        case '+':
        case '-':
            return 1;
        case '(':
            return 0;
        default:
            return -1; // Invalid operator
    }
}

void infixToPostfix(char c) {
    if (!isOp(c)) {
        addArr(c);
    } else {
        if (top == -1 || c == '(' || c == '^') {
            push(c);
        } else if (c == ')') {
            while (stack[top] != '(') {
                addArr(pop());
            }
            pop(); // Discard '('
        } else {
            while (top != -1 && prior(c) <= prior(stack[top])) {
                addArr(pop());
            }
            push(c);
        }
    }
}

int main() {
    char infix[SIZE];
    printf("Enter the infix operation: ");
    scanf("%s", infix);
    for (int i = 0; infix[i] != '\0'; i++) {
        infixToPostfix(infix[i]);
    }
    while (top > -1) {
        addArr(pop());
    }
    printf("Postfix expression: %s\n", array);
    return 0;
}
