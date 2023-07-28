#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <conio.h>
#include <string.h>

int tic_tac_toe(char *global_name, char *global_username);

void print_board(char *board)
{
    // system("cls");
    printf("\n\n\tTic Tac Toe\n\n");
    printf("Player 1 (%c)  -  Player 2 (%c)\n\n\n", 'X', 'O');
    printf("  %c  |  %c  |  %c \n", board[1], board[2], board[3]);
    printf("_____|_____|_____\n");
    printf("     |     |     \n");
    printf("  %c  |  %c  |  %c \n", board[4], board[5], board[6]);
    printf("_____|_____|_____\n");
    printf("     |     |     \n");
    printf("  %c  |  %c  |  %c \n", board[7], board[8], board[9]);
    printf("     |     |     \n");
    printf("\n");
}

void print_intro()
{
    printf("\n========================================\n");
    printf("        Welcome to Tic Tac Toe\n");
    printf("========================================\n");
    printf("Description: Tic Tac Toe is a simple two-player game where each player takes turns marking a cell in a 3x3 grid.\n");
    printf("The player who succeeds in placing three of their marks in a horizontal, vertical, or diagonal row wins the game.\n");
    printf("Min Players: 2\n");
    printf("Max Players: 2\n");
    printf("========================================\n");
    printf("How to play: Players take turns to choose a number between 1 to 9 which corresponds to the cell they want to mark.\n");
    printf("The board will be updated, and the first player to get three marks in a row wins. If all cells are marked and no player wins, it's a draw.\n");
    printf("========================================\n");
}

int is_over(char *board)
{
    // check for match and return 0 if x match 1 if o match and -1 if no match or draw
    if (board[1] == board[2] && board[2] == board[3])
    {
        if (board[1] == 'X')
            return 0;
        else
            return 1;
    }
    else if (board[4] == board[5] && board[5] == board[6])
    {
        if (board[4] == 'X')
            return 0;
        else
            return 1;
    }
    else if (board[7] == board[8] && board[8] == board[9])
    {
        if (board[7] == 'X')
            return 0;
        else
            return 1;
    }
    else if (board[1] == board[4] && board[4] == board[7])
    {
        if (board[1] == 'X')
            return 0;
        else
            return 1;
    }
    else if (board[2] == board[5] && board[5] == board[8])
    {
        if (board[2] == 'X')
            return 0;
        else
            return 1;
    }
    else if (board[3] == board[6] && board[6] == board[9])
    {
        if (board[3] == 'X')
            return 0;
        else
            return 1;
    }
    else if (board[1] == board[5] && board[5] == board[9])
    {
        if (board[1] == 'X')
            return 0;
        else
            return 1;
    }
    else if (board[3] == board[5] && board[5] == board[7])
    {
        if (board[3] == 'X')
            return 0;
        else
            return 1;
    }
    else if (board[1] != '1' && board[2] != '2' && board[3] != '3' &&
             board[4] != '4' && board[5] != '5' && board[6] != '6' &&
             board[7] != '7' && board[8] != '8' && board[9] != '9')
        return -1;
    else
        return -2;
}

int tic_tac_toe(char *global_name, char *global_username)
{
    int player1_score = 5;
    int player2_score = 5;
    char real_board[10], view_board[10];
    for (int i = 0; i < 10; i++)
    {
        real_board[i] = (char)(i + 48);
        view_board[i] = ' ';
    }
    char another_player[20];
    print_intro();
    print_board(real_board);

    printf("Enter the name of Player 2: ");
    scanf("%s", another_player);

    int player_count = 2, choice, i;
    int active_player = rand() % player_count + 1;
    char mark[2] = {'X', 'O'};

    int winner;
    do
    {
        print_board(view_board);
        printf("%s's turn (%c). Enter a number: ", (active_player == 1) ? global_name : another_player, (active_player == 1) ? 'X' : 'O');
        scanf("%d", &choice);
        strcpy(mark, (active_player == 1) ? "X" : "O");

        if (choice >= 1 && choice <= 9 && real_board[choice - 1] != 'X' && real_board[choice - 1] != 'O')
        {
            view_board[choice - 1] = mark[active_player - 1];
            real_board[choice - 1] = mark[active_player - 1];
            active_player++;
            active_player = (active_player > player_count) ? 1 : active_player;
        }
        else
        {
            printf("Invalid move. Try again.\n");
            continue;
        }
        winner = is_over(real_board);
    } while (winner == -2);

    print_board(view_board);

    // checks the winner
    if (winner == 0)
    {
        printf("\n\n\t\t\t\t\t%s wins\n\n", global_name);
        player1_score += 5;
    }
    else if (winner == 1)
    {
        printf("\n\n\t\t\t\t\t%s wins\n\n", another_player);
        player2_score += 5;
    }
    else
    {
        printf("\n\n\t\t\t\t\tGame draw\n\n");
    }

    return 0;
}

// int main()
// {
//     tic_tac_toe("tilak", "tilak");
//     return 0;
// }