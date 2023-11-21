#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* next;
};

struct node* top = NULL;
struct node* temp;

void push(int d) {
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    
    if (newNode == NULL) {
        printf("Memory allocation failed\n");
        return;
    }

    newNode->data = d;

    if (top != NULL) {
        newNode->next = top;
    } else {
        newNode->next = NULL;
    }

    top = newNode;
}

void pop() {
    if (top == NULL) {
        printf("Stack is EMPTY!!!!\n");
    } else {
        temp = top;
        top = top->next;
        free(temp);
    }
}

void peek() {
    if (top == NULL) {
        printf("Stack is EMPTY!!!!\n");
    } else {
        printf("Top element: %d\n", top->data);
    }
}

void display() {
    if (top == NULL) {
        printf("Stack is EMPTY!!!!\n");
    } else {
        temp = top;
        while (temp != NULL) {
            printf("%d ", temp->data);
            temp = temp->next;
        }
        printf("\n");
    }
}

int main() {
    int d, ch = 0;
    do {
        printf("CHOOSE.......\n");
        printf("1) Push\n2) Pop\n3) Peek\n4) Display\n5) Exit\n");
        scanf("%d", &ch);

        switch (ch) {
            case 1:
                printf("Enter new node data : ");
                scanf("%d", &d);
                push(d);
                display();
                break;
            case 2:
                pop();
                break;
            case 3:
                peek();
                break;
            case 4:
                display();
                break;
        }
    } while (ch != 5);

    return 0;
}

