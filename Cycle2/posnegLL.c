#include <stdio.h>
#include <stdlib.h>
struct node{
    int data;
    struct node* next;
}*head1=NULL,*newNode,*temp;
struct node* create(int data){
    newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data =data;
    newNode->next = NULL;
    return newNode;
}
void insert(struct node **head,int d){
    newNode = create(d);
    if(*head == NULL){
        *head = newNode;
    }
    else{
        temp = *head;
        while(temp->next!=NULL){
            temp = temp->next;
        }
        temp->next = newNode;
    }
}
void check(struct node **head1, struct node **head2, struct node **head3) {
    while (*head1 != NULL) {
        if ((*head1)->data > 0) {
            insert(head2, (*head1)->data);
        } else if ((*head1)->data < 0) {
            insert(head3, (*head1)->data);
        }
        *head1 = (*head1)->next;
    }
}


void display(struct node **head){
    temp = *head;
    while(temp!=NULL){
        printf("%d ",temp->data);
        temp = temp->next;
    }
}
void main(){
    int ch=0,d;
    do{
        printf("\n1)Insert\n2)Display\n3)Exit");
        scanf("%d",&ch);
        switch(ch){
            case 1:
                    printf("Enter Elements : ");
                    scanf("%d",&d);
                    insert(&head1,d);
                    display(&head1);
                    break;
                    
            case 2:
                    struct node * head2 = NULL,*head3=NULL;
                    check(&head1,&head2,&head3);
                    printf("\nLinked List : ");
                    display(&head1);
                    printf("\nPositive List : ");
                    display(&head2);
                    printf("\nNegative List : ");
                    display(&head3);
        }
    }while(ch!=3);
}
