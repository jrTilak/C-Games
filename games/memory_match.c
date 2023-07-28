#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

int main()
{
    int n, i, c = 0;
    int a = 1;
    int num;
    srand(time(NULL));
    printf("*********************************************\n");
    printf("\t welcome to memory match\n");
    printf("*********************************************\n");
    // for(int j=0;j<4;j++)
    // {
    //       printf("*\n");

    // }

    // printf("*")

    // printf("\t welcome to memory match");
    for (i = 1; i <= 3; i++)
    {
        printf("--------------------------------\n");
        printf("\tround %d", i);
        printf("\n--------------------------------\n");

        num = a * rand();
        a = a * 101;

        printf("\n%d", num);
        sleep(4);
        system("cls");
        printf("enter the above random number");
        scanf("%d", &n);
        if (num == n)
        {
            printf("\tu got it\n ");
            c += 1;
        }
        else
        {
            printf("\tsorry\n");
        }
    }

    printf("\tyour score is %d", c);
    return 0;
}