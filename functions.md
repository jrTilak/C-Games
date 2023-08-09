# Table of Contents
- [Table of Contents](#table-of-contents)
  - [Database/Auth Functions:](#databaseauth-functions)
  - [Game Functions:](#game-functions)
  - [Tic Tac Toe Functions:](#tic-tac-toe-functions)
  - [Truth or Dare Functions:](#truth-or-dare-functions)
  - [Rock Paper Scissors Functions:](#rock-paper-scissors-functions)
  - [Coin Flip Functions:](#coin-flip-functions)

## Database/Auth Functions:
1. `create_new_account` function:
   - Description: This function is responsible for creating a new user account by taking user details (name, username, and password) as input.
   - Arguments: `filename` - The file in which user details will be stored.
   - Working Mechanism: It prompts the user to enter their name, username, and password. It then calls the `create_user` function to create the new account, checks if the username already exists using the `is_username_exists` function, and displays appropriate messages based on the success or failure of account creation.

2. `create_user` function:
   - Description: This function creates a new user and stores it in the file.
   - Arguments: `filename` - The file in which user details will be stored, `name` - The name of the user, `username` - The chosen username for the user, `password` - The chosen password for the user.
   - Returns: `true` if the account is created successfully, `false` if account creation fails (e.g., if the username already exists).
   - Working Mechanism: It creates a new `User` struct with the provided name, username, and password. Then, it writes this struct into the specified file using binary mode. Before writing, it checks if the username already exists by calling the `is_username_exists` function.

3. `is_username_exists` function:
   - Description: This function checks if the given username exists in the file containing user details.
   - Arguments: `filename` - The file in which user details are stored, `username` - The username to check for existence.
   - Returns: `true` if the username exists in the file, `false` otherwise.
   - Working Mechanism: It opens the file in binary read mode and reads each `User` struct from the file one by one. It compares the `username` parameter with the `username` in each struct. If it finds a match, it returns `true`; otherwise, it returns `false`.

4. `login` function:
   - Description: This function handles user login by verifying the provided username and password.
   - Arguments: `filename` - The file in which user details are stored, `global_username` - A global variable to store the username of the logged-in user, `global_name` - A global variable to store the name of the logged-in user.
   - Returns: `true` if the login is successful, `false` otherwise.
   - Working Mechanism: It takes the input username and password from the user and then calls the `is_user_exists` function to check if the given username and password match any user's details in the file. If the login is successful, it sets the global variables `global_username` and `global_name` with the corresponding user details.

5. `is_user_exists` function:
   - Description: This function checks if the given username and password match any user's details in the file.
   - Arguments: `filename` - The file in which user details are stored, `username` - The username to check, `password` - The password to check.
   - Returns: `true` if the username and password match any user's details, `false` otherwise.
   - Working Mechanism: Similar to `is_username_exists` function, it opens the file in binary read mode, reads each `User` struct from the file one by one, and compares the `username` and `password` parameters with the corresponding fields in the structs. If it finds a match, it returns `true`; otherwise, it returns `false`.

6. `get_user` function:
   - Description: This function retrieves the name of a user based on their username.
   - Arguments: `username` - The username for which to retrieve the name, `name` - A variable to store the retrieved name.
   - Working Mechanism: It opens the file in binary read mode, reads each `User` struct from the file one by one, and compares the `username` parameter with the `username` in each struct. When it finds a match, it copies the corresponding `name` from the struct and stores it in the variable provided.

## Game Functions:

1. `game_menu` function:
   - Description: This function displays the game menu for a logged-in user.
   - Arguments: `global_name` - The name of the logged-in user, `global_username` - The username of the logged-in user.
   - Working Mechanism: It displays the game menu options for the user and takes their choice. Depending on the choice, it calls different game functions from separate game files (e.g., `tic_tac_toe`, `truth_or_dare`, `rock_paper_scissor`, `coin_flip`) or the `print_game_history` function to show the user's game history. It also allows the user to logout or exit the program.

2. `print_game_history` function:
   - Description: This function prints the game history for a user, showing their game scores and the date played.
   - Arguments: `username` - The username of the user for whom to display the game history.
   - Working Mechanism: It opens the corresponding game history file based on the username, reads the `Score` structs one by one, and prints the game name, score, and date played for each entry.


3. `exit_game` function:
    - Description: This function displays a message and exits the program with the provided exit code.
    - Arguments: `msg` - The message to be displayed before exiting, `code` - The exit code to return to the operating system.
    - Working Mechanism: It simply prints the provided message and then exits the program with the specified exit code.

4. `getCurrentDateTime` function:
    - Description: This function retrieves the current date and time in a formatted string.
    - Arguments: `dateTimeString` - A character array to store the date and time, `size` - The size of the array.
    - Working Mechanism: It gets the current time using the `time` function and then formats it as a string using the `localtime` and `strftime` functions. The formatted string is then stored in the provided `dateTimeString` array.

## Tic Tac Toe Functions:

1. `tic_tac_toe` function:
   - Description: This function is the main function for playing the Tic Tac Toe game. It allows two players to take turns marking a cell in a 3x3 grid until the game is over (either a win or a draw). After the game is over, it registers the score of the user in the database.
   - Arguments: `global_name` - The name of the currently logged-in user, `global_username` - The username of the currently logged-in user.
   - Working Mechanism: The function initializes the Tic Tac Toe board, prompts for the second player's name, and starts the game loop. In each iteration of the loop, it takes the current player's choice of cell and validates it. If the move is valid, it updates the board and checks if the game is over using the `is_over` function. The game loop continues until the game is over. After that, it displays the winner (or a draw) and registers the score using the `register_score` function.

2. `print_intro_tic_tac_toe` function:
   - Description: This function prints the introduction of the Tic Tac Toe game and the initial board with numbers to help the players choose their moves.
   - Arguments: `name` - The name of the player (currently logged-in user), `board` - The Tic Tac Toe board with numbers representing each cell.
   - Working Mechanism: It prints a welcome message, the rules of the game, and how to play. Then, it displays the initial board with cell numbers to guide the players. The function waits for a key press to continue.

3. `print_board` function:
   - Description: This function prints the Tic Tac Toe board.
   - Arguments: `board` - The Tic Tac Toe board to be displayed.
   - Working Mechanism: It takes the `board` as input and prints the current state of the Tic Tac Toe board with the 'X' and 'O' marks.

4. `is_over` function:
   - Description: This function checks if the Tic Tac Toe game is over (win or draw).
   - Arguments: `board` - The Tic Tac Toe board to be checked.
   - Returns: `-2` if the game is not over, `0` if 'X' wins, `1` if 'O' wins, `-1` if it's a draw.
   - Working Mechanism: The function checks for winning combinations in rows, columns, and diagonals. If any player ('X' or 'O') has three marks in a row, column, or diagonal, it returns the corresponding winner (0 for 'X' and 1 for 'O'). If all cells are filled, and no player has three marks in a row, it returns -1 to indicate a draw. If the game is not over, it returns -2.

## Truth or Dare Functions:

1. `truth_or_dare` function:
   - Description: This function is the main function for playing the Truth or Dare game. It allows multiple players to take turns choosing between Truth and Dare questions. Players receive points for answering truthfully or performing dares. After three rounds, the winner is determined based on the highest score. The function also registers the score of the user in the database.
   - Arguments: `global_name` - The name of the currently logged-in user, `global_username` - The username of the currently logged-in user.
   - Working Mechanism: The function starts by prompting the number of players and their names. It then loads Truth and Dare questions from files, shuffles the player order, and enters the game loop. In each round, each player takes a turn to choose between Truth and Dare. If the player accepts and completes the challenge, they are awarded 5 points. If they skip the challenge, they lose 1 point. After three rounds, the function determines the winner based on the highest score and displays the final scores. The score of the currently logged-in user is registered in the database using the `register_score` function.

2. `print_intro_truth_or_dare` function:
   - Description: This function prints the introduction of the Truth or Dare game.
   - Arguments: `name` - The name of the player (currently logged-in user).
   - Working Mechanism: It prints a welcome message and explains the rules and how to play the Truth or Dare game. The function waits for a key press to continue after each section.

3. `loadQuestions` function:
   - Description: This function loads questions from a file and stores them in the provided array.
   - Arguments: `filename` - The name of the file containing the questions, `questions` - The array to store the loaded questions.
   - Returns: The number of questions loaded from the file.
   - Working Mechanism: The function opens the file, reads each question line by line, removes newline characters, and stores them in the `questions` array. It then returns the total number of questions loaded from the file.

## Rock Paper Scissors Functions:

4. `generateComputerChoice` function:
   - Description: This function generates a random number between 0 and 2 to represent the computer's choice in Rock Paper Scissors. 0 corresponds to Rock, 1 to Paper, and 2 to Scissors.
   - Returns: The randomly generated computer choice (0, 1, or 2).

5. `determineWinner` function:
   - Description: This function compares the player's and computer's choices to determine the winner of a single round in Rock Paper Scissors.
   - Arguments: `playerChoice` - The choice of the player (0 for Rock, 1 for Paper, 2 for Scissors), `computerChoice` - The choice of the computer (0 for Rock, 1 for Paper, 2 for Scissors).
   - Returns: 1 if the player wins, 0 if it's a draw, and -1 if the computer wins.

6. `print_intro_rock_paper_scissor` function:
   - Description: This function prints the introduction and rules of the Rock Paper Scissors game.
   - Arguments: `name` - The name of the player (currently logged-in user).
   - Working Mechanism: It displays the rules and waits for a key press to continue after each section.

7. `rock_paper_scissor` function:
   - Description: This function is the main function for playing the Rock Paper Scissors game. It allows the player to choose Rock, Paper, or Scissors in each round and compete against the computer.
   - Arguments: `global_name` - The name of the currently logged-in user, `global_username` - The username of the currently logged-in user.
   - Returns: 0 when the game is over.
   - Working Mechanism: The function starts by displaying the introduction using the `print_intro_rock_paper_scissor` function. It enters a loop where the player can choose Rock, Paper, or Scissors ('r', 'p', or 's'). The computer's choice is generated, and the winner of each round is determined using the `determineWinner` function. The scores of the player and computer are updated accordingly. The game continues until the player decides to quit by pressing 'q'. After the game ends, the function displays the final score and registers the score of the currently logged-in user in the database using the `register_score` function.

## Coin Flip Functions:

1. `coin_flip` function:
   - Description: This function allows the player to play the Coin Flip game. The player is presented with a coin flip, and they have to guess whether it will land on Heads or Tails. If the player guesses correctly, they get a point, and if they guess incorrectly, they lose a point. The game continues until the player decides to quit by entering 'q'.
   - Arguments: `global_name` - The name of the currently logged-in user, `global_username` - The username of the currently logged-in user.
   - Returns: 0 when the game is over.
   - Working Mechanism: The function starts by displaying the introduction and rules of the Coin Flip game. It enters a loop where the player can make a guess by entering 'h' for Heads, 't' for Tails, or 'q' to quit. The computer then simulates the toss of a coin and generates either 'h' for Heads or 't' for Tails. If the player's guess matches the outcome, they get a point, and if not, they lose a point. The score is updated accordingly, and the game continues with the next round. The game ends when the player decides to quit by entering 'q'. After the game ends, the function displays the final score and registers the score of the currently logged-in user in the database using the `register_score` function.

---
---