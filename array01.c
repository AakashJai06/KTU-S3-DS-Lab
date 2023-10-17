#include <stdio.h>
void bubbleSort(int a[],int n)
{
	int temp,i,j;
	for(i=0;i<n+1;i++)
	{
		for(j=0;j<n-i-1;j++)
		{
			if(a[j]>a[j+1])
			{
				temp = a[j];
				a[j] = a[j+1];
				a[j+1] = temp;
	 	}
	}
}
for(i=0;i<n;i++)
	printf("%d ",a[i]);
}
void selectionSort(int a[],int n)
{
	int i,j,min,temp;
	for(i=0;i<n-1;i++)
	{
		min =i;
		for(j=i+1;j<n;j++)
			if(a[j]<a[min])
			{
				temp = a[j];
				a[j] = a[min];
				a[min] = temp;
	}
}
for(i=0;i<n;i++)
	printf("%d ",a[i]);
}
void linearSearch(int a[],int n)
{
	int i,n0,flag=0;
	printf("Enter the Number to be searched : ");
	scanf("%d",&n0);
	for(i=0;i<n;i++)
		{
			if(a[i] == n0)
			{
			flag = 1;
			break;
		}
	}
	if(flag == 1)
		printf("%d is present in the array .",n0);
	else 
		printf("%d is not present in the array .",n0);
}
void binarySearch(int a[],int n)
{
	int i,n0;
	printf("Enter the Number to be searched : ");
	scanf("%d",&n0);
	int first =0,last =n-1,mid = (first+last)/2,flag=0;	
	while(last >= first)	
	{
			if(a[mid] == n0)
		{
			flag =1;
			break;
		}
		else if(a[mid]>n0)
		{
				last = mid-1;
				mid = (first+last)/2;
		}
		else
			{
				first = mid+1;
				mid = (first+last)/2;
	}
}
if(flag == 1)
		printf("%d is present in the array at position %d.",n0,mid);
else
		printf("%d is not present in the array .",n0);
	}

void main()
{
	int ch,n;
	printf("Enter array size : ");
	scanf("%d",&n);
	int a[n];
	printf("Enter the elements : ");
	for(int i=0;i<n;i++)
		scanf("%d",&a[i]);
		printf("1. Bubble Sort \n");
		printf("2. Selection Sort \n");
		printf("3. Linear Search \n");
		printf("4. Binary Search \n");
		printf("Enter your choice : ");
		scanf("%d",&ch);
		switch (ch) {
			case 1 : 
				bubbleSort(a,n);
				break;
			case 2: 
				selectionSort(a,n);
				break;
			case 3: 
				linearSearch(a,n);
				break;
			case 4: 
				binarySearch(a,n);
				break;
}
}
