#include <stdio.h>

unsigned long long factLoop(int n)
{
    long long fact = 1;
    int i;
    for (i = 1; i <= n; i++)
    {
        fact = fact * i;
    }
    return fact;
}

long long factRec(int n)
{
    if (n == 0 || n == 1)
        return 1;
    return n * factRec(n - 1);
}

int main()
{
    int num;

    printf("Enter a number: ");
    scanf("%d", &num);

    if (num < 0)
    {
        printf("Factorial is not defined for negative numbers.\n");
    }
    else
    {
        printf("Factorial of number (without recursion) = %lld\n", factLoop(num));
        printf("Factorial of number (with recursion)    = %lld\n", factRec(num));
    }

    return 0;
}
