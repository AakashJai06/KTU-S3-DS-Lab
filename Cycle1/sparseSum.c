#include <stdio.h>
struct tuple{
    int row;
    int col;
    int val;
}sparse1[50],sparse2[50],sparse3[100];
int k=0;
void insert(struct tuple sparse[50],int n){
    printf("<--Elements in tuple form-->\n");
    for(int i=0;i<n;i++){
        scanf("%d %d %d",&sparse[i].row,&sparse[i].col,&sparse[i].val);
    }
}
void display(struct tuple sparse[50],int n){
    for(int i=0;i<n;i++)
    {
        printf("%5d%5d%5d\n",sparse[i].row,sparse[i].col,sparse[i].val);
    }
}
void add(struct tuple sparse1[50],struct tuple sparse2[50],struct tuple sparse3[100],int n1,int n2){
    int i=0,j=0;
    while(i<n1 && j<n2){
        if(sparse1[i].row == sparse2[j].row && sparse1[i].col == sparse2[i].col){
            sparse3[k].row = sparse1[i].row;
            sparse3[k].col = sparse1[i].col;
            sparse3[k].val = sparse1[i].val+sparse2[j].val;
            i++;j++;k++;
        }
        else if(sparse1[i].row <sparse2[j].row || sparse1[i].row == sparse2[j].row && sparse1[i].col<sparse2[j].col ){
            sparse3[k].row = sparse1[i].row;
            sparse3[k].col = sparse1[i].col;
            sparse3[k].val = sparse1[i].val;
            i++;k++;
        }
        else{
            sparse3[k].row = sparse2[j].row;
            sparse3[k].col = sparse2[j].col;
            sparse3[k].val = sparse2[j].val;
            j++;k++;
        }
    }
    while(i<n1){
            sparse3[k].row = sparse1[i].row;
            sparse3[k].col = sparse1[i].col;
            sparse3[k].val = sparse1[i].val;
            i++;k++;
    }
    while(j<n2){
            sparse3[k].row = sparse2[j].row;
            sparse3[k].col = sparse2[j].col;
            sparse3[k].val = sparse2[j].val;
            j++;k++;
    }
}
void main(){
    int n1,n2;
    printf("<-Enter Number of non zero elements->");
    scanf("%d",&n1);
    insert(sparse1,n1);
    printf("<-Enter Number of non zero elements->");
    scanf("%d",&n2);
    insert(sparse2,n2);
    add(sparse1,sparse2,sparse3,n1,n2);
    display(sparse3,k);
}
