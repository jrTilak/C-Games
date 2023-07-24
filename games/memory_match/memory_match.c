#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

int main()
{
    int n, i,c=0;
    int num;
    srand(time(NULL));
    printf("welcome to memory match");
    for(i=1;i<=3;i++)
    {
     printf("\nround %d",i);

    num = rand();
    printf("\n%d", num);
    sleep(1);
    system("cls");
    printf("enter the above random number");
    scanf("%d", &n);
    if (num == n)
    {
        printf("u got it ");
        c+=1;
    }
    else
    {
        printf("sorry");
    }

    }
//     printf("\nround 1");

//     num = rand();
//     printf("\n%d", num);
//     sleep(1);
//     system("cls");
//     printf("enter the above random number");
//     scanf("%d", &n);
//     if (num == n)
//     {
//         printf("u got it ");
//     }
//     else
//     {
//         printf("sorry");
//     }
printf("your score is %d",c);
     return 0;
 }