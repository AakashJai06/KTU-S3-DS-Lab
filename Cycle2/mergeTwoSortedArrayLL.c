#include <stdio.h>
#include <stdlib.h>
struct node{
    int data;
    struct node* next;
}*newNode,*head1=NULL,*head2=NULL,*head3 = NULL,*temp,*ptr1,*ptr2;
struct node* create(int d){
    newNode = (struct node*)malloc(sizeof(struct node));
    newNode->next = NULL;
    newNode->data = d;
    return newNode;
}
void insert(struct node** head,int d){
   newNode = create(d);
	if(*head == NULL){
		*head = newNode;
	}
	else{
	    temp = *head;
		while(temp->next!=NULL)
			{
				temp = temp->next;
			} 
			temp->next = newNode;
	}
}
void merge(struct node* head1,struct node* head2,struct node** head3){
    ptr1 = head1;
    ptr2 = head2;
    while(ptr1!= NULL && ptr2!= NULL){
        if(ptr1->data < ptr2->data){
            insert(head3,ptr1->data);
            ptr1 = ptr1->next;
        }
        else if(ptr2->data < ptr1->data){
            insert(head3,ptr2->data);
            ptr2 = ptr2->next;
        }
    }
    while(ptr1 != NULL){
        insert(head3,ptr1->data);
        ptr1 = ptr1->next;
    }
    while(ptr2!= NULL){
        insert(head3,ptr2->data);
        ptr2 = ptr2->next;
    }
}
void display(struct node** head){
    if(*head == NULL )
		printf("List is EMPTY!!!!");
	else{
		temp = *head;
		while(temp!=NULL){
			printf("%d ",temp->data);
			temp = temp->next;
		}
	}
}
int main() {
    int n1, n2,d;

    printf("<-NUMBER OF ELEMENTS->");
    scanf("%d", &n1);
    printf("ELEMENTS-->");
    for (int i = 0; i < n1; i++) {
        scanf("%d", &d);
        insert(&head1, d);
    }

    printf("<-NUMBER OF ELEMENTS->");
    scanf("%d", &n2);
    printf("ELEMENTS-->");
    for (int i = 0; i < n2; i++) {
        scanf("%d", &d);
        insert(&head2,d);
    }
    merge(head1,head2,&head3);
    display(&head3);
    return 0;
}
