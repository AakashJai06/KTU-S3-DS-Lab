#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    int priority;
    struct node *next;
}*head = NULL,*newNode = NULL,*temp=NULL;

struct node * create(int priority,int data){
    newNode = (struct node *)malloc(sizeof(struct node));
    newNode->next = NULL;
    newNode->data = data;
    newNode->priority = priority;
    return newNode;
}

void insert(int data,int priority){
    newNode = create(priority,data);
    if(head == NULL || priority <= head->priority){
        newNode->next = head;
        head = newNode;
    }
    else{
         temp = head;
         while(temp->next!=NULL && temp->priority<=priority){
             temp = temp->next;
         }
         newNode->next =  temp->next;
         temp->next = newNode;
    }
}
void delete() {
    if (head == NULL) {
        printf("Queue is empty\n");
    }
    else {
        temp = head;
        printf("Deleted item: %d\n", temp->data);
        head = head->next;
        free(temp);
    }
}
void display() {
    if (head == NULL) {
        printf("Queue is empty\n");
    }
    else {
        struct node* current = head;
        printf("Queue elements:\n");
        while (current != NULL) {
            printf("%d ", current->data);
            current = current->next;
        }
        printf("\n");
    }
}
int main() {
    
    insert(4, 2);
    insert(2, 3);
    insert(5, 4);
    insert(3, 1);
    insert(1, 5);
    display();
    delete();
    display();
    return 0;
}
