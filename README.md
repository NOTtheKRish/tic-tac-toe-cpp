# tic-tac-toe-cpp

5x5 Tic Tac Toe - using class and files in C++

[![Language Used](https://img.shields.io/badge/Language-C%2B%2B-success)](https://github.com/NOTtheKRish/tic-tac-toe-cpp)
[![Type](https://img.shields.io/badge/Type-Game-blue)](https://github.com/NOTtheKRish/tic-tac-toe-cpp)

## Contents

- ### viewScores

  - Global function
  - View all Previous Winners of the game
  - Reads data from file and prints for end-user
  - Returns void
  
- ### writeScores

  - Global function
  - Writes name of Winner into the file
  - Gets **Winner's name** as **parameter** and appends it into the file
  - Returns void
  
- ### change

  - Public member function of class TTT
  - Changes the board values after user's choice
  - Gets **choice** and **current player** as **parameter** and changes value
  - Returns **Mark of Current Player ( either X or O )** [char datatype]
  
- ### getNames

  - Public member function of class TTT
  - Get name of the Players about to play and store
  - Returns void

- ### checkWin

  - Public member function of class TTT
  - Checks if current status of the board is Win / Draw / Game still exists
  - Returns
      - **1** if **Win**
      - **0** if **Draw**
      - **-1** if **Game still Exists**
  
- ### drawboard

  - Public member function of class TTT
  - Prints the 5x5 Tic Tac Toe with positional values and Mark of players ( X or O ) at positions chosen by the players
  - Returns void
