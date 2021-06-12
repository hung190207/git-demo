#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int dec_to_bin(int n)
{
    int i = 0;
    int binary = 0;
    while(n>0)
    {
        binary += (n % 2) * pow(10,i);
        i++;
        n /= 2;

    }
    return binary;
}
int main()
{
    char s[1000];
    printf("Input a decimal number: ");
    scanf("%s", s);

    int n = atoi(s);
    int bin = dec_to_bin(n);
    printf("Binary output: %d\n", bin);
}
/*
101011 = 1 * 2^0 + 1 * 2^1 + 0 * 2^2 + 1 * 2^3 + 0 * 2^4 + 1 * 2^5  = 1 + 2 + 0 + 8 + 32  = 43 /Nice :D
43 =
    1,21 ** cai nay kieu chia lay du xong roi sau do lay phan da chia chia lay du tiep cho den khi khong the chia tiep duoc nua hoac kieu vay **
    1,10
    0,5
    1,2
    0,1
    1,0 ** Det bay gio moi hieu :V ** // chuyen tu so thap phan sang nhi phan con kho hon chuyen tu nhi phan sang thap phan nua :))
*/
