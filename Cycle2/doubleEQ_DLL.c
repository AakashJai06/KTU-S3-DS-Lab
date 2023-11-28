#include <stdio.h>
#include <stdlib.h>
struct node{
	int data;
	struct node* prev;
	struct node* next; 
};
struct node* head = NULL;
struct node* tail = NULL;
struct node* temp;
struct node* newNode;
struct node* create(int d){
		newNode = (struct node*)malloc(sizeof(struct node));
		newNode->next =NULL;
		newNode->prev =NULL;
		newNode->data = d;
		return newNode;
}
void insertBeg(int d){
	newNode = create(d);
	if(head == NULL){
		head = newNode;
		tail = newNode;
	}
	else{
		newNode ->next = head;
		head->prev  = newNode;
		head = newNode;
	}
}
void insertEnd(int d){
	newNode = create(d);
	if(head == NULL){
		head = newNode;
		tail = newNode;
	}
	else{
		newNode -> prev = tail;
		tail->next = newNode;
		tail = newNode;
	}
}
void deleteBeg(){
	if(head == NULL){
		return;
	}
	else if(head == tail){
		free(head);
		head = NULL;
		tail = NULL;
	}
	else{
		temp = head;
		head = head->next;
		temp->next = NULL;
		head -> prev = NULL;
		free(temp); 
	}
}
void deleteEnd(){
	if(head == NULL){
		return;
	}
	else if(head == tail){
		free(head);
		head = NULL;
		tail = NULL;
	}
	else{
		temp = tail;
		tail = tail->prev;
		temp->prev = NULL;
		tail -> next = NULL;
		free(temp); 
	}
}
void display(){
	if(head == NULL )
		printf("List is EMPTY!!!!");
	else{
		temp = head;
		while(temp!=NULL){
			printf("%d ",temp->data);
			temp = temp->next;
		}
	}
}
void main()
{
	int d,ch=0,p;
	do{
	printf("CHOOSE.......");
	printf("\n1)Insert Element Beginning\n2)Insert Element End\n3)Delete At Beginning\n4)Delete At End\n5)Display\n6)Exit\t\n");
	scanf("%d",&ch);
	switch(ch){
		case 1:
						printf(" Insert Element Beginning : ");
						scanf("%d",&d);
						insertBeg(d);
						display();
						break;
		case 2:
						printf(" Insert Element End : ");
						scanf("%d",&d);
						insertEnd(d);
						display();
						break;
		case 3:
						printf("Delete Element Beginning : ");
						deleteBeg();
						display();
						break;
		case 4: 
						printf("Delete Element End : ");
						deleteEnd();
						display();
						break;
		case 5: 
						display();
						break;
	}}while(ch!=6);
}

