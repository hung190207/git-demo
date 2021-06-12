#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int bin_to_dec(int n)
{
    int i = 0;
    int decimal = 0;
    while(n>0)
    {
        decimal += (n % 10) * pow(2,i);
        i++;
        n /= 10;

    }
    return decimal;
}
int main()
{
    char s[1000];
    printf("Input a binary number: ");
    scanf("%s", s);

    int n = atoi(s);
    int dec = bin_to_dec(n);
    printf("decimal output: %d\n", &dec);
}

