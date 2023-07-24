// header files
#include <stdio.h>
#include <time.h>
#include <ctype.h>
#include <conio.h>
#include <string.h>
#include <stdlib.h>
#include "./games/truth_or_dare.c"

// structures

typedef struct Users
{
    char name[50];
    char username[50];
    char password[50];
} User;

// function prototypes
int create_new_account(char *filename);                                      // desc: create a new account and save it to the file
int create_user(char *filename, char *name, char *username, char *password); // desc: create a new user and save it to the file
int check_username(char *filename, char *username);                          // desc: check if the username exists in the file
int check_user(char *filename, char *username, char *password);              // desc: check if the username and password exists in the file
int login(char *filename, char *global_username, char *global_name);         // desc: login the user and return 1 if successful
void get_user(char *username, char *name);                                   // desc: get the user details from the file
int game_menu(char *global_name, char *global_username);                     // desc: game menu
void print_game_history(char *username);                                     // desc: print the game history of the user
void register_score(char *game, char *username, char *score);                // desc: register the score of the user
int exit_game(char *msg, int code);                                          // desc: exit the game with a message and code

// user details -> global variables
char global_username[50],
    global_name[50];

// main function
int main()
{
main:
    // Variables
    int choice;

    // Menu
    // system("cls");
    printf("-----------------------------------------\n");
    printf("%-40s", "| Welcome to C Games");
    printf("|\n");
    printf("-----------------------------------------\n");
    printf("%-40s", "|   1. Create a new Account");
    printf("|\n");
    printf("%-40s", "|   2. Login");
    printf("|\n");
    printf("%-40s", "|   0. Exit");
    printf("|\n");
    printf("-----------------------------------------\n");
    // Input choice
    printf("Enter your choice: ");
    scanf("%d", &choice);

    // Switch case
    switch (choice)
    {
    case 1:
        system("cls");
        create_new_account("./db/users.bin");
        goto main;
        break;
    case 2:
        system("cls");
        login("./db/users.bin", global_username, global_name);
        // goto main; //todo
        break;
    case 0:
        system("cls");
        exit_game("Thanks for playing C Games.", 0);
        break;
    default:
        system("cls");
        printf("Invalid choice");
        break;
    }

    return 0;
}

// auth functions
// create a new account
int create_new_account(char *filename)
{
    char name[50], username[50], password[50];
    User all_user[100];
    printf("Name: ");
    scanf("%s", name);
    name[0] = toupper(name[0]);
    printf("Username: ");
    scanf("%s", username);
    printf("Password: ");
    scanf("%s", password);

    // Create new account
    system("cls");
    printf("-----------------------------------------\n");
    if (create_user(filename, name, username, password))
    {

        printf("%-40s", "|   Account created successfully");
        printf("|\n");
    }
    else
    {
        printf("%-40s", "|   Account creation failed.");
        printf("|\n");
        printf("%-40s", "|   Username already exists.");
        printf("|\n");
    }
    printf("-----------------------------------------\n");
    printf("Press any key to continue...");
    getch();
    system("cls");
    return 0;
}

// create a new user
int create_user(char *filename, char *name, char *username, char *password)
{
    FILE *fptr;
    User new_user;
    fptr = fopen(filename, "ab");
    if (fptr == NULL)
    {
        return 0;
    }
    strcpy(new_user.name, name);
    strcpy(new_user.username, username);
    strcpy(new_user.password, password);
    if (check_username(filename, username) == 1)
    {
        return 0;
    }
    else
    {
        fwrite(&new_user, sizeof(User), 1, fptr);
    }
    fclose(fptr);
    return 1;
}

// checks if the user with the username exists
int check_username(char *filename, char *username)
{
    FILE *fptr;
    User temp_user;
    fptr = fopen(filename, "rb");
    while (fread(&temp_user, sizeof(User), 1, fptr) == 1)
    {
        if (strcmp(temp_user.username, username) == 0)
        {
            fclose(fptr);
            return 1;
        }
    }
    fclose(fptr);
    return 0;
}

// login functions
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

        system("cls");
        printf("-----------------------------------------\n");
        printf("%-40s", "|   Login Successful");
        printf("|\n");
        printf("-----------------------------------------\n");
        // get user details
        strcpy(global_username, username);
        get_user(global_username, global_name);
        printf("Press any key to continue...");
        getch();
        system("cls");
        game_menu(global_name, global_username);
        return 1;
    }
    else
    {
        system("cls");
        printf("-----------------------------------------\n");
        printf("%-40s", "|   Login Failed");
        printf("|\n");
        printf("%-40s", "|   Invalid username or password");
        printf("|\n");
        printf("-----------------------------------------\n");
        printf("Press any key to continue...");
        getch();
        system("cls");
    }

    return 0;
}

