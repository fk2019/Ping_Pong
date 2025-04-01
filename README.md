
# Table of Contents

1.  [Introduction](#org9c74dd2)
2.  [Features](#org5cc5887)
3.  [Technologies Used](#org883770b)
4.  [Getting Started](#orgaef7a83)
    1.  [Requirements](#orgf8b4f1d)
    2.  [Installation and Compilation](#org2ae6681)
5.  [Screenshots](#org7e0e47d)
6.  [Contributions](#org7a36d07)
7.  [Authors](#orge4bf195)
8.  [Licence](#org48a0337)



<a id="org9c74dd2"></a>

# Introduction

This is my implementation of a simple ping pong game in C. It allows two players
to compete in a tabel tennis game while keeping track of scores. The games follows the rules
of ping pong. It ensures that a player wins by at least 2 points. The match is
won following a best of 5 games.


<a id="org5cc5887"></a>

# Features

-   Score tracking for two players
-   Automatic handling of deuces
-   Easy installation both Linux and Windows systems


<a id="org883770b"></a>

# Technologies Used

-   C
-   Linux
-   SDL2
-   Windows


<a id="orgaef7a83"></a>

# Getting Started

The requirements and compilation steps described below are for a Linux Environment since the game was developed on
it. However, feel free to install the required packages if you wish to modify the code and compile on a different system.
To simply run the game without compiling, skip step 2 of the installation stage.


<a id="orgf8b4f1d"></a>

## Requirements

C compilers such as

-   GCC
-   Clang
-   MinGW(for Windows)

SDL2


<a id="org2ae6681"></a>

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


<a id="org7e0e47d"></a>

# Screenshots

![img](./images/game_win.png "A game win")
A game win

![img](./images/match_win.png "A match win")
A match win


<a id="org7a36d07"></a>

# Contributions

Please feel free to fork and make contributions to the game.


<a id="orge4bf195"></a>

# Authors

Francis is a skilled Software Engineer keen on making great programs. Reach out to [Francis](mailto:fkmuiruri8@gmail.com) for any opportunities and collaborations.


<a id="org48a0337"></a>

# Licence

This project is licensed under the terms of the MIT license. Please see the [LICENSE](./LICENCE.txt) file for more details.

