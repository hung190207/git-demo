# Testing Printf(Beginner)
 #include <stdio.h>
  int main()
{
    int f =123456789;
    unsigned int i =1234;
    int r = 354.291;
    int e = 2;
    int d = 3;
    printf("%d\n",f);
    printf("%u\n",i);
    printf("%o\n",i);
    printf("%x\n",f);
    printf("%X\n",f);
    printf("%f\n", r * 10);
    printf("%2F\n",r*1000);
    printf("%d%e\n",d,e);
    printf("%d%E\n",d,e);
    return 0;
}
