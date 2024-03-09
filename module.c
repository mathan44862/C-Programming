//write a function which return charater and first argument is integer and another is float .. take modules of first and second argument and store it in charater and return it
#include <stdio.h>
char modulo(int a,float b){
    char c = a%(int)b;
    return c;
}
int main()
{
    printf("%d",modulo(10,20.0));
    return 0;
}
