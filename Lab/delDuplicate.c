#include <stdio.h>
#include <stdlib.h>

struct node{
    struct node *next;
    int data;
}*newNode,*head=NULL,*temp=NULL,*current=NULL,*prev=NULL,*nextNode=NULL;

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
        while(temp->next!=NULL){
            temp = temp->next;
        }
        temp->next = newNode;
    }
}
void dltDul(){
    temp = head;
    while(temp!=NULL && temp->next!=NULL){
        if(temp->data == temp->next->data){
            struct node* duplicate = temp->next;
            temp->next = temp->next->next;
            free(duplicate);
        }
        else{
            temp = temp->next;
        }
    }
}
void display(){
    temp = head;
    while(temp!=NULL){
        printf("%d ",temp->data);
        temp = temp->next;
    }
}
void main(){
    int ch=0,d;
    do{
        scanf("%d",&ch);
        switch(ch){
            case 1: scanf("%d",&d);
                    insert(d);
                    display();
                    break;
            case 2: 
                    dltDul();
                    display();
                    break;
        }
    }while(ch!=3);
}
