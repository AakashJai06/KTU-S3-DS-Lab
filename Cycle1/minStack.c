#include <stdio.h>
#define max 100
int a[max],min[max],top = -1;
	void push(int data)
	{
		if(top == max-1)
		printf("Overflow \n");
		else if(top == -1 || data < min[0]){ 
			a[++top] = data;
			min[0] = data;
		}
		else
			a[++top] = data;
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
	printf("\nMin Stack : %d.\n",min[0]);		
}
	void main()
	{
		int ch=0,data;
		while(ch != 3){
			printf("Choose : \n");
			printf("\t1) Push\n\t2) Display\n\t3)Exit\n\t");
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
