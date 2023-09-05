#include <netinet/in.h> //structure for storing address information
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h> //for socket APIs
#include <sys/types.h>
#include <stdbool.h>
#include <string.h>

struct mailBox{
int num;
int player;
int compChoice;
bool gameOver;

};
char board[3][3] = { {'1','2','3'},{'4','5','6'},{'7','8','9'} };
    int occupied[9];  //vector array to hold occupied spots on board
    int playerChoice;
    int currentPlayer;
    char playerMark;
    int occSize = sizeof(occupied)/sizeof(occupied[0]);
    int occIndex =0;
    int playerWins;
    int playerLosses;
    int totalWins;
    int totalLosses;
 void printboard()
    {
      char a;
        printf("------------\n");
        for (int i = 0; i < 3; i++) {
    
            for (int j = 0; j < 3; j++) {
               
               // printf("%c",a);
                printf("| "); 
                printf("%c ", board[i][j]);
            }
            printf("\n");
            printf("------------\n");
        }
    }
    
    void checkPlayer() {
        if (currentPlayer == 1) {
            playerMark = 'X';
        }
        else {
            playerMark = 'O';
        }
    }
    bool checkMove(int num) {
    
        for (int i = 0; i < occSize; i++) {
            if (num == occupied[i]) {
                return false;
            }
        }
        if (occIndex == 9) {
            printf("Drawmee \n");
            return false;
        }
        return true;
    }
    void makeMove(int num, char mark) {
      //printf("%c", mark);
        switch (num) {
        case 1:
            board[0][0] = mark;
            break;
        case 2:
            board[0][1] = mark;
           //printf("%c", board[0][1]);
            break;
        case 3:
            board[0][2] = mark;
            break;
        case 4:
            board[1][0] = mark;
            break;
        case 5:
            board[1][1] = mark;
            break;
        case 6:
            board[1][2] = mark;
            break;
        case 7:
            board[2][0] = mark;
            break;
        case 8:
            board[2][1] = mark;
            break;
        case 9:
            board[2][2] = mark;
            break;
        default:
            printf("Invalid Option Please Try Again!\n");
            printf("%d\n",num);
        }
    
    }

