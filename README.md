
# Table of Contents

1.  [Introduction](#org1422f12)
2.  [Features](#org4537d38)
3.  [Technologies Used](#orgd8c02d5)
4.  [Getting Started](#org0cfcfff)
    1.  [Requirements](#orgafddc6e)
    2.  [Installation and Compilation](#orgfab678e)
    3.  [On Linux](#orgabbecb5)
5.  [Screenshots](#org235de33)
6.  [Contributions](#org9abc493)
7.  [Authors](#org24dda6d)
8.  [Licence](#org9595f2f)



<a id="org1422f12"></a>

# Introduction

This is my implementation of a simple ping pong game in C. It allows two players
to compete in a tabel tennis game while keeping track of scores. The games follows the rules
of ping pong. It ensures that a player wins by at least 2 points. The match is
won following a best of 5 games.


<a id="org4537d38"></a>

# Features

-   Score tracking for two players
-   Automatic handling of deuces
-   Easy installation both Linux and Windows systems


<a id="orgd8c02d5"></a>

# Technologies Used

-   C
-   Linux
-   SDL2
-   Windows


<a id="org0cfcfff"></a>

# Getting Started

The requirements and compilation steps described below are for a Linux Environment since the game was developed on
it. However, feel free to install the required packages if you wish to modify the code and compile on a different system.
To simply run the game without compiling, skip step 2 of the installation stage.


<a id="orgafddc6e"></a>

## Requirements

C compilers such as

-   GCC
-   Clang
-   MinGW(for Windows)

SDL2


<a id="orgfab678e"></a>

## Installation and Compilation

1.  Clone the repo:
    
        git clone https://github.com/fk2019/Ping_Pong.git
        cd Ping_Pong
2.  Compile the program and run the game
    
        make rebuild
        ./ping_pong.exe
3.  Play and enjoy the game


<a id="orgabbecb5"></a>

## On Linux

    ./ping_pong

On Windows

    ping_pong.exe


<a id="org235de33"></a>

# Screenshots

![img](./images/game_win.png "A game win")
A game win

![img](./images/match_win.png "A match win")
A match win


<a id="org9abc493"></a>

# Contributions

Please feel free to fork and make contributions to the game.


<a id="org24dda6d"></a>

# Authors

Francis is a skilled Software Engineer keen on making great programs. Reach out to [Francis](mailto:fkmuiruri8@gmail.com) for any opportunities and collaborations.


<a id="org9595f2f"></a>

# Licence

This project is licensed under the terms of the MIT license. Please see the [LICENSE](./LICENCE.txt) file for more details.

