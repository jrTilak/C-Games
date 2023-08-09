//========================= Rock Paper Scissor =========================//
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

/*
    *function name: generateComputerChoice
    arguments: none
    return type: int => 0 for rock, 1 for paper and 2 for scissors
    working mechanism: This function is to generate a random number between 0 and 2
        which will be used to determine the computer's choice.
*/
int generateComputerChoice()
{
    return rand() % 3;
}

/*
    *function name: determineWinner
    arguments: player's choice and computer's choice
    return type: int => 1 for player wins, 0 for draw and -1 for computer wins
    working mechanism: This function is to determine the winner of the round.
        It returns 1 if the player wins, 0 if it's a draw and -1 if the computer wins.
*/
int determineWinner(int playerChoice, int computerChoice)
{
    if (playerChoice == computerChoice)
    {
        return 0; // Draw
    }
    else if ((playerChoice == 0 && computerChoice == 2) ||
             (playerChoice == 1 && computerChoice == 0) ||
             (playerChoice == 2 && computerChoice == 1))
    {
        return 1; // Player wins
    }
    else
    {
        return -1; // Computer wins
    }
}

/*
    *function name: print_intro_rock_paper_scissor
    arguments: name of currently logged in user
    return type: void
    working mechanism: This function is to print the intro of the game.
*/
void print_intro_rock_paper_scissor(char *name)
{
    // intro of game
    printf("--------------------------------------------------------------------\n");
    printf("  Welcome %s to Rock Paper Scissor\n", name);
    printf("--------------------------------------------------------------------\n");
    printf("%-67s", "| Rock Paper Scissor is a game for two players. Each player");
    printf("|\n");
    printf("%-67s", "| chooses either rock, paper or scissors. The items are compared.");
    printf("|\n");
    printf("%-67s", "| Paper wins against rock, rock wins against scissors and scissors");
    printf("|\n");
    printf("%-67s", "| win against paper. The winner is the one who defeats the other.");
    printf("|\n");
    printf("%-67s", "| The game is a tie if both players choose the same item.");
    printf("|\n");
    printf("--------------------------------------------------------------------\n");
    printf("Press any key to continue...");
    getch();
    system("cls");
    return;
}

/*
    *function name: rock_paper_scissor
    arguments: name of currently logged in user, username of currently logged in user
    return type: int => 0 after the game is over
    working mechanism: This function is to play rock paper scissor game.
*/
int rock_paper_scissor(char *global_name, char *global_username)
{
    system("cls");
    int current_round = 1, player_choice, computer_choice, result, players_score = 0, computers_score = 0;
    bool is_invalid_choice = false;
    char ch_player_choice, ch_result[10];

    print_intro_rock_paper_scissor(global_name);

    // Seed the random number generator with the current time
    srand(time(NULL));

    while (true)
    {
        system("cls");
        printf("\n==================== Round %d ===========================\n", current_round);
        printf("Score:\n");
        printf("%s: %d\n", global_name, players_score);
        printf("Computer: %d\n", computers_score);
        printf("Rock: 'r', Paper: 'p', Scissors: 's'\n\n");
        is_invalid_choice &&printf("Invalid choice! Please try again.\n");
        printf("Choose your weapon(r/p/s): ");
        scanf(" %c", &ch_player_choice);
        printf("\n");
        ch_player_choice = tolower(ch_player_choice);

        // Convert the player choice to an integer
        if (ch_player_choice == 'r')
        {
            player_choice = 0;
        }
        else if (ch_player_choice == 'p')
        {
            player_choice = 1;
        }
        else if (ch_player_choice == 's')
        {
            player_choice = 2;
        }
        else
        {
            is_invalid_choice = true;
            continue;
        }

        computer_choice = generateComputerChoice();
        result = determineWinner(player_choice, computer_choice);
        printf("---------------- Result ---------------------\n");
        if (result == 0)
        {
            printf("It's a draw!\n");
        }
        else if (result == 1)
        {
            printf("Congratulations! You win this round!\n");
            players_score++;
        }
        else
        {
            printf("Computer wins! Better luck next time!\n");
            computers_score++;
        }

        printf("%s: %s\n", global_name, player_choice == 0 ? "Rock" : (player_choice == 1 ? "Paper" : "Scissors"));
        printf("Computer: %s\n", computer_choice == 0 ? "Rock" : (computer_choice == 1 ? "Paper" : "Scissors"));

        printf("Press any key to continue or 'q' to quit: ");
        ch_player_choice = getch();
        ch_player_choice = tolower(ch_player_choice);
        if (ch_player_choice == 'q')
        {
            break;
        }
        else
        {
            current_round++;
            is_invalid_choice = false;
            system("cls");
        }
    }

    system("cls");
    printf("================= Game Over =================\n");
    if (players_score > computers_score)
    {
        printf("Congratulations! You win the game!\n");
        sprintf(ch_result, "%d", players_score);
        strcat(ch_result, "(Won)");
    }
    else if (players_score < computers_score)
    {
        printf("Computer wins the game!\n");
        sprintf(ch_result, "%d", players_score);
        strcat(ch_result, "(Lost)");
    }
    else
    {
        printf("It's a draw!\n");
    }
    printf("Final score:\n");
    printf("%s: %d\n", global_name, players_score);
    printf("Computer: %d\n", computers_score);
    register_score("Rock Paper Scissor", global_username, ch_result);
    printf("Press any key to continue...");
    getch();
    system("cls");
    return 0;
}
