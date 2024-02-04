#include <stdio.h>
int arr[5] = {98,10,45,9,12};
void swap(int *a,int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}
int partition(int arr[],int lb,int ub){
    int pivot =arr[lb],start = lb,end = ub;
    while(start<=end){
        while(start<=end && pivot >= arr[start]){
            start++;}
        while(start<=end && pivot <  arr[end]){
            end--;}
        if(start<end){
            swap(&arr[start],&arr[end]);
        }
    }
    swap(&arr[lb],&arr[end]);
    return end;
}
void quickSort(int arr[],int lb,int ub){
    if(lb<ub){
    int p = partition(arr,lb,ub);
    quickSort(arr,lb,p-1);
    quickSort(arr,p+1,ub);
    }
}
int main() {
    quickSort(arr, 0, 4);

    printf("\nSorted array: ");
    for (int i = 0; i < 5; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}
