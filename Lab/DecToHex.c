#include <stdio.h>
#define size 100
int stack[size] ;
int top=-1;
void push(int d){
    if(top == size-1){
        return;
    }
    else{
        stack[++top] = d;
    }
}

void main(){
    int d,rem;
    printf("Enter : ");
    scanf("%d",&d);
    while(d>0){
        rem  = d%16;
        push(rem);
        d = d/16;
    }
    while(top !=-1){
        if(stack[top]<10){
            printf("%d",stack[top--]);
        }
        else{
            printf("%c",(char)(stack[top--]+55));
                        
            }
        }
    }
