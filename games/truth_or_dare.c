/*
========================================================================================
||                        Truth or Dare Game                                           ||
========================================================================================
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <conio.h>
#include <time.h>
#include <stdbool.h>

//========================== Preprocessor directives =======================================//

#define MAX_PLAYERS 5
#define MAX_QUESTIONS 100
#define MAX_QUESTION_LENGTH 200

//========================== Function Prototypes =======================================//

int loadQuestions(const char *filename, char questions[][MAX_QUESTION_LENGTH]);
void truth_or_dare(char *global_name, char *global_username);
void register_score(char *game, char *username, char *score);
void print_intro_truth_or_dare(char *name);

//========================== Function Definitions =======================================//

/*
    function name: truth_or_dare
    arguments: name and username of currently logged in user
    return type: void
    working mechanism: This function is to play truth or dare game. After the game is over, it
        will register the score of the user in the database.
*/
void truth_or_dare(char *global_name, char *global_username)
{
    // Variables
    char questions[MAX_QUESTIONS][MAX_QUESTION_LENGTH];
    char truth_qns[MAX_QUESTIONS][MAX_QUESTION_LENGTH];
    char dare_qns[MAX_QUESTIONS][MAX_QUESTION_LENGTH];
    int numPlayers, currentPlayer, currentRound, score[MAX_PLAYERS];
    char playerNames[MAX_PLAYERS][50], choice;
    int questionIndex;
    char acceptChoice = ' ';

    // show game desc
    print_intro_truth_or_dare(global_name);
    srand(time(0)); // Seed random number generator

    // Input number of players
    do
    {
        printf("Enter the number of players (2-5): ");
        scanf("%d", &numPlayers);

        if (numPlayers < 2 || numPlayers > MAX_PLAYERS)
        {
            system("cls");
            printf("Invalid number of players. Try Again.\n");
        }
    } while (numPlayers < 2 || numPlayers > MAX_PLAYERS);

    // Input player names and initialize scores
    system("cls");
    strcpy(playerNames[0], global_name);
    printf(" Enter the name of players except you: ");

    for (int i = 1; i < numPlayers; i++) // Input player names and initialize scores
    {
        scanf("%s", playerNames[i]);
        playerNames[i][0] = toupper(playerNames[i][0]);
        score[i] = 0;
    }

    // Load questions from files
    int truth_count = loadQuestions("./db/games/truth_or_dare/truths.txt", truth_qns);
    int dare_counts = loadQuestions("./db/games/truth_or_dare/dares.txt", dare_qns);

    // Shuffle player order
    for (int i = numPlayers - 1; i > 0; i--)
    {
        int j = rand() % (i + 1);
        char temp[50];
        strcpy(temp, playerNames[i]);
        strcpy(playerNames[i], playerNames[j]);
        strcpy(playerNames[j], temp);
    }

    // Game loop
    for (currentRound = 1; currentRound <= 3; currentRound++)
    {
        system("cls");
        printf("\n==================== Round %d ===========================\n", currentRound);

        for (currentPlayer = 0; currentPlayer < numPlayers; currentPlayer++) // Loop through players
        {

            do
            { // loop to jump to if player chooses invalid option
                printf("\n%s, choose Truth (T) or Dare (D): ", playerNames[currentPlayer]);
                scanf(" %c", &choice);
                choice = toupper(choice);

                // Check if player has chosen Truth/Dare before
                switch (choice)
                {

                // Truth
                case 'T':
                    questionIndex = rand() % truth_count;
                    printf("Truth: %s\n", truth_qns[questionIndex]);
                    printf("Press 'a' if accepted/completed  or 's' to skip: ");
                    scanf(" %c", &acceptChoice);
                    if (tolower(acceptChoice) != 's')
                    {
                        score[currentPlayer] += 5;

                        // Remove question from array
                        for (int i = questionIndex; i < truth_count - 1; i++)
                        {
                            strcpy(truth_qns[i], truth_qns[i + 1]);
                        }
                        truth_count--;
                    }
                    else
                    {
                        score[currentPlayer]--;
                    }

                    break;

                // Dare
                case 'D':
                    questionIndex = rand() % dare_counts;
                    printf("Dare: %s\n", dare_qns[questionIndex]);
                    printf("Press 'a' if accepted/completed or 's' to skip: ");
                    scanf(" %c", &acceptChoice);
                    if (tolower(acceptChoice) != 's')
                    {
                        score[currentPlayer] += 5;

                        // Remove question from array
                        for (int i = questionIndex; i < dare_counts - 1; i++)
                        {
                            strcpy(dare_qns[i], dare_qns[i + 1]);
                        }
                        dare_counts--;
                    }
                    else
                    {
                        score[currentPlayer]--;
                    }

                    break;

                // Invalid choice
                default:
                    printf("Invalid choice. \n");
                    break;
                }
                printf("\n");
            } while (choice != 'T' && choice != 'D');
        }
    }

    // Find winner
    int maxScore = score[0];
    int winnerIndex = 0;
    for (int i = 1; i < numPlayers; i++)
    {
        score[i] = score[i] < 0 ? 0 : score[i]; // Set negative scores to 0
        if (score[i] > maxScore)
        {
            maxScore = score[i];
            winnerIndex = i;
        }
    }
    // search for draw
    int draw = false;
    for (int i = 0; i < numPlayers; i++)
    {
        if (score[i] == maxScore && i != winnerIndex)
        {
            draw = true;
            break;
        }
        else
        {
            draw = false;
        }
    }

    // Display final scores
    system("cls");
    printf("================= Game Over =================\n");

    printf("| Winner: ");
    if (draw)
    {
        printf("%-34s", "None(Draw)");
    }
    else
    {
        printf("%-34s", playerNames[winnerIndex]);
    }
    printf("|\n");

    printf("---------------- Scores ---------------------\n");
    for (int i = 0; i < numPlayers; i++)
    {
        if (strcmp(playerNames[i], global_name) == 0)
        {
            char result[20];
            sprintf(result, "%d", score[i]);
            strcat(result, maxScore == score[i] ? "(Won)" : "(Lost)"); // if max score is equal to score[i] then add (won) else add (lost)
            register_score("Truth or Dare", global_username, result);
        }
        printf("| %-10s: %d", playerNames[i], score[i]);
        printf("%32s", "|\n");
    }
    printf("=============================================\n");
    printf("\nPress any key to continue...");
    getch();
    return;
}

