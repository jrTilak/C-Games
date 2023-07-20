#include <stdio.h>

int game_menu()
{
    // Variables
    int choice;

    // Menu
    // system("cls");
    printf("----------------------------------------\n");
    printf("%-40s", "| Choose a Game:");
    printf("|\n");
    printf("----------------------------------------\n");
    printf("%-40s", "|   1. Truth or Dare");
    printf("|\n");
    printf("%-40s", "|   2. Memory Match ");
    printf("|\n");
    printf("%-40s", "|   3. Rock Paper Scissor ");
    printf("|\n");
    printf("%-40s", "|   4. Coin Flip ");
    printf("|\n");
    printf("----------------------------------------\n");
    printf("%-40s", "|   5. Logout");
    printf("|\n");
    printf("%-40s", "|   0. Exit");
    printf("|\n");
    printf("----------------------------------------\n");

    // Input choice
    printf("Enter your choice: ");
    scanf("%d", &choice);

    // Switch case
    switch (choice)
    {
    case 1:
        system("cls");
        break;
    case 2:
        system("cls");
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