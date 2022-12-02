#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

void basicFizzBuzz (int x)
{
    int Fizz = 0;
    int Buzz = 0;

    if (x % 3 == 0 || x % 5 == 0)
    {
        Fizz = 1;
    }
    if (x % 11 == 0 || x % 13 == 0)
    {
        Buzz = 1;
    }


    if (Fizz == 1 && Buzz == 1)
    {
        printf("FizzBuzz");
    }
    if (Fizz == 1 && Buzz == 0)
    {
        printf("Fizz \n");
    }
    if (Fizz == 0 && Buzz == 1)
    {
        printf("Buzz \n");
    }
    if (Fizz == 0 && Buzz == 0)
    {
        printf("%d \n", x);
    }
}

int main()
{
    int x;
    printf("Enter a number: \n ");
    scanf("%d", &x);
    basicFizzBuzz(x);
}
