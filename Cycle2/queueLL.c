#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* next;
};
struct node* front = NULL;
struct node* rear = NULL;
struct node* temp;

void enqueue(int d){
	struct node* newNode = (struct node*)malloc(sizeof(struct node));
    	newNode->data = d;
	newNode->next = NULL;
    if (front == NULL) {
        front = rear = newNode;
    } else {
        	rear->next = newNode;
        	rear = newNode;
    }
}
void dequeue(){
    if (front == NULL) {
        printf("Queue is Empty!!!!");
    } 	
    else if(front == rear){
    	temp = front;
    	front = NULL;
    	rear = NULL;
    	free(temp);
    }
    else{
    	temp = front;
    	front = front->next;
    	free(temp);
    }
}
void display() {
	temp = front;
	if(front ==  NULL){
		printf("Queue is Empty!!!");
	}
	else{
		while(temp!=rear){
			printf("%d ",temp->data);
			temp = temp->next;
		}
	printf("%d.",temp->data);
	}
}
int main() {
    int d, ch = 0;
    do {
        printf("\nCHOOSE.......\n");
        printf("1) Enqueue\n2) Dequeue\n3) Exit\n");
        scanf("%d", &ch);

        switch (ch) {
            case 1:
                printf("Enter new node data : ");
                scanf("%d", &d);
                enqueue(d);
                display();
                break;
            case 2:
                dequeue();
                display();
                break;
        }
    } while (ch != 3);

    return 0;
}
