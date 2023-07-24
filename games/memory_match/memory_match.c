#include <stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<time.h>

int main()
{
    int n,i;
    int randnum[1];
    srand(time(NULL));
    printf("welcome to memory match");
    printf("\nround 1");
    for(i=0;i<1;i++)
    {
        randnum[i]=rand();
         printf("      \n%d",rand());

    }
    // printf("      \n%d",rand());
    sleep(1);
    system("cls");
    printf("enter the above random number");
    scanf("%d",&n);
    if(randnum(i)==n)
    {
        printf("u got it ");
    }

    return 0;
}