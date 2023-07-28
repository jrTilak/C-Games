#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <conio.h>
#include <time.h>

// preprocessor directives for constants
#define MAX_PLAYERS 5
#define MAX_QUESTIONS 100
#define MAX_QUESTION_LENGTH 200

// Function prototypes
int loadQuestions(const char *filename, char questions[][MAX_QUESTION_LENGTH]);
int truth_or_dare(char *global_name, char *global_username);
void register_score(char *game, char *username, char *score);

// Function to play the game
int truth_or_dare(char *global_name, char *global_username)
{
    // Variables
    char questions[MAX_QUESTIONS][MAX_QUESTION_LENGTH];
    char truth_qns[MAX_QUESTIONS][MAX_QUESTION_LENGTH];
    char dare_qns[MAX_QUESTIONS][MAX_QUESTION_LENGTH];
    int numPlayers, currentPlayer, currentRound, score[MAX_PLAYERS];
    char playerNames[MAX_PLAYERS][50], choice;

    // show game desc
    printf(" Title: Truth or Dare\n");
    printf(" Description: Truth or Dare is a game where players have to choose between\n");
    printf(" answering a question truthfully or performing a dare.\n");
    printf(" Maximum Players: 5\n");
    printf(" Minimum Players: 2\n");
    printf(" Total Rounds: 3\n");
    printf(" Press any key to continue...");
    getch();
    system("cls");

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
    for (int i = 1; i < numPlayers; i++)
    {
        scanf("%s", playerNames[i]);
        playerNames[i][0] = toupper(playerNames[i][0]);
        score[i] = 0;
    }

    // Load questions from files
    int truth_count = loadQuestions("./db/games/truth_or_dare/truths.txt", truth_qns);
    int dare_counts = loadQuestions("./db/games/truth_or_dare/dares.txt", dare_qns);
    // int truth_count = loadQuestions("../db/games/truth_or_dare/truths.txt", truth_qns);
    // int dare_counts = loadQuestions("../db/games/truth_or_dare/dares.txt", dare_qns);

    // Shuffle player order
    for (int i = numPlayers - 1; i > 0; i--)
    {
        int j = rand() % (i + 1);
        char temp[50];
        strcpy(temp, playerNames[i]);
        strcpy(playerNames[i], playerNames[j]);
        strcpy(playerNames[j], temp);
    }

    // Play game
    for (currentRound = 1; currentRound <= 3; currentRound++)
    {
        system("cls");
        printf("\n--- Round %d ---\n", currentRound);

        for (currentPlayer = 0; currentPlayer < numPlayers; currentPlayer++)
        {
        choose:
            int questionIndex;
            char acceptChoice;

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
                goto choose;
                break;
            }
        }
    }

    // Find winner
    int maxScore = score[0];
    int winnerIndex = 0;
    for (int i = 1; i < numPlayers; i++)
    {
        score[i] = score[i] < 0 ? 0 : score[i];
        if (score[i] > maxScore)
        {
            maxScore = score[i];
            winnerIndex = i;
        }
    }
    system("cls");
    printf("\n--- Game Over ---\n");
    printf("Winner: %s\n", playerNames[winnerIndex]);

    // Display final scores
    printf("\n--- Final Scores ---\n");
    for (int i = 0; i < numPlayers; i++)
    {
        if (strcmp(playerNames[i], global_name) == 0)
        {
            char result[20];
            sprintf(result, "%d", score[i]);
            strcat(result, maxScore == score[i] ? "(Won)" : "(Lost)"); // if max score is equal to score[i] then add (won) else add (lost)
            register_score("Truth or Dare", global_username, result);
        }
        printf("%s: %d\n", playerNames[i], score[i]);
    }
    printf("\nPress any key to continue...");
    getch();
    return 0;
}

// Function to load questions from the file into an array
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
