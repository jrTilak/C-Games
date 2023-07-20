#include <stdio.h>
#include <stdlib.h>
# include "../games/game_menu.c"

int login(char *filename, char *global_username, char *global_name)
{
    // Variables
    char username[50], password[50];

    system("cls");
    // Input username and password
    printf("\n");
    printf("Username: ");
    scanf("%s", username);
    printf("Password: ");
    scanf("%s", password);

    // Compare username and password
    if (check_user(filename, username, password))
    {
        printf("\nLogin successful\n\n");
        get_user(filename, global_username, global_name); // get user details
        printf("Press any key to continue...");
        getch();
        system("cls");
        game_menu();
        return 1;
    }
    else
    {
        printf("\nLogin failed\n\n");
        printf("Press any key to continue...");
        getch();
        system("cls");
    }

    return 0;
}