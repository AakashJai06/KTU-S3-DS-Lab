#include <stdio.h>
void main()
{
	int a[100][3],b[100][3],c[100][3],n0,n1,k=0;
	printf("Enter number of non-zero elements in the matrixes : ");
	scanf("%d %d",&n0,&n1);
	printf("Enter Sparse Representation of 1st matrix : ");
	for(int i=0;i<n0;i++)
	{
	for(int j=0;j<3;j++)
	{
	scanf("%d",&a[i][j]);
	}
	}
	printf("Enter Sparse Representation of 2nd matrix : ");
	for(int i=0;i<n1;i++)
	{
	for(int j=0;j<3;j++)
	{
	scanf("%d",&b[i][j]);
	}
	}
	printf("\nRow\tColumn\tValue\n");
	for(int i=0;i<n0;i++)
	{
	for(int j=0;j<3;j++)
	{
	printf("%d\t",a[i][j]);
	}
	printf("\n");
	}
	printf("\nRow\tColumn\tValue\n");
	for(int i=0;i<n1;i++)
	{
	for(int j=0;j<3;j++)
	{
	printf("%d\t",b[i][j]);
	}
	printf("\n");
	} 
	for(int i=0;i<n0;i++)
	{
	for(int j=0;j<3;j++)
	{
	if(a[k][0] == b[k][0])
	{
	if(a[k][1] == b[k][1])
	{
		c[k][0] = k;
		c[k][1] = j;
		c[k][2] = a[k][2]+b[k][2];
		}
		else if(a[k][1] < b[k][1])
		{
		c[k][0] = k;
		c[k][1] = j;
		c[k][2] = a[k][2];
		}
		else
		{
		c[k][0] = k;
		c[k][1] = j;
		c[k][2] = b[k][2];
		}
	}
	k++;
	}
	}
	printf("\nRow\tColumn\tValue\n");
	for(int i=0;i<n0;i++)
	{
	for(int j=0;j<3;j++)
	{
	printf("%d\t",c[i][j]);
	}
	printf("\n");
	}
}
