#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>
#include <stdbool.h>
#include <conio.h>
#include <string.h>

int coin_flip(char *global_name, char *global_username)
{
    int user_score = 0, currentRound = 1;
    bool is_valid_move = false;
    char user_choice, computer_choice, user_result[10];

    srand(time(NULL)); // Seed the random number generator

    system("cls");
    printf("-----------------------------------------------------------\n");
    printf("  Welcome %s to Coin Flip:\n", global_name);
    printf("-----------------------------------------------------------\n");
    printf("%-58s", "| Coin Flip is a simple single-player game where you ");
    printf("|\n");
    printf("%-58s", "| guess whether the coin will land on heads or tails.");
    printf("|\n");
    printf("%-58s", "| If you guess correctly, you get a point.");
    printf("|\n");
    printf("%-58s", "| If you guess incorrectly, you lose a point.");
    printf("|\n");
    printf("%-58s", "| The game ends when you enter 'q' to quit.");
    printf("|\n");
    printf("%-58s", "| You can enter 'h' for heads or 't' for tails.");
    printf("|\n");
    printf("-----------------------------------------------------------\n");
    printf("Press any key to continue...");
    getch();
    system("cls");

    while (true)
    {
        system("cls");
        printf("\n==================== Round %d ===========================\n", currentRound);
        printf("Current score: %d\n", user_score);
        printf("Enter 'h' for heads, 't' for tails and 'q' to quit.\n\n");

        is_valid_move && printf("Invalid move. Try again.\n");
        printf("Guess (Head or Tail): ");
        scanf(" %c", &user_choice);
        printf("\n");
        // Convert the user choice to lowercase for case-insensitivity
        user_choice = tolower(user_choice);
        // Simulate the toss of a coin
        int random_number = rand() % 2;
        computer_choice = (random_number == 0) ? 'h' : 't';

        if (user_choice == 'q')
        {
            break;
        }
        else if (user_choice == computer_choice)
        {
            printf("Congratulations! You got it.\n");
            user_score++;
            printf("The coin landed on %s.\n", computer_choice == 'h' ? "Heads" : "Tails");
            printf("Press any key to continue...");
            getch();
            currentRound++;
        }
        else if(user_choice == 'h' || user_choice == 't')
        {
            printf("Sorry! You got it wrong.\n");
            printf("The coin landed on %s.\n", computer_choice == 'h' ? "Heads" : "Tails");
            printf("Press any key to continue...");
            getch();
            currentRound++;
            
        }
        else
        {
            is_valid_move = true;
        }
    }
    system("cls");
    printf("\n=======================================================\n");
    printf("%-54s", "| Thanks for playing Coin Flip.");
    printf("|\n");
    printf("| Your final score is: %d", user_score);
    printf("%32s", "|\n");
    sprintf(user_result, "%d", user_score);
    register_score("Coin Flip", global_username, user_result);
    printf("=======================================================\n");
    printf("Press any key to continue...");
    getch();
    return 0;
}
