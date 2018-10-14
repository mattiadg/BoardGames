# C++ Board Games
This repository is a container of two players board games with AI engine. The engines are not supposed to be state of 
the art, but they should work reasonably well. In fact the goal of this project is twofold:  
- Learn software development in C++ 
- Learn AI for games

The first game to be implemented will be TicTacToe, which is the easiest game around, especially to build an AI for. 
While gaining more experience with this project, new games will be added to explore more features of C++ for engineering 
and new game algorithms. 
At the moment, the most complex game to add is chess. We are not interested in games that can be solved only through 
a massive use of resources with deep learning.  

This code is meant for educational purpose, and thus anybody that shares the same goals should 
feel free to contribute or to use it under the license agreements.

## Hacktoberfest 2018
Hacktoberfest is the event running from October 1st to 31st. Everyone is encouraged to contribute to github 
repositories to win a T-shirt of the event.  
This repository wants to welcome developers that share the learning goals of the project with tasks that are easy to 
implement for people that read the code for the first time. There are [issues](https://github.com/mattiadg/BoardGames/issues)
 labeled Hacktoberfest for this purpose.  
We want to let you make a PR with small effort, but while learning something useful for you and for others.  
After the PR, go to [https://hacktoberfest.digitalocean.com/stats](https://hacktoberfest.digitalocean.com/stats) and 
check your stats! 

## Provisional list of games to support
- TicTacToe
- Backgammon
- Connect Four
- Reversi (multiple sizes)
- Bridge
- Poker (multiple formats)
- Chess

## Getting started
To install this software you only need a C++ compiler that supports C++11 and either g++ or cmake (or both). 

Clone the repository with 
```
git clone https://github.com/mattiadg/BoardGames.git
```
### Option 1: Use CMake
Create a build directory (preferably outside the source tree), and enter it.
````
mkdir build
cd build
````

Configure with cmake

#### Windows
````
cmake -G "Visual Studo 15 2017 Win64" ..
````
Open the generated `BoardGames.sln` file in the `build` directory and build in Visual Studio

#### Linux
````
cmake -DCMAKE_BUILD_TYPE=Debug <source location>
````

Build using `make`

### Option 2: Use Make
Enter into the directory of TicTacToe
```
cd BoardGames/TicTacToe
```

Use the Makefile to install
```
make tictactoe
```

Now you can run the executable and start playing!
