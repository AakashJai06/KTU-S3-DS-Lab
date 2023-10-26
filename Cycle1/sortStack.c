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
void sort()
{
int temp;
	if(top != 0)
	{
	for(int i=0;i<top;i++)
	{
	if(a[i] > a[i+1])
	{
	temp = a[i];
	a[i] = a[i+1];
	a[i+1] = temp;
	}
	}
	}
}
	void display()
	{
		sort();
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
		while(ch != 3){
			printf("Choose : \n");
			printf("\t1) Push\n\t2) Display\n\t3) Exit");
			scanf("%d",&ch);
			switch(ch){
			case 1:
				printf("Data : ");
				scanf("%d",&data);
				push(data);
				break;
			case 2:
				display();
				break;
		}
	}
}
