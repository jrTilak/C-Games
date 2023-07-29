#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int generateComputerChoice() {
    // Generate a random number between 0 and 2
    // 0 - Rock, 1 - Paper, 2 - Scissors
    return rand() % 3;
}

int determineWinner(int playerChoice, int computerChoice) {
    // Returns:
    // 1 if the player wins
    // 0 if it's a draw
    // -1 if the computer wins

    if (playerChoice == computerChoice) {
        return 0; // Draw
    } else if ((playerChoice == 0 && computerChoice == 2) ||
               (playerChoice == 1 && computerChoice == 0) ||
               (playerChoice == 2 && computerChoice == 1)) {
        return 1; // Player wins
    } else {
        return -1; // Computer wins
    }
}

int main() {
    int playerChoice, computerChoice, result;
    char choices[3][10] = {"Rock", "Paper", "Scissors"};

    printf("Welcome to Rock-Paper-Scissors game!\n");
    printf("Enter your choice:\n");
    printf("0 - Rock\n1 - Paper\n2 - Scissors\n");

    // Seed the random number generator with the current time
    srand(time(NULL));

    while (1) {
        printf("\nEnter your choice (0, 1, or 2): ");
        scanf("%d", &playerChoice);

        if (playerChoice < 0 || playerChoice > 2) {
            printf("Invalid choice! Please choose again.\n");
            continue;
        }

        computerChoice = generateComputerChoice();

        printf("\nYou chose: %s\n", choices[playerChoice]);
        printf("Computer chose: %s\n", choices[computerChoice]);

        result = determineWinner(playerChoice, computerChoice);

        if (result == 0) {
            printf("It's a draw!\n");
        } else if (result == 1) {
            printf("Congratulations! You win!\n");
        } else {
            printf("Computer wins! Better luck next time!\n");
        }

        char playAgain;
        printf("\nDo you want to play again? (y/n): ");
        scanf(" %c", &playAgain);

        if (playAgain != 'y' && playAgain != 'Y') {
            break;
        }
    }

    printf("\nThank you for playing Rock-Paper-Scissors!\n");
    return 0;
}