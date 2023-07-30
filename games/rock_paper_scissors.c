#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

int generateComputerChoice()
{
    // Generate a random number between 0 and 2
    // 0 - Rock, 1 - Paper, 2 - Scissors
    return rand() % 3;
}

int determineWinner(int playerChoice, int computerChoice)
{
    // Returns:
    // 1 if the player wins
    // 0 if it's a draw
    // -1 if the computer wins

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

int rock_paper_scissor(char *global_name, char *global_username)
{
    system("cls");
    // int playerChoice, computerChoice, result, ;
    // char choices[3][10] = {"Rock", "Paper", "Scissors"};
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
