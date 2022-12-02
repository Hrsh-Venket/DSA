#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

void advancedFizzBuzz (int *a, int m, int *b, int nb, int *f, int nf)
{

    for (int i = 0; i < m; i++)
    {
        int Fizz = 0;
        int Buzz = 0;

        int x = a[i];
        
        for (int j = 0; j < nb; j++)
        {
            if (x % b[j] == 0)
            {
                Fizz = 1;
                break;
            }
        }

        for (int k = 0; k < nf; k++)
        {
            if (x % f[k] == 0)
            {
                Buzz = 1;
                break;
            }
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
}

int main()
{
    int *a;
    int m;
    int *b;
    int nb;
    int *f;
    int nf;

    printf("Enter the number of elements in the array you want to check: \n");
    scanf("%d", &m);

    if (m <= 0)
    {
        printf("Bastard");
        exit(0);
    }

    a = (int *)malloc(m * sizeof(int));


    printf("Enter the elements of the array separated by spaces: \n");
    for (int i = 0; i < m; i++)
    {
        scanf("%d", &a[i]);
    }


    printf("Enter the number of elements in the array of numbers that will be checked for Fizz: \n");
    scanf("%d", &nb);
    b = (int *)malloc(nb * sizeof(int));

    printf("Enter the elements of the array separated by spaces: \n");
    for (int i = 0; i < nb; i++)
    {
        scanf("%d", &b[i]);
    }


    printf("Enter the number of elements in the array of numbers that will be checked for Buzz: \n");
    scanf("%d", &nf);
    f = (int *)malloc(nf * sizeof(int));

    printf("Enter the elements of the array separated by spaces: \n");
    for (int i = 0; i < nf; i++)
    {
        scanf("%d", &f[i]);
    }

    advancedFizzBuzz(a, m, b, nb, f, nf);
}
