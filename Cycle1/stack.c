#include <stdio.h>
#define max 100
int a[max],top = -1;
	void push(int data)
	{
		if(top == max-1)
		printf("Overflow \n");
		else 
		a[++top] = data;

	}
	void pop()
	{
		int item;
		if(top == -1)
		printf("Stack empty \n");
		else{
		item = a[top--];
		printf("Deleted item : %d\n",item);
		}
	}
	void peek()
	{
		if(top != -1)
			printf("Value at the top is %d.\n",a[top]);
		else
			printf("Stack Empty\n");
	}
	void display()
	{
		printf("Stack : \n");
			for(int i=0;i<=top;i++){
		if(i == 0)
			printf("[%d,",a[i]);
		else if(i != top)
			printf("%d,",a[i]);
		else
			printf("%d]",a[i]);
		}
			printf("\n");
	}
	void main()
	{
		int ch=0,data;
		while(ch != 5){
			printf("Choose : \n");
			printf("\t1) Push\n\t2) Pop\n\t3) Peek\n\t4) Display\n\t5) Exit");
			scanf("%d",&ch);
			switch(ch){
			case 1:
				printf("Data : ");
				scanf("%d",&data);
				push(data);
				break;
			case 2:
				pop();
				break;
			case 3:
				peek();
				break;
			case 4: 
				display();
				break;
		}
	}
}
