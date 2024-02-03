#include <stdio.h>
#define size 13
int hashTable[size] = {0};
void display(int arr[],int n){
    for(int i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
}
void insert(int arr[],int n){
    printf("Enter Elements");
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
}
void hashFunction(int arr[],int n){
    int key;
    for(int i=0;i<n;i++){
        key = arr[i]%size;
        if(hashTable[key]==0){
            hashTable[key] = arr[i];
        }
        else{
            int j = (key+1)%size;
            while(1){
                if(hashTable[j] == 0){
                    hashTable[j] = arr[i];
                    break;
                }
                else{
                    j = (j+1)%size;
                }
            }
        }
    }
}
void main(){
    int n;
    printf("Enter number of Elements : ");
    scanf("%d",&n);
    int arr[n];
    insert(arr,n);
    hashFunction(arr,n);
    display(hashTable,size);
}
