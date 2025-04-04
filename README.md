
# Table of Contents

1.  [Introduction](#org7b82a03)
2.  [Features](#org55dc41e)
3.  [Technologies Used](#org2794ba1)
4.  [Getting Started](#orgc3aacfa)
    1.  [Requirements](#org6754182)
    2.  [Installation and Compilation](#org784085e)
5.  [Screenshots](#org2bfcefc)
6.  [Contributions](#org61993db)
7.  [Authors](#orgb63348b)
8.  [Licence](#org434323f)



<a id="org7b82a03"></a>

# Introduction

This is my implementation of a simple ping pong game in C. It allows two players
to compete in a tabel tennis game while keeping track of scores. The games follows the rules
of ping pong. It ensures that a player wins by at least 2 points. The match is
won following a best of 5 games.


<a id="org55dc41e"></a>

# Features

-   Score tracking for two players
-   Automatic handling of deuces
-   Easy installation both Linux and Windows systems


<a id="org2794ba1"></a>

# Technologies Used

-   C
-   Linux
-   SDL2
-   Windows


<a id="orgc3aacfa"></a>

# Getting Started

The requirements and compilation steps described below are for a Linux Environment since the game was developed on
it. However, feel free to install the required packages if you wish to modify the code and compile on a different system.
To simply run the game without compiling, skip step 2 of the installation stage.


<a id="org6754182"></a>

## Requirements

C compilers such as

-   GCC
-   Clang
-   MinGW(for Windows)

SDL2


<a id="org784085e"></a>

## Installation and Compilation

1.  Clone the repo:
    
        git clone https://github.com/fk2019/Ping_Pong.git
        cd Ping_Pong
2.  Compile the program and run the game
    
        make rebuild
        ./ping_pong.exe
3.  Play and enjoy the game

On Linux

    ./ping_pong

On Windows

    ping_pong.exe


<a id="org2bfcefc"></a>

# Screenshots

![img](./images/game_win.png "A game win")
A game win

![img](./images/match_win.png "A match win")
A match win


<a id="org61993db"></a>

# Contributions

Please feel free to fork and make contributions to the game.


<a id="orgb63348b"></a>

# Authors

Francis is a skilled Software Engineer keen on making great programs. Reach out to [Francis](mailto:fkmuiruri8@gmail.com) for any opportunities and collaborations.


<a id="org434323f"></a>

# Licence

This project is licensed under the terms of the MIT license. Please see the [LICENSE](./LICENCE.txt) file for more details.

