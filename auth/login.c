#include <stdio.h>
#include <stdlib.h>

int main();

int login(char *filename)
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
        main();
    }

    return 0;
}