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
	printf("Enter the order of the 1st and 2nd polynomial : ");
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
		printf("Enter the coeff of x^%d in the first polynomial : ",i);
		scanf("%d",&a[i].coef);
	}
	for(int i=m;i>=0;i--)
	{
		printf("Enter the coeff of x^%d in the second polynomial : ",i);
		scanf("%d",&b[i].coef);
	}
	for(int i=max(n,m);i>=0;i--)
		 c[i].coef = a[i].coef+b[i].coef;
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

