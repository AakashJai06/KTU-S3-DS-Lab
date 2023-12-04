#include <stdio.h>
struct tuple{
    int row;
    int col;
    int val;
}sparseMat[50],transMat[50];
void sparseRep(int a[][50],int r,int c){
    int k=1;
    sparseMat[0].row = r;
    sparseMat[0].col = c;
    for(int i=0;i<r;i++){
        for(int j = 0;j<c;j++){
            if(a[i][j]!=0){
                sparseMat[k].row = i;
                sparseMat[k].col = j;
                sparseMat[k].val = a[i][j];
                k++;
            }
        }
    }
    sparseMat[0].val = k-1;
}
void transpose(){
    transMat[0].row = sparseMat[0].col;
    transMat[0].col = sparseMat[0].row;
    transMat[0].val = sparseMat[0].val;
    int k = 1;
    for (int i=0; i<=sparseMat[0].col; i++){
        for (int j=1; j<=sparseMat[0].val; j++){
            if (sparseMat[j].col == i){
                transMat[k].row = sparseMat[j].col;
                transMat[k].col = sparseMat[j].row;
                transMat[k].val = sparseMat[j].val;
                k++;
        }
    }
}
}
void display(struct tuple* sparseMat){
     int k = 0;
     while (k!=sparseMat[0].val+1){
        printf("%5d%5d%5d\n",sparseMat[k].row, sparseMat[k].col, sparseMat[k].val);
        k++;
    }
}
void main(){
    int r,c,a[50][50];
    printf("<--Rows and Columns-->");
    scanf("%d %d",&r,&c);
    printf("<--Elements-->\n");
    for(int i=0;i<r;i++){
        for(int j = 0;j<c;j++){
            scanf("%d",&a[i][j]);
        }
    }
    sparseRep(a,r,c);
    display(sparseMat);
    transpose();
    display(transMat);
}