bool isGameOver() {
   
    
        if (board[0][0] == board[0][1] && board[0][0] == board[0][2]) {
            if (board[0][0] == 'X') {
                printf("Player 1 Won!!! \n");
                playerWins++;
            }
            else {
                printf("The Computer Won!!! \n");
                playerLosses++;
            }
            
            return true;
        }
        else if (board[1][0] == board[1][1] && board[1][0] == board[1][2]) {
            if (board[1][0] == 'X') {
                printf("Player 1 Won!!! \n");
                playerWins++;
            }
            else {
                printf("The Computer Won!!! \n");
                playerLosses++;
            }
             
            return true;
        }
        else if (board[2][0] == board[2][1] && board[2][0] == board[2][2]) {
            if (board[2][0] == 'X') {
                printf("Player 1 Won!!! \n");
                playerWins++;
            }
            else {
                printf("The Computer Won!!! \n");
                playerLosses++;
            }
             
            return true;
        }
        else if (board[0][0] == board[1][0] && board[0][0] == board[2][0]) {
            if (board[0][0] == 'X') {
                printf("Player 1 Won!!! \n");
                playerWins++;
            }
            else {
                printf("The Computer Won!!! \n");
                playerLosses++;
            }
             
            return true;
        }
        else if (board[0][1] == board[1][1] && board[0][1] == board[2][1]) {
            if (board[0][1] == 'X') {
                printf("Player 1 Won!!! \n");
                playerWins++;
            }
            else {
                printf("The Computer Won!!! \n");
                playerLosses++;
            }
             
            return true;
        }
        else if (board[0][2] == board[1][2] && board[0][2] == board[2][2]) {
            if (board[0][2] == 'X') {
                printf("Player 1 Won!!! \n");
                playerWins++;
            }
            else {
                printf("The Computer Won!!! \n");
                playerLosses++;
            }
             
            return true;
        }
        else if (board[0][0] == board[1][1] && board[0][0] == board[2][2]) {
            if (board[0][0] == 'X') {
                printf("Player 1 Won!!! \n");
            }
            else {
                printf("The Computer Won!!! \n");
            }
             
            return true;
        }
        else if (board[0][2] == board[1][1] && board[0][2] == board[2][0]) {
            if (board[0][2] == 'X') {
                printf("Player 1 Won!!! \n");
            }
            else {
                printf("The Computer Won!!! \n");
            }
             
            return true;
        }
        else if (occIndex >= 9) {
            
            printf("DRAW \n");
             
            return true;
        }
     
        return false;
    }

 bool playAgain(){
      char answer[50];
      bool isResponseValid = false;
      printf("Would you like to play again?\n");
    
      do{
        fgets(answer, 50,stdin);
        if ( (strcmp(answer,"YES\n") == 0) || (strcmp(answer,"Yes\n")==0) ||             (strcmp(answer,"yes\n")==0)){
          
          isResponseValid = true;
          break;
        }else if ((strcmp(answer,"NO\n")==0) || (strcmp(answer,"No\n")==0) ||             (strcmp(answer,"no\n")==0)){
          isResponseValid = true;
          break;
        }else{
          isResponseValid = false;
        }
        printf("Invalid input! Try again: \n");
      }while(!(isResponseValid));
   
       
      if((strcmp(answer,"YES\n") ==0) || (strcmp(answer,"Yes\n")==0) ||             (strcmp(answer,"yes\n")==0)){
           return true;
         }
           return false;
    }

 void clientGameplay(FILE *fp,int compfd){
 
  struct mailBox parcel;
  int x;
  bool a; //play again answer
  
  playagain: 
  
 
   
  memset(occupied, 0, sizeof (occupied));
  occIndex =0;
  playerWins=0;
  playerLosses=0;
   
   board[0][0]='1';
   board[0][1]='2';
   board[0][2]='3';
   board[1][0]='4';
   board[1][1]='5';
   board[1][2]='6';
   board[2][0]='7';
   board[2][1]='8';
   board[2][2]='9';
   parcel.gameOver = false;
   send(compfd,&parcel,sizeof(parcel),0);

   char temp[20];
  while(!(isGameOver())) {
            printboard();
            currentPlayer = 1;
            checkPlayer();
            printf ("Choose An Open Space \n");
           
            fgets(temp,20,stdin);
            printf("\n");
          
            playerChoice = atoi(temp);
            printf("Player Move: %d\n",playerChoice);
            while (!(checkMove(playerChoice))) {
            printf("Space is not available! Try Again!\n"); 
            fgets(temp,20, stdin);
            printf("\n");
            playerChoice = atoi(temp);
        }
            
            occupied[occIndex]=playerChoice;
            occIndex++;
            
            makeMove(playerChoice, playerMark);
  
    if(isGameOver()){
      printboard();
      
      break; //exit gameplay while loop
    }
    //computer turn

    recv(compfd, &parcel, sizeof(parcel),0);
    while (!(checkMove(parcel.compChoice))) {
       
      recv(compfd, &parcel, sizeof(parcel),0);
    }
    currentPlayer=2;
    checkPlayer();
   
    printf("Computer Move: %d\n",parcel.compChoice);
    occupied[occIndex]=parcel.compChoice;
    occIndex++;
    makeMove(parcel.compChoice, playerMark);
  
   
  send (compfd, &parcel, sizeof(parcel),0);  

   printf("\n");
  }
   totalWins+=playerWins;
   totalLosses+=playerLosses;
    a=playAgain();
   
    if (a==true){
      
      goto playagain;
    }else{
    
      goto gameover;
   }
  

gameover:
 printf("GAME OVER :) \n");
 printf("Player Wins: %d\t\t",totalWins);
 printf("Player Losses: %d\n",totalLosses);
  parcel.gameOver=true;
  send(compfd,&parcel,sizeof(parcel),0);
      return;
 }




int main(int argc, char const* argv[])
{
  struct mailBox open;
    int sockD = socket(AF_INET, SOCK_STREAM, 0);
  
    struct sockaddr_in servAddr;
  
    servAddr.sin_family = AF_INET;
    servAddr.sin_port
        = htons(9001); // use some unused port number
    servAddr.sin_addr.s_addr = INADDR_ANY;
  
    int connectStatus
        = connect(sockD, (struct sockaddr*)&servAddr,
                  sizeof(servAddr));
  
    if (connectStatus == -1) {
        printf("Trouble connecting to server...\n");
    }
  
    else {
        char strData[255];
        open.gameOver=false;
        recv(sockD, &open, sizeof(open), 0);
        int x = open.num;
       // printf("Message: %d\n", x);
      printf("WELCOME TO TIC TAC TOE\n");
      while(!(isGameOver())){
        
         clientGameplay(stdin,sockD);
      }


    }
  
    return 0;
}
