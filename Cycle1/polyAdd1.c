#include <stdio.h>
int max(int n,int m)
{
	if(n>m)
		return n;
	else
		return m;
}
void main()
{
	int n,m;
	printf("Enter number of elements in 1st and 2nd polynomial : ");
	scanf("%d %d",&n,&m);
	struct polyAdd
	{
		int coef;
		int power;
	}a[max(n,m)],b[max(n,m)],c[(n+m)];
	for(int i = max(n,m);i>=0;i--)
	{
		a[i].coef=0;
		b[i].coef=0;
	}
	for(int i=n;i>=0;i--)
	{
		printf("Enter the power and coeff in the first polynomial : ");
		scanf("%d %d",&a[i].power,&a[i].coef);
	}
	for(int i=m;i>=0;i--)
	{
		printf("Enter the power and coeff in the second polynomial : ");
		scanf("%d %d",&b[i].power,&b[i].coef);
		}
	for(int i=max(n,m);i>=0;i--)
		 if(a[                                          ])
	printf("First Polynominal  : ");
	for(int i=n;i>=0;i--)
	{
		if(i<n)
		printf("+");
		printf("%dx^%d ",a[i].coef,i);
	}
	printf("\nSecond Polynominal : ");
	for(int i=m;i>=0;i--)
	{
		if(i<m)
		printf("+");
		printf("%dx^%d ",b[i].coef,i);
	}
	printf("\nAdded Polynominal  : ");
	for(int i=max(n,m);i>=0;i--)
	{
		if(i<max(n,m))
		printf("+");
		printf("%dx^%d ",c[i].coef,i);
}
}

