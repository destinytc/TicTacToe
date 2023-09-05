#include <netinet/in.h> //structure for storing address information
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h> //for socket APIs
#include <sys/types.h>
#include <stdbool.h>
#include <time.h>

struct mail{
int num;
int player;
int compChoice;
bool gameOver;

};

int occupied[9];
 int occSize = sizeof(occupied)/sizeof(occupied[0]);
int occIndex =0;
char playerMark;
int currentPlayer;

/*
~~~~~~~~~~~~~~~~~~~~~~~~~~~GAME FUNCTIONS~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
*/
 
bool checkMove(int num) {
    
        for (int i = 0; i < occSize; i++) {
            if (num == occupied[i]) {
                return false;
            }
        }
        if (occIndex == 9) {
            printf("Draw \n");
            return false;
        }
        return true;
    }

int computerMove() {
        if (occIndex == 9) {
            return 0;
        }
        srand(time(0));
        int computerChoice;
        computerChoice = (rand() % 9) + 1;
        while (!(checkMove(computerChoice))) {
            computerChoice = (rand() % 9) + 1;
        }
     
        printf("Im playing\n");
    return computerChoice;
    }

 
/*----------------------------------------------------------------------*/
void computer (int playerfd, int compfd){

 
  struct mail sendMail; 

  
  printf("%d\n",sendMail.gameOver);
  while(!(sendMail.gameOver)){
   
  
    sendMail.player=2;
    
   sendMail.compChoice= computerMove();
    
    printf("Computer move: %d\n",sendMail.compChoice);
    currentPlayer = 1;
    sendMail.player =1;
   
    send(playerfd, &sendMail, sizeof(sendMail),0);
    printf("I played\n");
   
    printf("%d\n",sendMail.gameOver);
  }

   
}


int main(int argc, char const* argv[])
{
  struct mail boost;
 
    // create server socket similar to what was done in
    // client program
    int servSockD = socket(AF_INET, SOCK_STREAM, 0);
    
    boost.gameOver = false;
    // define server address
    struct sockaddr_in servAddr;
  
    servAddr.sin_family = AF_INET;
    servAddr.sin_port = htons(9001);
    servAddr.sin_addr.s_addr = INADDR_ANY;
  
    // bind socket to the specified IP and port
    bind(servSockD, (struct sockaddr*)&servAddr,
         sizeof(servAddr));
  
    // listen for connections
    listen(servSockD, 1);
  
    // integer to hold client socket.
    int clientSocket = accept(servSockD, NULL, NULL);
    
   send(clientSocket, &boost, sizeof(boost), 0);

  while(1){
    computer(clientSocket, servSockD);
  }
    return 0;
}
