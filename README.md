
# Table of Contents

1.  [Introduction](#org45e5b52)
2.  [Features](#org6eb0e98)
3.  [Technologies Used](#orga4d4e6a)
4.  [Getting Started](#org86b4817)
    1.  [Requirements](#orgff9088d)
    2.  [Installation and Compilation](#orgd3ecf91)
5.  [Screenshots](#org08ac908)
6.  [Contributions](#org3ebd992)
7.  [Authors](#org9e69976)
8.  [Licence](#orgc745610)



<a id="org45e5b52"></a>

# Introduction

This is my implementation of a simple ping pong game in C. It allows two players
to compete in a tabel tennis game while keeping track of scores. The games follows the rules
of ping pong. It ensures that a player wins by at least 2 points. The match is
won following a best of 5 games.


<a id="org6eb0e98"></a>

# Features

-   Score tracking for two players
-   Automatic handling of deuces
-   Easy installation both Linux and Windows systems


<a id="orga4d4e6a"></a>

# Technologies Used

-   C
-   Linux
-   SDL2
-   Windows


<a id="org86b4817"></a>

# Getting Started

The requirements and compilation steps described below are for a Linux Environment since the game was developed on
it. However, feel free to install the required packages if you wish to modify the code and compile on a different system.
To simply run the game without compiling, skip step 2.


<a id="orgff9088d"></a>

## Requirements

C compilers such as

-   GCC
-   Clang
-   MinGW(for Windows)

SDL2


<a id="orgd3ecf91"></a>

## Installation and Compilation

1.  Clone the repo:
    
        git clone https://github.com/fk2019/Ping_Pong.git
        cd Ping_Pong
2.  Compile the program and run the game
    
        make rebuild
        ./game.exe
3.  Play and enjoy the game

On Linux:

    ./game

On Windows

    game.exe


<a id="org08ac908"></a>

# Screenshots

![img](./images/game_win.png "A game win")
A game win

![img](./images/match_win.png "A match win")
A match win


<a id="org3ebd992"></a>

# Contributions

Please feel free to fork and make contributions to the game.


<a id="org9e69976"></a>

# Authors

Francis is a skilled Software Engineer keen on making great programs. Reach out to [Francis](mailto:fkmuiruri8@gmail.com) for any opportunities and collaborations.


<a id="orgc745610"></a>

# Licence

This project is licensed under the terms of the MIT license. Please see the [LICENSE](./LICENCE.txt) file for more details.