/*
    *function name: print_intro_truth_or_dare
    arguments: name of player
    return type: void
    working mechanism: prints the intro of the game
*/
void print_intro_truth_or_dare(char *name)
{
    // intro of game
    printf("--------------------------------------------------------------------\n");
    printf("  Welcome %s to Truth or Dare\n", name);
    printf("--------------------------------------------------------------------\n");
    printf("%-67s", "| Truth or Dare is a game where players have to choose");
    printf("|\n");
    printf("%-67s", "| between answering a question truthfully or performing a dare.");
    printf("|\n");
    printf("--------------------------------------------------------------------\n");
    printf("Press any key to continue...");
    getch();
    system("cls");

    // how to play
    printf("------------------------------------------------------------------------------\n");
    printf(" How to play:\n");
    printf("------------------------------------------------------------------------------\n");
    printf("%-77s", "| 1. The game will start with a random player.");
    printf("|\n");
    printf("%-77s", "| 2. The player will be asked to choose between truth or dare.");
    printf("|\n");
    printf("%-77s", "| 3. If the player chooses truth, he/she will be asked a question.");
    printf("|\n");
    printf("%-77s", "| 4. If the player chooses dare, he/she will be asked to perform a dare.");
    printf("|\n");
    printf("%-77s", "| 5. If the player answers the question truthfully or performs the dare,");
    printf("|\n");
    printf("%-77s", "|      he/she will be awarded 1 point.");
    printf("|\n");
    printf("%-77s", "| 6. If the player refuses to answer the question or perform the dare,");
    printf("|\n");
    printf("%-77s", "|      he/she will not be awarded any points");
    printf("|\n");
    printf("%-77s", "| 7. The game will continue until all players have been asked a question");
    printf("|\n");
    printf("%-77s", "|      or performed a dare.");
    printf("|\n");
    printf("%-77s", "| 8. The player with the highest score wins.");
    printf("|\n");
    printf("------------------------------------------------------------------------------\n");
    printf("Press any key to continue...");
    getch();
    system("cls");
    return;
}

/*
    *function name: loadQuestions
    arguments: filename where questions are stored, a array to store questions
    return type: number of questions
    working mechanism: loads the questions from the file
*/
int loadQuestions(const char *filename, char questions[][MAX_QUESTION_LENGTH])
{
    FILE *file = fopen(filename, "r");
    if (file == NULL)
    {
        printf("Error opening file '%s'\n", filename);
        return 0;
    }
    int count = 0;
    while (fgets(questions[count], MAX_QUESTION_LENGTH, file))
    {
        // Remove newline characters from the question
        strtok(questions[count], "\n");
        count++;
        if (count == MAX_QUESTIONS)
        {
            break;
        }
    }
    fclose(file);
    return count;
}
