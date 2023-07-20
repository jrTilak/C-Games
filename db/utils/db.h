#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../struct/user.h"

// function prototypes
int create_user(char *filename, char *name, char *username, char *password);
void get_all_users(char *filename, User *all_users);
int check_username(char *filename, char *username);


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
        printf("Username already exists.\n");
        return 0;
    }
    else
    {
        fwrite(&new_user, sizeof(User), 1, fptr);
    }
    fclose(fptr);
    return 1;
}

// get all users function
void get_all_users(char *filename, User *all_users)
{
    FILE *fptr;
    int i = 0;
    User temp_user;
    fptr = fopen(filename, "rb");
    while (fread(&temp_user, sizeof(User), 1, fptr) == 1)
    {
        all_users[i] = temp_user;
        i++;
    }
    fclose(fptr);
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

//give the username and nme of user with the username
void get_user(char *filename, char *username, char *name)
{
    FILE *fptr;
    User temp_user;
    fptr = fopen(filename, "rb");
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