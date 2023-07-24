#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

int main()
{
    int n, i;
    int num;
    srand(time(NULL));
    printf("welcome to memory match");
    printf("\nround 1");

    num = rand();
    printf("\n%d", num);
    sleep(1);
    system("cls");
    printf("enter the above random number");
    scanf("%d", &n);
    if (num == n)
    {
        printf("u got it ");
    }
    else
    {
        printf("sorry");
    }

    return 0;
}