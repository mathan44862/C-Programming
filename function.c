#include <stdio.h>
struct Sample
{
  int a;
  int b;
};
int sum (int a, int b);
int main()
{
  unsigned char a;
  printf ("%u\n", &a);
  printf ("%d", sum (a, 10));
  return 0;
}

int
sum (int a, int b)
{
  printf ("%u\n", &a);
  return a + b;
}
