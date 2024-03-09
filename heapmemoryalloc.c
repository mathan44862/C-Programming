//create a function to alloc 4 bytes in heap and store value 10 in the alloc heap memory
#include<stdio.h>
void* allocatememoryinheap(int size){
    void *ptr = malloc(size);
    printf("%ld",ptr);
    return ptr;
}
int main(){
    int *ptr = allocatememoryinheap(4);
    *ptr = 20;
    printf("\n%d",*ptr); 
    printf("\n%ld",ptr);
}
