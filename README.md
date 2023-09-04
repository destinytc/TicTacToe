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

## Technologies
Project is created with:
* Linux version: 6.2.0-1012-gcp
* C version: 11.0
* GCC version: 11.3.0

## Setup
### Run:
$ gcc server.c - server  
$ gcc client.c -o client  
$ ./server
$ ./client
