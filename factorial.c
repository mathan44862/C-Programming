#include<stdio.h>
int factorial(int fact){
    if(fact == 0){
        return 1;
    }
    return fact*factorial(fact-1);
}
void main(){
    int fact;
    printf("Enter the factorial number");
    scanf("%d",&fact);
    printf("%d",factorial(fact));
}
