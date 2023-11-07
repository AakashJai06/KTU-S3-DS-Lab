#include <stdio.h>
#define max_size 100
int q[max_size];
int rear=-1;
int front=-1;
void enqueue(int item)
{
		if(rear == max_size-1)
			printf("The stack is full.");
		else if(front == -1 && rear == -1){
			front = 0;
			q[++rear] = item;
		}
		else 
			q[++rear] = item;
}
void dequeue()
{
int item;
if(front == -1)
	printf("The Queue is empty");
else if(front == rear){
	item = q[front];
	front = rear = -1;
}
else{
item = q[front++];
}
printf("\nDeleted item : %d.",item);
}
void display()
{
for (int i = front; i <= rear; i += 1)
{
	printf("%d ",q[i]);
}
}
void main()
{
	int ch=0,item;
	do{
		printf("Select the choice......");
		printf("\n1)Enqueue\n2)Dequeue\n3)Display Queue\n4)Exit\n");
		scanf("%d",&ch);
		switch(ch){
			case 1: 
							printf("Enter value to be added...");
							scanf("%d",&item);
							enqueue(item);
							break;
			case 2:
							dequeue();
							break;
			case 3:
							display();
							break;
		}
	}while(ch!=4);
 }

