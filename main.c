#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include "auth/create_new_account.c"
#include "auth/login.c"
#include "games/game_menu.c"

//
User current_user;

int main()
{
    // Variables
    int choice;

    // Menu
    // system("cls");
    printf("----------------------------------------\n");
    printf("%-40s", "| Welcome to C Games");
    printf("|\n");
    printf("----------------------------------------\n");
    printf("%-40s", "|   1. Create a new Account");
    printf("|\n");
    printf("%-40s", "|   2. Login");
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
        create_new_account("./db/users.bin");
        break;
    case 2:
        system("cls");
        login("./db/users.bin");
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