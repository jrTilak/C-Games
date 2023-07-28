#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>

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

void print_board(char *board)
{
    // system("cls");
    printf("\n\n\tTic Tac Toe\n\n");
    printf("Player 1 (%c)  -  Player 2 (%c)\n\n\n", 'X', 'O');
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

int is_over(char *board)
{
    // check for match and return 0 if x match 1 if o match and -1 if no match or draw
    if (board[0] == board[1] && board[1] == board[2])
    {
        if (board[0] == 'X')
            return 0;
        else
            return 1;
    }
    else if (board[3] == board[4] && board[4] == board[5])
    {
        if (board[5] == 'X')
            return 0;
        else
            return 1;
    }
    else if (board[6] == board[7] && board[7] == board[8])
    {
        if (board[7] == 'X')
            return 0;
        else
            return 1;
    }
    else if (board[0] == board[3] && board[3] == board[6])
    {
        if (board[0] == 'X')
            return 0;
        else
            return 1;
    }
    else if (board[1] == board[4] && board[4] == board[7])
    {
        if (board[2] == 'X')
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
    else if (board[0] != '1' && board[1] != '2' && board[2] != '3' && board[3] != '4' && board[4] != '5' && board[5] != '6' && board[6] != '7' && board[7] != '8' && board[8] != '9')
        return -1;
    else
        return -2;
}
int tic_tac_toe(char *global_name, char *global_username)
{
    char real_board[9], view_board[9];
    char player1[20], player2[20];
    int player1_score = 5, player2_score = 5;
    char mark[2] = {'X', 'O'};
    int winner;
    int active_player = rand() % 2;

    for (int i = 0; i < 9; i++)
    {
        real_board[i] = i + 49;
        view_board[i] = ' ';
    }
    print_intro();
    print_board(real_board);
    printf("Press any key to continue...");
    getch();

    system("cls");
    strcpy(player1, global_name);
    printf("Enter player 2 name: ");
    scanf("%s", player2);
    system("cls");

    do
    {
        int choice;
        printf("%s\n: %c", player1, mark[0]);
        printf("\n%s\n: %c", player2, mark[1]);
        char active_mark = mark[active_player];
        print_board(view_board);
        printf("%s's turn. Enter a number(position): ", (active_player == 0) ? player1 : player2);
        scanf("%d", &choice);

        if (choice >= 1 && choice <= 9 && real_board[choice - 1] != 'X' && real_board[choice - 1] != 'O')
        {
            view_board[choice - 1] = active_mark;
            real_board[choice - 1] = active_mark;
            active_player++;
            active_player = (active_player > 1) ? 0 : active_player;
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
        printf("\n\n\t\t\t\t\t%s wins\n\n", player1);
        player1_score += 5;
    }
    else if (winner == 1)
    {
        printf("\n\n\t\t\t\t\t%s wins\n\n", player2);
        player2_score += 5;
    }
    else
    {
        printf("\n\n\t\t\t\t\tGame draw\n\n");
    }
    return 0;
}
int main(int argc, char const *argv[])
{
    tic_tac_toe("tilak", "tilak");
    return 0;
}
