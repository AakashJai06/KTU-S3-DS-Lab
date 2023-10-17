#include <stdio.h>
struct student
{
	int roll;
	int sub1;
	int sub2;
	int sub3;
	int sub4;
	int sub5;
	int total;
}a[50],temp;
void main()
{
	int n;
	printf("Enter number of students : ");
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		printf("Enter the roll number : ");
		scanf("%d",&a[i].roll);
		printf("Enter the marks : ");
		scanf("%d",&a[i].sub1);
		scanf("%d",&a[i].sub2);
		scanf("%d",&a[i].sub3);
		scanf("%d",&a[i].sub4);
		scanf("%d",&a[i].sub5);
		a[i].total = a[i].sub1+a[i].sub2+a[i].sub3+a[i].sub4+a[i].sub5;
	}
	for(int i=0;i<n-1;i++)
	{
		for(int j=0;j<n-i-1;j++)
		{
			if(a[j].total<a[j+1].total)
			{
				temp = a[j];
				a[j] = a[j+1];
				a[j+1] = temp;
			}
		}
	}
	printf("Rank list :  \n ");
	printf("Roll no. \t marks\n");
	for(int i=0;i<n;i++)
	{
		printf("%d \t %d \n",a[i].roll,a[i].total);
	}
}
