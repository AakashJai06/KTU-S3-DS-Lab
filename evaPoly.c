#include <stdio.h>
int power(int x,int i)
{
int val =1;
while(i>0)
{
val *= x;
i--; 
}
return val;
}
void main()
{
int n,x,sum=0;
printf("Enter the order of the polynomial : ");
scanf("%d",&n);
printf("Enter the value of x : ");
scanf("%d",&x);
struct poly
{
int coef;
}a[n];
for(int i=n;i>=0;i--)
	{
		printf("Enter the coeff of x^%d in the polynomial : ",i);
		scanf("%d",&a[i].coef);
	}
for(int i=n;i>0;i--)
{
sum += a[i].coef*power(x,i);
}
sum += a[0].coef;
printf("Polynominal  : ");
	for(int i=n;i>=0;i--)
	{
		if(i<n)
		printf("+");
		printf("%dx^%d ",a[i].coef,i);
	}
printf("\nSum : %d",sum);
}
