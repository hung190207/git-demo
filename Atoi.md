#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int my_atoi(char* h)
{
    int i = 0;
    int result = 0;
    for(i = 0; i<=strlen(h); i++)
    {
        if(i==0&&h[0]=='+'||h[0]=='-'&&i==0)
        {
                i++;
        }
        if(h[i]<'0'||h[i]>'9')
        {
                break;
        }
        result=result*10+h[i]-'0';
    }
    if(h[0]=="-")
    {
        return result-2*result;
    }
    else
    {
        return result;
    }
}
int main()
{
    char* hung2 = calloc(1024,sizeof(char));
    printf("Enter any number at here : ");
    scanf("%1024[^\n]",hung2);
    printf("Atoi = %d",my_atoi(hung2));
    return 0;
}
