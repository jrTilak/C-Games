#include "../db/utils/db.h"
int create_new_account(char *filename)
{
    char name[50], username[50], password[50];
    User all_user[100];
    printf("Name: ");
    scanf("%s", name);
    printf("Username: ");
    scanf("%s", username);
    printf("Password: ");
    scanf("%s", password);

    // Create new account
    system("cls");
    if (create_user(filename, name, username, password))
    {
        printf("\nAccount created successfully\n\n");
    }
    else
    {
        printf("\nAccount creation failed\n\n");
    }
    printf("Press any key to continue...");
    getch();
    system("cls");
    return 0;
}