// checks if the user with the username and password exists
int check_user(char *filename, char *username, char *password)
{
    FILE *fptr;
    User temp_user;
    fptr = fopen(filename, "rb");
    while (fread(&temp_user, sizeof(User), 1, fptr) == 1)
    {
        if (strcmp(temp_user.username, username) == 0 && strcmp(temp_user.password, password) == 0)
        {
            fclose(fptr);
            return 1;
        }
    }
    fclose(fptr);
    return 0;
}

// give the username and nme of user with the username
void get_user(char *username, char *name)
{
    FILE *fptr;
    User temp_user;
    fptr = fopen("./db/users.bin", "rb");
    while (fread(&temp_user, sizeof(User), 1, fptr) == 1)
    {
        if (strcmp(temp_user.username, username) == 0)
        {
            strcpy(name, temp_user.name);
            break;
        }
    }
    fclose(fptr);
}

// game functions
// game menu
int game_menu(char *global_name, char *global_username)
{
    // Variables
    int choice;

    // Menu
    system("cls");
    printf("----------------------------------------\n");
    printf("| Welcome ");
    printf("%-29s", global_name);
    printf("|\n");
    printf("%-40s", "| Choose a Game:");
    printf("|\n");
    printf("----------------------------------------\n");
    printf("%-40s", "|   1. Tic Tac Toe");
    printf("|\n");
    printf("%-40s", "|   2. Truth or Dare");
    printf("|\n");
    printf("%-40s", "|   3. Memory Match ");
    printf("|\n");
    printf("%-40s", "|   4. Rock Paper Scissor ");
    printf("|\n");
    printf("%-40s", "|   5. Coin Flip ");
    printf("|\n");
    printf("----------------------------------------\n");
    printf("%-40s", "|   6. Game History");
    printf("|\n");
    printf("%-40s", "|   7. Logout");
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
    case 1: // tic tac toe
        system("cls");
        printf("This game is not available yet\n");
        printf("Press any key to continue...");
        getch();
        system("cls");
        game_menu(global_name, global_username);
        break;
    case 2: // truth or dare
        system("cls");
        truth_or_dare(global_name, global_username);
        game_menu(global_name, global_username);
        break;
    case 3: // memory match
        system("cls");
        printf("This game is not available yet\n");
        printf("Press any key to continue...");
        getch();
        system("cls");
        game_menu(global_name, global_username);
        break;
    case 4: // rock paper scissor
        system("cls");
        printf("This game is not available yet\n");
        printf("Press any key to continue...");
        getch();
        system("cls");
        game_menu(global_name, global_username);
        break;
    case 5: // coin flip
        system("cls");
        printf("This game is not available yet\n");
        printf("Press any key to continue...");
        getch();
        system("cls");
        game_menu(global_name, global_username);
        break;
    case 6: // game history
        system("cls");
        print_game_history(global_username);
        printf("Press any key to continue...");
        getch();
        system("cls");
        game_menu(global_name, global_username);
        break;
    case 7: // logout
        system("cls");
        main();
        break;
    case 0: // exit
        system("cls");
        exit_game("Thanks for playing C Games.", 0);
        break;
    default:
        system("cls");
        printf("Invalid choice");
        break;
    }

    return 0;
}

// print user game history
void print_game_history(char *username)
{
    FILE *fptr;
    Score temp_score;
    char file_name[100];
    sprintf(file_name, "./db/game_history/%s.bin", username);
    fptr = fopen(file_name, "rb");
    if (fptr == NULL)
    {
        printf("No game history found\n");
    }
    else
    {
        printf("Game\t\tScore\n");
        while (fread(&temp_score, sizeof(Score), 1, fptr) == 1)
        {
            printf("%s\t%s\n", temp_score.game, temp_score.score);
        }
    }
    fclose(fptr);
}

// register user score by making a new file with username and score
void register_score(char *game, char *username, char *score)
{
    FILE *fptr;
    Score new_score;
    char file_name[100];
    sprintf(file_name, "./db/game_history/%s.bin", username);
    fptr = fopen(file_name, "ab");
    if (fptr == NULL)
    {
        return;
    }
    strcpy(new_score.game, game);
    strcpy(new_score.score, score);
    fwrite(&new_score, sizeof(Score), 1, fptr);
    fclose(fptr);
}

// exit game with a message and code
int exit_game(char *msg, int code)
{
    printf("-----------------------------------------\n");
    printf("|   ");
    printf("%-36s", msg);
    printf("|\n");
    printf("-----------------------------------------\n");
    exit(code);
}