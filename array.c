#include <stdio.h>
void insert(int a[], int n)
{
	int n1;
	printf("Enter the element to be inserted : ");
	scanf("%d",&n1);
	a[n]=n1;
	for(int i=0;i<n+1;i++)
		printf("%d ",a[i]);
}
void delete(int a[],int n)
{
	int n1;
	printf("Enter the position of the element to be deleted : ");
	scanf("%d",&n1);
	a[n1-1] = 0;  
	for(int i=0;i<n;i++)
		printf("%d ",a[i]);
}
void search(int a[],int n)
{
	int n1,flag=0;
	printf("Enter the element to be searched : ");
	scanf("%d",&n1);
	for(int i=0;i<n;i++)
	{
		if(a[i]==n1)
		{
			flag =1;
			break;
		}	
	}
	if(flag == 1)
		printf("The element %d is present in the array ",n1);
	else
		printf("The element %d is not present in the array ",n1);
}
void main()
{
	int a[50],n,ch;
	printf("Enter the length : ");
	scanf("%d",&n);
	printf("Enter the elements : ");
	for(int i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	printf("Enter the choice : \n 1) For insertion \n 2) For Deletion \n 3) For searching \n");
	scanf("%d",&ch);
	if(ch == 1)
		insert(a,n);
	else if(ch == 2)
		delete(a,n);
	else 
		search(a,n);	
}

