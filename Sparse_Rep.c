#include <stdio.h>
void main()
{
	int r,c,flag=0;
	printf("Enter number of rows and columns : ");
	scanf("%d %d",&r,&c);
	int a[r][c];
	for(int i=0;i<r;i++)
	{
	for(int j=0;j<c;j++)
	{
		scanf("%d",&a[i][j]);
	}
	}
	printf("Row\tColumn\tValue\n");
	int store[100][3];
	for(int i=0;i<r;i++)
	{
	for(int j=0;j<c;j++)
	{
		if(a[i][j]!=0)
		{
		store[flag+1][0] = i;
		store[flag+1][1] = j;
		store[flag+1][2] = a[i][j];
		flag++;
		}
	}
	}
	store[0][0] = r;
	store[0][1] = c;
	store[0][2] = flag;
	for(int i=0;i<flag+1;i++)
	{
	for(int j=0;j<3;j++)
	{
		printf("%d\t",store[i][j]);
	}
	printf("\n");
	}
	float sparcity = (float)(((float)(r*c-flag))/((float)(r*c)));
	printf("\nSparcity : %f",sparcity);
}
