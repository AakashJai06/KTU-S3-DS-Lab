#include <stdio.h>
#include <stdlib.h>
struct node{
    int data;
    struct node* next;
}*newNode,*head=NULL,*temp=NULL,*prev=NULL,*ptr1,*ptr2,*dlt=NULL;
struct node* create(int d){
    newNode = (struct node*)malloc(sizeof(struct node));
    newNode->next = NULL;
    newNode->data = d;
    return newNode;
}
void insert(int d){
   newNode = create(d);
	if(head == NULL){
		head = newNode;
	}
	else{
	    temp = head;
		while(temp->next!=NULL)
			{
				temp = temp->next;
			} 
			temp->next = newNode;
	}
}
void delete(struct node **head,struct node *dltNode){
    temp = *head;
    if(temp == dltNode){
        *head = (*head)->next;
        free(temp);
    }
    else{
        while(temp!=dltNode){
           prev = temp;
           temp = temp->next;
        }
        prev->next = temp->next;
        free(temp);
    }
}

void modify(struct node **head) {
    ptr1 = *head;
    while (ptr1 != NULL) {
        ptr2 = ptr1->next;
        while (ptr2 != NULL) {
            if (ptr1->data == ptr2->data) {
                dlt = ptr2;
                ptr2 = ptr2->next; 
                delete(head, dlt); 
            } else {
                ptr2 = ptr2->next;
            }
        }
        ptr1 = ptr1->next;
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
	printf("\n");
}

void main() {
    int ch=0,d;
    do{
        printf("\n1)Insert\n2)modify\n3)Exit\n");
        scanf("%d",&ch);
        switch(ch){
        case 1:
                printf("value--> ");
                scanf("%d",&d);
                insert(d);
                display();
                break;
        case 2: 
                modify(&head);
                display();
                break;
               
    }
    }while(ch!=3);
}
