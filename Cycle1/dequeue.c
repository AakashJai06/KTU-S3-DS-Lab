#include <stdio.h>
#include <stdbool.h>
#define size 30
int deq[size];
int front =-1,rear = -1;
bool isEmpty(){
    return front == -1 && rear == -1;
}
bool isFull(){
    return front == (rear+1)%size;
}
void insertAtRear(int d){
    if(isFull()){
        printf("FULL");
    }
    else{
        if(isEmpty())
            front = rear =0;
        else
            rear = (rear+1)%size;
        deq[rear] = d;
    }
}
void deleteAtFront(){
    if(isEmpty())
        printf("Empty");
    else{
        if(front == rear)
            front = rear =-1;
        else
            front = (front+1)%size;
    }
}
void insertAtFront(int d){
    if(isFull()){
        printf("FULL");
    }
    else{
        if(isEmpty())
            front = rear = 0;
        else    
            front = (front+size-1)%size;
        deq[front] = d;
    }
}
void deleteAtRear(){
    if(isEmpty())
        printf("Empty");
    else{
        if(front == rear)
            front = rear =-1;
        else
            rear = (rear+size-1)%size;
    }
}
void display() {
    if (isEmpty()) {
        printf("Deque is empty\n");
    } else {
        int i = front;
        do {
            printf("%d ", deq[i]);
            i = (i + 1) % size;
        } while (i != (rear + 1) % size);
    }
}
int main()
{
    int ch, element, del;
    do
    {
        printf("\n\nChoose operation");
        printf("\n1.Enqueue at front");
        printf("\n2.Enqueue at rear");
        printf("\n3.Dequeue at front");
        printf("\n4.Dequeue at rear");
        printf("\n5.Display queue");
        printf("\n6.Exit\n");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            printf("\nEnter element to insert ");
            scanf("%d", &element);
            insertAtFront(element);
            display();
            break;
        case 2:
            printf("\nEnter element to insert ");
            scanf("%d", &element);
            insertAtRear(element);
            display();
            break;
        case 3:
            deleteAtFront();
            display();
            break;
        case 4:
            deleteAtRear();
            display();
            break;
        case 5:
            display();
            break;
        }
    } while (ch < 6);
    
    return 0;
}
