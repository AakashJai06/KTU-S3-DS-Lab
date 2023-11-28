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
		head =tail= newNode;
		newNode->prev = tail;
		newNode->next = head;
	}
	else{
		newNode ->next = head;
		head->prev  = newNode;
		newNode->prev = tail;
		tail->next = newNode;
		head = newNode;
	}
}
void insertEnd(int d){
	newNode = create(d);
	if(head == NULL){
		head =tail= newNode;
		newNode->prev = tail;
		newNode->next = head;
	}
	else{
		newNode -> prev = tail;
		tail->next = newNode;
		newNode->next = head;
		head->prev = newNode;
		tail = newNode;
	}
}
void deleteBeg(){
	temp = head;
	if(head == NULL){
		return;
	}
	else if(head ->next == head){
		free(head);
		head = NULL;
		tail = NULL;
	}
	else{
		head = head->next;
		head->prev = tail;
		tail->next = head;
		free(temp); 
	}
}
void deleteEnd(){
	temp = head;
	if(head == NULL){
		return;
	}
	else if(head == tail){
		free(head);
		head = NULL;
		tail = NULL;
	}
	else{

		tail = tail->prev;
		tail -> next = head;
		head->prev = tail;
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

