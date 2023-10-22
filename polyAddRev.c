#include <stdio.h>

struct poly
{
    int pow;
    int coef;
};

int main()
{
    int n1, n2, i, j, k, count = 0;
    printf("Enter the number of elements in 1st poly :  ");
    scanf("%d", &n1);
    printf("Enter the number of elements in 2nd poly :  ");
    scanf("%d", &n2);
    struct poly p1[n1], p2[n2], p3[n1 + n2];

    for (i = n1 - 1; i >= 0; i--)
    {
        printf("Enter the power and coef of 1st poly : ");
        scanf("%d %d", &p1[i].pow, &p1[i].coef);
    }
    for (i = n2 - 1; i >= 0; i--)
    {
        printf("Enter the power and coef of 2nd poly : ");
        scanf("%d %d", &p2[i].pow, &p2[i].coef);
    }
    i = 0;
    j = 0;
    k = 0;
    while (i < n1 && j < n2)
    {
        if (p1[i].pow == p2[j].pow)
        {
            p3[k].coef = p1[i].coef + p2[j].coef;
            p3[k].pow = p1[i].pow;
            k++;
            i++;
            j++;
            count++;
        }
        else if (p1[i].pow < p2[j].pow)
        {
            p3[k].coef = p1[i].coef;
            p3[k].pow = p1[i].pow;
            i++;
            k++;
            count++;
        }
        else
        {
            p3[k].coef = p2[j].coef;
            p3[k].pow = p2[j].pow;
            j++;
            k++;
            count++;
        }
    }

    for (i = 0; i < k; i++)
    {
        if (i != 0)
            printf(" +");
        printf(" %dX^%d", p3[i].coef, p3[i].pow);
    }
    printf("\n");
    return 0;
}
