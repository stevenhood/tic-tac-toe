Tic-tac-toe README
==================
by Steven Hood, last edit 17.02.2013

- A simple text-based console game written in C source code.

- Project started on 15th February 2013.

Development tools
-----------------

- GNU Emacs 23

- Notepad++ (used to reformat source code)

- GNU Project C Compiler (gcc)


HOW TO PLAY
===========

Intro.
------

  "Tic-tac-toe" or "Noughts and crosses" is based on the classic pencil-and-paper game of the same name where two players, O and X, take turns marking spaces in a 3x3 grid. The player who succeeds in placing three marks in a horizontal, vertical or diagonal row wins the game.

Playing the game
----------------

  Compile the C source file tictactoe.c using a compiler (such as gcc) and run the executable file in a terminal. The game will start, displaying the initial state of the game, which is the empty board. Players will be referred to as "Player 1 (Noughts)" and "Player 2 (Crosses)" during gameplay.

  Two players will take turns to input coordinates as to where they wish to place a mark. Coordinates are written in the form "x,y" where x is the column and y is the row. The program will only accept two integers separated by a comma. Once you have entered your coordinates, press the Enter/Return key. A new board will be displayed below with the updated spaces.

   1,1 | 2,1 | 3,1
   1,2 | 2,2 | 3,2
   1,3 | 2,3 | 3,3

  Coordinates can range from 1,1 to 3,3. Any values higher or lower will be caught as invalid by the program.

Stalemates
----------

  If all nine places have been filled and neither player has placed three marks in a row, the game has ended in a stalemate.
