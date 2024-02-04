#include <stdio.h>
int arr[5] = {23,1,4,67,45};
void merge(int arr[],int lb,int ub,int mid){
    int Lsize = mid-lb+1;
    int Rsize = ub-mid;
    int Larr[Lsize],Rarr[Rsize];
    for(int i=0;i<Lsize;i++){
        Larr[i] = arr[i+lb];
    }
    for(int i=0;i<Rsize;i++){
        Rarr[i] = arr[mid+i+1];
    }
    int i=0,j=0,k=lb;
    while(i<Lsize && j<Rsize){
        if(Larr[i] < Rarr[j]){
            arr[k++] = Larr[i++];
        }
        else{
            arr[k++] = Rarr[j++];
        }
    }
    while(i<Lsize){
        arr[k++] = Larr[i++];
    }
    while(j<Rsize){
        arr[k++] = Rarr[j++];
    }
}
void mergeSort(int arr[],int lb,int ub){
    if(lb<ub){
        int mid = (lb+ub)/2;
        mergeSort(arr,lb,mid);
        mergeSort(arr,mid+1,ub);
        merge(arr,lb,ub,mid);
    }
}
void main(){
    mergeSort(arr,0,4);
    for(int i=0;i<5;i++){
        printf("%d ",arr[i]);
    }
}
