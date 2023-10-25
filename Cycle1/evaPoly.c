#include <stdio.h>
struct poly
{
    int pow;
    int coef;
};
int power(int x,int p)
{
    int va =1;
    while(p>0)
    {
        va *= x;
        p--;
    }
    return va;
}
void main()
{
    int n,i,x,val=0;
    printf("Enter the number of elements in poly : ");
    scanf("%d",&n);
    struct poly p[n];
    for(i = n;i>0;i--)
    {
        printf("Enter the power : ");
        scanf("%d",&p[i].pow);
        printf("Enter the coef of %d power : ",p[i].pow);
        scanf("%d",&p[i].coef);
    }
    printf("Enter the value of x : ");
    scanf("%d",&x);
    for(i =n ; i>0;i--)
    {
        val += p[i].coef*(power(x,p[i].pow));
    }
    printf("%d",val);
}
