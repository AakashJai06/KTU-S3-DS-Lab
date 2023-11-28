#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct node{
	char data;
	struct node* prev;
	struct node* next; 
};
char s[50];
struct node* head = NULL;
struct node* tail = NULL;
struct node* temp;
struct node* newNode;
struct node* ptr1;
struct node* ptr2;
struct node* create(char d){
		newNode = (struct node*)malloc(sizeof(struct node));
		newNode->next =NULL;
		newNode->prev =NULL;
		newNode->data = d;
		return newNode;
}
void insert(char c){
	newNode = create(c);
	if(head == NULL){
		head = newNode;
		tail = newNode;
	}
	else{
		newNode->prev = tail;
		tail -> next = newNode;
		tail = tail -> next;
	}
}
void display(){
	if(head == NULL )
		printf("List is EMPTY!!!!");
	else{
		temp = head;
		while(temp!=NULL){
			printf("%c ",temp->data);
			temp = temp->next;
		}
	}
}
void check(){
	if(head == NULL){
		printf("PLEASE ENTER A STRING");
	}
	else{
		ptr1 = head;
		ptr2 = tail;
		while(ptr1!=ptr2){
			if(ptr1->data != ptr2->data){
				printf("\nNot A Palindrome String");
				return;
			}
			ptr1 = ptr1->next;
			ptr2 = ptr2->prev;
		}
		printf("\nIts is a Palindrome String!!!");
	}
}
void main(){
	printf("Enter a String : ");
	scanf("%s",s);
	int len = strlen(s);
	for(int i=0;i<len;i++){
		insert(s[i]);
	}
	display();
	check();
}
