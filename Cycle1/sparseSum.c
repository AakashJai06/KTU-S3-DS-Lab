#include <stdio.h>
void main() {
    int a[100][3], b[100][3], c[100][3], n0, n1;

    printf("Enter the number of non-zero elements in the matrices: ");
    scanf("%d %d", &n0, &n1);

    printf("Enter Sparse Representation of the 1st matrix:\n");
    for (int i = 0; i < n0; i++) {
        for (int j = 0; j < 3; j++) {
            scanf("%d", &a[i][j]);
        }
    }

    printf("Enter Sparse Representation of the 2nd matrix:\n");
    for (int i = 0; i < n1; i++) {
        for (int j = 0; j < 3; j++) {
            scanf("%d", &b[i][j]);
        }
    }

    printf("\nRow\tColumn\tValue\n");
    for (int i = 0; i < n0; i++) {
        for (int j = 0; j < 3; j++) {
            printf("%d\t", a[i][j]);
        }
        printf("\n");
    }

    printf("\nRow\tColumn\tValue\n");
    for (int i = 0; i < n1; i++) {
        for (int j = 0; j < 3; j++) {
            printf("%d\t", b[i][j]);
        }
        printf("\n");
    }

    int i = 0, j = 0, k = 0;

    while (i < n0 && j < n1) {
        if (a[i][0] < b[j][0] || (a[i][0] == b[j][0] && a[i][1] < b[j][1])) {
            c[k][0] = a[i][0];
            c[k][1] = a[i][1];
            c[k][2] = a[i][2];
            i++;
        } else if (a[i][0] > b[j][0] || (a[i][0] == b[j][0] && a[i][1] > b[j][1])) {
            c[k][0] = b[j][0];
            c[k][1] = b[j][1];
            c[k][2] = b[j][2];
            j++;
        } else {
            c[k][0] = a[i][0];
            c[k][1] = a[i][1];
            c[k][2] = a[i][2] + b[j][2];
            i++;
            j++;
        }

        k++;
    }
    while (i < n0) {
        c[k][0] = a[i][0];
        c[k][1] = a[i][1];
        c[k][2] = a[i][2];
        i++;
        k++;
    }

    while (j < n1) {
        c[k][0] = b[j][0];
        c[k][1] = b[j][1];
        c[k][2] = b[j][2];
        j++;
        k++;
    }

    printf("\nRow\tColumn\tValue\n");
    for (int i = 0; i < k; i++) {
        for (int j = 0; j < 3; j++) {
            printf("%d\t", c[i][j]);
        }
        printf("\n");
    }
}
