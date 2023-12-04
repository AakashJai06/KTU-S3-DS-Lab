#include <stdio.h>
#include <stdlib.h>
struct node{
    int data;
    struct node* next;
}*front=NULL,*rear = NULL,*top = NULL,*temp=NULL,*newNode;
struct node * create(int d){
        newNode = (struct node *)malloc(sizeof(struct node));
        newNode->next = NULL;
        newNode->data = d;
        return newNode;
    }
void enqueue(int d){
    newNode = create(d);
        if(front == NULL){
        front = rear = newNode;
    }
    else{
        temp = rear;
        temp->next = newNode;
        rear = newNode;
}
}
int dequeue(){
    if(front == NULL)
        printf("UNDERFLOW");
    else{
        temp = front;
        front = front->next;
        int data = temp->data;
        free(temp);
        return data;
    }
}
void push(int d){
    newNode = create(d);
    if(top == NULL){
        top = newNode;
    }
    else{
        newNode->next = top;
        top = newNode;
    }
}
int pop(){
    if(top == NULL)
        printf("UNDERFLOW");
    else{
        temp = top;
        top = top->next;
        int data = temp->data;
        free(temp);
        return data;
    }
}
void display(){
	temp = front;
	if(front ==  NULL){
		printf("Queue is Empty!!!");
	}
	else{
		while(temp!=rear){
			printf("%d ",temp->data);
			temp = temp->next;
		}
	}
}
void main(){
    int n, d;
    printf("<--Number of elements-->\n");
    scanf("%d", &n);
    printf("elements-->");
    for (int i = 0; i < n; i++) {
        scanf("%d", &d);
        enqueue(d);
    }
    display();
    for (int i = 0; i < n; i++) {
        push(dequeue());
    }
    printf("<--Reversed Queue using Stack-->");
    for (int i = 0; i < n; i++) {
        printf("%d ", pop());
    }  
}
