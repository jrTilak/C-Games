/*
========================================================================================
||                          Tic Tac Toe Game                                           ||
========================================================================================
*/
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include <stdbool.h>

//========================== Function Prototypes =======================================//

void tic_tac_toe(char *global_name, char *global_username);
void print_intro_tic_tac_toe(char *name, char *board);
void print_board(char *board);
int is_over(char *board);


//========================== Function Definitions =======================================//
/*
    *function name: tic_tac_toe
    arguments: name and username of currently logged in user
    return type: void
    working mechanism: This function is to play tic tac toe game. After the game is over, it
        will register the score of the user in the database.
*/
void tic_tac_toe(char *global_name, char *global_username)
{
    system("cls");
    bool is_valid_move = true;
    char real_board[9], view_board[9];
    char player1[20], player2[20]; // name of players
    char mark[2] = {'X', 'O'};
    int winner, active_player = 0;

    for (int i = 0; i < 9; i++) // initializing the real board with numbers and view board with white spaces
    {
        real_board[i] = i + 49;
        view_board[i] = ' ';
    }

    print_intro_tic_tac_toe(global_name, real_board);
    system("cls");

    strcpy(player1, global_name);
    printf("Enter another player name: ");
    scanf("%s", player2);
    player2[0] = toupper(player2[0]);
    system("cls");

    do // game loop
    {
        char active_mark = mark[active_player];
        int choice;

        system("cls");
        printf("%s: %c\n", player1, mark[0]);
        printf("%s: %c", player2, mark[1]);
        print_board(view_board);
        !is_valid_move &&printf("Invalid move. Try again.\n"); // if the move is invalid, print this message
        printf("%s's turn. Enter a number(position): ", (active_player == 0) ? player1 : player2);
        scanf("%d", &choice);

        // checks if the move is valid
        if (choice >= 1 && choice <= 9 && real_board[choice - 1] != 'X' && real_board[choice - 1] != 'O')
        {
            view_board[choice - 1] = active_mark;
            real_board[choice - 1] = active_mark;
            active_player++;
            active_player = (active_player > 1) ? 0 : active_player;
            is_valid_move = true;
        }
        else
        {
            is_valid_move = false;
        }
        winner = is_over(real_board);
    } while (winner == -2); // game loop ends when winner is decided

    system("cls");
    print_board(view_board);

    // checks the winner
    printf("================= Game Over =================\n");

    if (winner == 0)
    {
        printf("| Winner: ");
        printf("%-34s", player1);
        printf("|\n");
        register_score("Tic Tac Toe", global_username, "Won");
    }
    else if (winner == 1)
    {
        printf("| Winner: ");
        printf("%-34s", player2);
        printf("|\n");
        register_score("Tic Tac Toe", global_username, "Lost");
    }
    else
    {
        printf("|                    Draw                   |\n");
        register_score("Tic Tac Toe", global_username, "Draw");
    }
    printf("=============================================\n");
    return;
}

/*
    *function name: print_intro_tic_tac_toe
    arguments: name of the player and the board
    return type: void
    working mechanism: This function prints the introduction of the game and the board
        with numbers.
*/
void print_intro_tic_tac_toe(char *name, char *board)
{
    // intro of game
    printf("-----------------------------------------------------------\n");
    printf("  Welcome %s to Tic Tac Toe\n", name);
    printf("-----------------------------------------------------------\n");
    printf("%-58s", "| Tic Tac Toe is a simple two-player game where each");
    printf("|\n");
    printf("%-58s", "| player takes turns marking a cell in a 3x3 grid.");
    printf("|\n");
    printf("%-58s", "| The player wins by placing three of their marks in");
    printf("|\n");
    printf("%-58s", "| a horizontal, vertical, or diagonal row wins the game.");
    printf("|\n");
    printf("%-58s", "|");
    printf("|\n");
    printf("%-58s", "| Min Players: 2");
    printf("|\n");
    printf("%-58s", "| Max Players: 2");
    printf("|\n");
    printf("-----------------------------------------------------------\n");
    printf("Press any key to continue...");
    getch();
    system("cls");

    // how to play
    printf("-----------------------------------------------------------\n");
    printf("  How to play:\n");
    printf("-----------------------------------------------------------\n");
    printf("%-58s", "| Players take turns to choose a number between 1 to 9");
    printf("|\n");
    printf("%-58s", "| which corresponds to the cell they want to mark.");
    printf("|\n");
    printf("-----------------------------------------------------------\n");
    print_board(board);
    printf("Remember the cell numbers!!\n");
    printf("Press any key to continue...");
    getch();
}

/*
    *function name: print_board
    arguments: board
    return type: void
    working mechanism: This function prints the board.
*/
void print_board(char *board)
{
    printf("\n\n\tTic Tac Toe\n\n");
    printf("  %c  |  %c  |  %c \n", board[0], board[1], board[2]);
    printf("_____|_____|_____\n");
    printf("     |     |     \n");
    printf("  %c  |  %c  |  %c \n", board[3], board[4], board[5]);
    printf("_____|_____|_____\n");
    printf("     |     |     \n");
    printf("  %c  |  %c  |  %c \n", board[6], board[7], board[8]);
    printf("     |     |     \n");
    printf("\n");
}

/*
    *function name: is_over
    arguments: board
    return type: -2 if game is not over, 0 if x wins, 1 if o wins, -1 if draw
    working mechanism: This function checks if the game is over or not
*/
int is_over(char *board)
{
    // horizontal check
    if (board[0] == board[1] && board[1] == board[2])
    {
        if (board[0] == 'X')
            return 0;
        else
            return 1;
    }
    else if (board[3] == board[4] && board[4] == board[5])
    {
        if (board[3] == 'X')
            return 0;
        else
            return 1;
    }
    else if (board[6] == board[7] && board[7] == board[8])
    {
        if (board[6] == 'X')
            return 0;
        else
            return 1;
    }

    // vertical check
    else if (board[0] == board[3] && board[3] == board[6])
    {
        if (board[0] == 'X')
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

    // diagonal check
    else if (board[0] == board[4] && board[4] == board[8])
    {
        if (board[0] == 'X')
            return 0;
        else
            return 1;
    }
    else if (board[2] == board[4] && board[4] == board[6])
    {
        if (board[2] == 'X')
            return 0;
        else
            return 1;
    }

    // draw check
    else if (board[0] != '1' && board[1] != '2' && board[2] != '3' && board[3] != '4' && board[4] != '5' && board[5] != '6' && board[6] != '7' && board[7] != '8' && board[8] != '9')
        return -1;

    // game not over
    else
        return -2;
}
