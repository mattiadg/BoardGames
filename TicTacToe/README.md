# TicTacToe

TicTacToe is the easiest game in the world, for which it is possible to compute a brute force solution for every match.
The goal of this sub-project is write a first version of an "AI" based on evaluation and tree-search, and also to start
to apply engineering concepts typical of C++.

To meet the goals, this sub-project is divided in the following modules:
- Back-end
- Presentation
- Playing engine

The back-end stores the moves, checks their legality and checks end-game conditions.  
The presentation module manages the interaction with the user(s) and display of the board.  
The engine contains the logic of a brute-force agent that plays the game optimally. 
