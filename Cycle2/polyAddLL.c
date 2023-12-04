#include <stdio.h>
#include <stdlib.h>
struct node{
    int coef;
    int po;
    struct node* next;
}*newNode,*temp,*head1=NULL,*head2=NULL,*head3 = NULL;
struct node * create(int c,int p){
    newNode = (struct node *)malloc(sizeof(struct node));
    newNode->next = NULL;
    newNode->coef = c;
    newNode->po = p;
    return newNode;
}
void insert(int c,int p,struct node** head){
    newNode = create(c,p);
    if(*head == NULL){
        *head = newNode;
    }
    else{
        temp = *head;
        while(temp->next != NULL){
            temp = temp->next;
        }
        temp->next = newNode;
    }
}
void add(struct node* head1,struct node* head2, struct node** head3){
    struct node* ptr1 = head1;
    struct node* ptr2 = head2;
    while(ptr1!=NULL && ptr2!=NULL){
        if(ptr1->po == ptr2->po){
            insert(ptr1->coef+ptr1->coef,ptr1->po,head3);
            ptr1 = ptr1->next;
            ptr2 = ptr2->next;
        }
        else if(ptr1->po>ptr2->po){
            insert(ptr1->coef,ptr1->po,head3);
            ptr1 = ptr1->next;
        }
        else{
            insert(ptr2->coef,ptr2->po,head3);
            ptr2 = ptr2->next;
        }
    }
    while(ptr1!=NULL){
         insert(ptr1->coef,ptr1->po,head3);
            ptr1 = ptr1->next;
    }
    while(ptr2!=NULL){
        insert(ptr2->coef,ptr2->po,head3);
            ptr2 = ptr2->next;
    }
}
void display(struct node* head){
    temp = head;
	if(head ==  NULL){
		printf("Poly is Empty!!!");
	}
	else{
		while(temp!=NULL){
			printf("%dX^%d ",temp->coef,temp->po);
			temp = temp->next;
		}
	}
	printf("\n");
}
void main(){
    int n1,n2,c1,c2,p1,p2;
    printf("<--Number of elements-->");
    scanf("%d",&n1);
    for(int i=n1;i>0;i--){
        printf("<-Coef and pow in %d element of 1st poly->",i);
        scanf("%d %d",&c1,&p1);
        insert(c1,p1,&head1);
    }
    printf("<--Number of elements-->");
    scanf("%d",&n2);
    for(int i=n2;i>0;i--){
        printf("<-Coef and pow in %d element of 2nd poly->",i);
        scanf("%d %d",&c2,&p2);
        insert(c2,p2,&head2);
    }
    add(head1,head2,&head3);
    display(head1);
    display(head2);
    display(head3);
}
