#include <stdio.h>
#include <stdlib.h>
struct poly{
    int coef;
    int po;
    struct poly* next;
}p1[20],p2[20],p3[40];
int k=0;
void insert(struct poly p[20],int n){
    for(int i=0;i<n;i++){
    printf("<-Coef and power of %d element->",i);
    scanf("%d %d",&p[i].coef,&p[i].po);
    }
}
void multiply(int n1,int n2){
     for (int i = 0; i < n1; i++) {
        for (int j = 0; j < n2; j++) {
            int flag =0;
            for (int l = 0; l < k; l++) {
                if (p3[l].po == p1[i].po + p2[j].po) {
                    p3[l].coef += (p1[i].coef * p2[j].coef);
                    flag =1;
                    break;
                }
            }
            if(flag == 0){
                    p3[k].coef = p1[i].coef * p2[j].coef;
                    p3[k].po = p1[i].po + p2[j].po;
                    k++;
                }
        }
    }
}
void display(struct poly p[20],int n){
    for(int i=0;i<n;i++)
        printf("%dX^%d ",p[i].coef,p[i].po);
    printf("\n");
}
void main(){
    int n1,n2;
    printf("<-Number of elements in 1st Poly->");
    scanf("%d",&n1);
    insert(p1,n1);
    display(p1,n1);
    printf("<-Number of elements in 2nd Poly->");
    scanf("%d",&n2);
    insert(p2,n2);
    display(p2,n2);
    multiply(n1,n2);
    display(p3,k);
}
