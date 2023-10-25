#include <stdio.h>

void main()
{
    int r, c, i, j,k=0, flag = 0;

    printf("Enter number of rows and columns: ");
    scanf("%d %d", &r, &c);

    int a[r][c];

    printf("Enter sparse matrix: \n");
    for (i = 0; i < r; i++)
    {
        for (j = 0; j < c; j++)
        {
            scanf("%d", &a[i][j]);
        }
    }

    for (i = 0; i < r; i++)
    {
        for (j = 0; j < c; j++)
        {
            if (a[i][j] != 0)
            {
                flag++;
            }
        }
    }
    int store[100][3];
    store[0][0] = r;
    store[0][1] = c;
    store[0][2] = flag;
    for(i =0;i<r;i++){
        for(j = 0;j < c;j++){
            if(a[i][j] != 0){
                 store[k+1][0] = i;
                 store[k+1][1] = j;
                 store[k+1][2] = a[i][j];
                k++;          
            }
        }
    }
    printf("Rows\tColumns\tValues\n");
    for(i =0;i<=flag;i++){
        for(j = 0;j < 3;j++){
            printf("%d ",store[i][j]);
            }
            printf("\n");
        }
    float sparsity = 1.0 - (float)((float)flag / (float)(r * c));
    printf("Sparcity of the matrix : %f",sparsity);
    }
