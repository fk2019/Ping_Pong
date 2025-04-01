
# Table of Contents

1.  [Introduction](#org4421df7)
2.  [Features](#org4ea26f7)
3.  [Technologies Used](#org6f5ed5b)
4.  [Getting Started](#org4427260)
    1.  [Requirements](#org8441e21)
    2.  [Installation and Compilation](#orgba2edd0)
5.  [Screenshots](#orgdbe9e07)
6.  [Contributions](#org5b0a615)
7.  [Authors](#org9fdc89c)
8.  [Licence](#org2c120f1)



<a id="org4421df7"></a>

# Introduction

This is my implementation of a simple ping pong game in C. It allows two players
to compete in a tabel tennis game while keeping track of scores. The games follows the rules
of ping pong. It ensures that a player wins by at least 2 points. The match is
won following a best of 5 games.


<a id="org4ea26f7"></a>

# Features

-   Score tracking for two players
-   Automatic handling of deuces
-   Easy installation both Linux and Windows systems


<a id="org6f5ed5b"></a>

# Technologies Used

-   C
-   Linux
-   SDL2
-   Windows


<a id="org4427260"></a>

# Getting Started

The requirements and compilation steps described below are for a Linux Environment since the game was developed on
it. However, feel free to install the required packages if you wish to modify the code and compile on a different system.
To simply run the game without compiling, skip step 2 of the installation stage.


<a id="org8441e21"></a>

## Requirements

C compilers such as

-   GCC
-   Clang
-   MinGW(for Windows)

SDL2


<a id="orgba2edd0"></a>

## Installation and Compilation

1.  Clone the repo:
    
        git clone https://github.com/fk2019/Ping_Pong.git
        cd Ping_Pong
2.  Compile the program and run the game
    
        make rebuild
        ./ping_pong.exe
3.  Play and enjoy the game
    On Linux:
    
        ./ping_pong
    
    On Windows
    
        ping_pong.exe


<a id="orgdbe9e07"></a>

# Screenshots

![img](./images/game_win.png "A game win")
A game win

![img](./images/match_win.png "A match win")
A match win


<a id="org5b0a615"></a>

# Contributions

Please feel free to fork and make contributions to the game.


<a id="org9fdc89c"></a>

# Authors

Francis is a skilled Software Engineer keen on making great programs. Reach out to [Francis](mailto:fkmuiruri8@gmail.com) for any opportunities and collaborations.


<a id="org2c120f1"></a>

# Licence

This project is licensed under the terms of the MIT license. Please see the [LICENSE](./LICENCE.txt) file for more details.

