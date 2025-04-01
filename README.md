
# Table of Contents

1.  [Introduction](#org03594b1)
2.  [Features](#org882471b)
3.  [Technologies Used](#orgd25c7f8)
4.  [Getting Started](#orge215d7d)
    1.  [Requirements](#org6102ac4)
    2.  [Installation and Compilation](#orgcb50129)
5.  [Screenshots](#orgf49da68)
6.  [Contributions](#org13a132d)
7.  [Authors](#org441690b)
8.  [Licence](#orgd0e7365)



<a id="org03594b1"></a>

# Introduction

This is my implementation of a simple ping pong game in C. It allows two players
to compete in a tabel tennis game while keeping track of scores. The games follows the rules
of ping pong. It ensures that a player wins by at least 2 points. The match is
won following a best of 5 games.


<a id="org882471b"></a>

# Features

-   Score tracking for two players
-   Automatic handling of deuces
-   Easy installation both Linux and Windows systems


<a id="orgd25c7f8"></a>

# Technologies Used

-   C
-   Linux
-   SDL2
-   Windows


<a id="orge215d7d"></a>

# Getting Started

The requirements and compilation steps described below are for a Linux Environment since the game was developed on
it. However, feel free to install the required packages if you wish to modify the code and compile on a different system.
To simply run the game without compiling, skip step 2 of the installation stage.


<a id="org6102ac4"></a>

## Requirements

C compilers such as

-   GCC
-   Clang
-   MinGW(for Windows)

SDL2


<a id="orgcb50129"></a>

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


<a id="orgf49da68"></a>

# Screenshots

![img](./images/game_win.png "A game win")
A game win

![img](./images/match_win.png "A match win")
A match win


<a id="org13a132d"></a>

# Contributions

Please feel free to fork and make contributions to the game.


<a id="org441690b"></a>

# Authors

Francis is a skilled Software Engineer keen on making great programs. Reach out to [Francis](mailto:fkmuiruri8@gmail.com) for any opportunities and collaborations.


<a id="orgd0e7365"></a>

# Licence

This project is licensed under the terms of the MIT license. Please see the [LICENSE](./LICENCE.txt) file for more details.

