#include <stdio.h>
struct poly{
    int coef;
    int po;
};
struct poly p1[10],p2[10],p3[20];
int i,j,k,n1,n2;
void create(struct poly p[10],int n){
    for(i=0;i<n;i++){
        printf("Coef and pow of %d element.....",i+1);
        scanf("%d %d",&p[i].coef,&p[i].po);
    }
}
void add(struct poly p1[10],struct poly p2[10]){
    i=0,j=0,k=0;
    while (i < n1 && j < n2) {
        if (p1[i].po == p2[j].po) {
            p3[k].coef = p1[i].coef + p2[j].coef;
            p3[k].po = p1[i].po;
            k++; i++; j++;
        } else if (p1[i].po > p2[j].po) {
            p3[k].coef = p1[i].coef;
            p3[k].po = p1[i].po;
            i++; k++;
        } else {
            p3[k].coef = p2[j].coef;
            p3[k].po = p2[j].po;
            j++; k++;
        }
    }

    while (i < n1) {
        p3[k].coef = p1[i].coef;
        p3[k].po = p1[i].po;
        i++; k++;
    }

    while (j < n2) {
        p3[k].coef = p2[j].coef;
        p3[k].po = p2[j].po;
        j++; k++;
    }
}
void display(){
    printf("<--First Polynominal-->\n");
    for (int i = 0; i < n1; i++) {
        if (i < n1 - 1) {
            printf("%dx^%d + ", p1[i].coef, p1[i].po);
        } else {
            printf("%dx^%d\n", p1[i].coef, p1[i].po);
        }
    }

    printf("<--Second Polynomial-->\n");
    for (int i = 0; i < n2; i++) {
        if (i < n2 - 1) {
            printf("%dx^%d + ", p2[i].coef, p2[i].po);
        } else {
            printf("%dx^%d\n", p2[i].coef, p2[i].po);
        }
    }

    printf("<--Resultant Polynomial-->\n");
    for (int x = 0; x < k; x++) {
        if (x < k - 1) {
            printf("%dx^%d + ", p3[x].coef, p3[x].po);
        } else {
            printf("%dx^%d\n", p3[x].coef, p3[x].po);
        }
    }
}
void main(){
    printf("<--Number of Elements-->");
    scanf("%d",&n1);
    create(p1,n1);
    printf("<--Number of Elements-->");
    scanf("%d",&n2);
    create(p2,n2);
    add(p1,p2);
    display();
}
