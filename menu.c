#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

int main()
{
    // Variables
    int choice;

    // Menu
    system("cls");
    printf("----------------------------------------\n");
    printf("%-40s", "| Welcome to C Games");
    printf("|\n");
    printf("----------------------------------------\n");
    printf("%-40s", "|   1. Truth or Dare");
    printf("|\n");
    printf("%-40s", "|   2. Rock Paper Scissors");
    printf("|\n");
    printf("%-40s", "|   3. Memory Match");
    printf("|\n");
    printf("%-40s", "|   4. Coin Flip");
    printf("|\n");
    printf("%-40s", "|   0. Exit");
    printf("|\n");
    printf("----------------------------------------\n");

    // Input choice
    printf("%-40s", "Enter your choice: ");
    scanf("%d", &choice);

    // Switch case
    switch (choice)
    {
    case 1:
        system("cls");
        printf("Truth or Dare");
        break;
    case 2:
        system("cls");
        printf("Rock Paper Scissors");
        break;
    case 3:
        system("cls");
        printf("Memory Match");
        break;
    case 4:
        system("cls");
        printf("Coin Flip");
        break;
    case 0:
        system("cls");
        printf("Exiting...");
        break;
    default:
        system("cls");
        printf("Invalid choice");
        break;
    }

    return 0;
}