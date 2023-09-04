# Tic Tac Toe
This project is a rendition of Tic Tac Toe that allows the user to play the 
game against a computer through a client-server architecture.

## Table of Contents
* [General Info](#general-info)
* [Technologies](#technologies)
* [Setup](#setup)

## General Info
### Description:
Tic Tac Toe is a classic game where two players compete to get either 
three O's or X's in a row vertically, horizontally, or diagonally. 
The program I created allows a user to play the game of Tic Tac Toe
against a computer. The gameplay is facilitated using a TCP client-sever
architecture. 

### How To Play
As the player, you will get the option to make the first move every round. Your designated player mark is the 'X'. The computer moves will be repesented using the 'O'. Each spot on the game board is represented by a number 1-9. Enter a number within the range to mark your spot on the board. If the spot selected is not available, you will be prompted to remake a selection until you choose an available spot. After you make your selection, the computer will make its own move and return the power to make a move back to you. This pattern will continue to loop until either a the player or computer has won or the game ends in a draw. In order to win, either the player or the computer must align their respective mark in a uninterupted sequence of three either vertically, horizontally or diagonally. The verdict of a draw comes when all spots on the board have been filled, but neither the player or computer was able to achieve three in a row.
Once the game is over, the player will be asked if they would like to play again. If yes, a new gameboard will be presented to play on. If no, the program will exit.

## Technologies
Project is created with:
* Linux version: 6.2.0-1012-gcp
* C version: 11.0
* GCC version: 11.3.0

## Setup
### Run:
```
$ gcc server.c - server  
$ gcc client.c -o client  
$ ./server
$ ./client
```
