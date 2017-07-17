//I declare that the attached assignment is wholly my own work in accordance with
//Seneca Academic Policy. No part of this assignment has been copied manually or
//electronically from any other source (including web sites) or distributed to
//other students.
//Name : Alejandro Mesa
//Student ID : 038515151

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX 256
#define LOW 4 //Boardsize (non-inclusive)
#define HIGH 15 //Boardsize (inclusive)

//Structure Player

struct Player{

    char playerName;
    int playerScore;
    int prizeCount;
    int playerPosition;
    int playerPrizes[10];

}players[7];

//PROTOTYPES
char getTileType(unsigned int index, struct Player players[7], unsigned int playerCount);
void displayBoard(unsigned int boardSize, struct Player players[7], unsigned int playerCount);
void initPlayer(struct Player *player);
void playGame(unsigned int boardSize, struct Player players[7], unsigned int playerCount);

void winPrize(struct Player *player); //
void winGrandPrize(struct Player *player); //
int loseItem(struct Player *player); //
int checkout(struct Player *player); //

int getValidInteger(int low, int high);
char getValidCharacter(char low, char high);
int getRandom(int low, int high);
unsigned int playerRoll();

//MILESTONE4 PROTOTYPES
void displayInstructions(void);
void addToLeaderboard (int game, struct Player* winner);
void displayHighestScore (void);

char tile(struct Player players[7],unsigned int playerCount);

//MAIN PROGRAM
int main(){

    struct Player players[7]; //array of 8 players
    //Variables
    char menu_choice;
    int flag = 0;
    int another_flag = 0;
    //srand(time(NULL)); //Rand

    unsigned int playerCount = 0;
    unsigned int boardSize = 0;

    int i;

    //Starting Program
    printf("Welcome to CHECKOUT The Game\n");
    printf("Main Menu\n");

//Do-while that runs until q is selected
do{

    //Do for error checking menu
    do{
    printf("p-(p)lay q-(q)uit r-inst(r)uctions s-HI(s)core: ");
    scanf(" %c",&menu_choice);
    if(menu_choice=='p'||menu_choice=='q'||menu_choice=='r'||menu_choice=='s')
        flag=1;
    if(flag==0)
        printf("Invalid choice\n");
    }while(flag==0);

    //If play selected start the game
    if(menu_choice=='p'){

        do{
        printf("Enter number of players (1-8): ");
        scanf(" %d",&playerCount);
        if(playerCount>=1 && playerCount<9)
            another_flag=1;
        if(another_flag==0)
            printf("Invalid choice\n");
        }while(another_flag==0);

        //Get playerName(s) and initialize each player
        for(i=0;i<playerCount;i++){

            initPlayer(&players[i]);

        }

        boardSize = getValidInteger(LOW,HIGH); //Get BoardSize (non inclusive, inclusive)
        playGame(boardSize, players, playerCount); //Initialize the game

    }
    //If High Score selected
    if(menu_choice=='s'){

        printf("__\n");
        printf("  \\_______\n");
        printf("   \\++++++|\n");
        printf("    \\=====|\n");
        printf("    0---  0\n\n");

        int high_score = 0;
        int high_player = 0;

        for(i=0;i<playerCount;i++){


            if(players[i].playerScore > high_score){

                high_score = players[i].playerScore;
                high_player = i;

            }

        }

        printf("HI SCORE: %d\tPlayer Name: %c\n",players[high_score].playerScore,players[high_score].playerName);

    }
    //If Instructions selected
    if(menu_choice=='r'){



    }
    //If Quit selected
    if(menu_choice=='q'){
        printf("This game is much more fun than bash...\n");
    }

}while(menu_choice!='q');

    return 0;
}


//FUNCTIONS
//Get the Tile type depending on playerPosition and index
char getTileType(unsigned int index, struct Player players[7], unsigned int playerCount){

    char tile;


    if(index==players[playerCount].playerPosition)
        tile=players[playerCount].playerName;
    else if(index==0)
        tile='C';
    else if(index%7==0)
        tile='G';
    else if(index%5==0)
        tile='L';
    else if(index%3==0)
        tile='W';
    else
        tile = ' ';

    return tile;

}

//Get the tile type function to check  playerPosition letter without passing all the other arguments from the previous function
char tile(struct Player players[7],unsigned int playerCount){

    char tile;
    if(players[playerCount].playerPosition==0)
        tile='C';
    else if(players[playerCount].playerPosition%7==0)
        tile='G';
    else if(players[playerCount].playerPosition%5==0)
        tile='L';
    else if(players[playerCount].playerPosition%3==0)
        tile='W';
    else
        tile = ' ';

    return tile;

}

//FUNCTIONS USING STRUCT
//======================
//DisplayBoard - Algorithms to print the board with player position
void displayBoard(unsigned int boardSize, struct Player players[7], unsigned int playerCount){
     int i;



     int middle_space = boardSize-2; //this is the middle space on the row on the center

     int first_left = boardSize-1+(boardSize-1)+(boardSize-1)+(boardSize-2); //this is the first number on the left after finishing first line (left column)
     int first_right = boardSize; //this is the first number on the right after finishing top row (right column)

     int rows = boardSize-2; //this is the rows not inlcuding top row or bottom row
     int first_last_row = boardSize + (boardSize-1) + (boardSize-1); //this is the first number of the last row which will be regressive on the loop

     //If boardSize is 1
    if(boardSize==1){
        printf(" ___ ");
        printf("\n");
        printf("| %c |",getTileType(0,players,playerCount));

        printf("\n");

        printf("|___|");
        printf("\n");


        }//Sizes > 1
    else{
     ////FIRST ROW PRINTING
     //Printing top part
     for(i=0;i<boardSize;i++){

        printf(" ___ ");

     }
     printf("\n");
     //Printing mid part
     for(i=0;i<boardSize;i++){

        printf("| %c |",getTileType(i,players,playerCount));

     }
     printf("\n");
     //Printing bottom part
     for(i=0;i<boardSize;i++){

        printf("|___|");

     }
     printf("\n");


     ////MID ROWS PRINTING

     for(i=0;i<rows;i++){
        int y; //For the inner loops
        //Printing top part
        printf(" ___ ");
        for(y=0;y<middle_space;y++){
                printf("     ");
        }
        printf(" ___ ");
        printf("\n");
        //Printing mid part
        printf("| %c |",getTileType(first_left,players,playerCount));
        for(y=0;y<middle_space;y++){
                printf("     ");
        }
        printf("| %c |",getTileType(first_right,players,playerCount));
        printf("\n");
        //Printing bottom part
        printf("|___|");
        for(y=0;y<middle_space;y++){
                printf("     ");
        }
        printf("|___|");
        printf("\n");

        //Decresing the count of the left column and increasing the count of right column
        first_left--;
        first_right++;


     }






     ////LAST ROW PRINTING
     //Printing top part
     for(i=first_last_row-1;i>(boardSize+(boardSize-2)-1);i--){

        printf(" ___ ");

     }
     printf("\n");
     //Printing mid part
     for(i=first_last_row-1;i>(boardSize+(boardSize-2)-1);i--){

        printf("| %c |",getTileType(i,players,playerCount));

     }
     printf("\n");
     //Printing bottom part
     for(i=first_last_row-1;i>(boardSize+(boardSize-2)-1);i--){

        printf("|___|");

     }
     printf("\n");



     }

}

//Initialize player
void initPlayer(struct Player* player){

    //Initiliaze player stats
    player->playerScore = 0;
    player->playerPrizes[7] = 0;
    player->prizeCount = 0;
    player->playerPosition = 0;

    player->playerName = getValidCharacter(33,64);
    //Values like ! " # $ % & ' ( ) * + , - . / @   ASCI Codes


}

//Play Game
void playGame(unsigned int boardSize, struct Player players[7], unsigned int playerCount){
              int i;
              int y;
              int win = 0;
              char position;
              int final_size = boardSize-1+(boardSize-1)+(boardSize-1)+(boardSize-2);






                for(y=0;y<playerCount&&win==0;){

                //Display the board including the player’s position on the board
                displayBoard(boardSize,players,y);

                //Display the player’s score, and inventory information
                printf("score: ");
                players[y].playerScore=0;
                //Loop to count the score
                for(i=0;i<players[y].prizeCount;i++){
                        players[y].playerScore=players[y].playerScore+players[y].playerPrizes[i];
                }
                printf("%d\tinventory (%d items) ",players[y].playerScore,players[y].prizeCount);
                //Loop to print the Prizes
                for(i=0;i<players[y].prizeCount;i++){
                        printf("%d ",players[y].playerPrizes[i]);
                }
                printf("\n");


                //Rolling the dices
                printf("%c's turn ",players[y].playerName);
                players[y].playerPosition = players[y].playerPosition + playerRoll();

                //Restart the position of the board if it goes over
                //Ex: A boardsize of 5 has 17, if playerPositionis 18, it will erstart the position to 1
                //For proper use of the function that display the board
                if(players[y].playerPosition>final_size){

                    players[y].playerPosition=players[y].playerPosition-(final_size+1);

                }
                int z;
                //In case they are on the same position
                for(z=0;z<playerCount;z++){}
                    if(players[y].playerPosition)


                //Check the tile of the player Position
                position = tile(players,y);


                //Depending on the tile run each of these functions
                if(position == 'G'){
                    winGrandPrize(&players[y]);
                }
                else if(position == 'W'){
                    winPrize(&players[y]);
                }
                else if(position == 'L' && (players[y].prizeCount)>0){
                    loseItem(&players[y]);
                }
                else if(position == 'C'){
                    win = checkout(&players[y]);
                }
                else{
                    printf("You do nothing.\n");
                }

                y++;
                if(y==playerCount)
                    y=0;

              }


            }

//Getting a prize between 1 and 10 while the prizeCount is less than 10
void winPrize(struct Player* player){

    int prize = 0;
    prize = getRandom(10,100);
    if(player->prizeCount<10){

        player->playerPrizes[player->prizeCount] = prize;
        printf("you won a prize of %d\n",player->playerPrizes[player->prizeCount]);
        player->prizeCount++;

    }

}

//Getting a prize between 100 and 200 while the prizeCount is less than 10
void winGrandPrize(struct Player* player){

    int prize = 0;
    prize = getRandom(100,200);
    if(player->prizeCount<10){

        player->playerPrizes[player->prizeCount] = prize;
        printf("you won a grand prize of %d\n",player->playerPrizes[player->prizeCount]);
        player->prizeCount++;

    }

}

//Lose Item function
int loseItem(struct Player* player){
    int random_delete = 0;

    //Randomly select a position on the array to be eliminated
    random_delete = getRandom(0,player->prizeCount-1);
    printf("randomly removing one prize\n");
    printf("price #%d removed\n",random_delete+1);

    //Run a loop that will push everything to the left
    for(;random_delete<player->prizeCount;random_delete++){

        player->playerPrizes[random_delete]=player->playerPrizes[random_delete+1];

    }
    player->prizeCount=player->prizeCount-1; //Decresing PrizeCount

    return 0;
}

//Checkout function
int checkout(struct Player* player){

    int win = 0; //false

    //If the player lands in C and the Score is >200 will win the game and return true which is 1
    if(player->playerScore>=200){
        win = 1; //true
        printf("Your score was %d\n",player->playerScore);
        printf("You won the game!\n");
    }
    //Restarting prizes
    player->prizeCount = 0;
    player->playerPrizes[7] = 0;

    return win;

}


//OTHER FUNCTIONS
//===============
//Get a Valid Integer between limits
int getValidInteger(int low, int high){

    int choice;
    int var = 0;


    do{
       printf("Enter board size: ");
       scanf(" %d",&choice);
       if ( choice > low  && choice <= high ){
	   var = 1;
       }
       else{
	    printf("Invalid choice!\n");
       }

    } while( var == 0 );

    return choice;
}

//Get a Valid Character between limits
char getValidCharacter(char low, char high){

    char choice = ' ';
    int var = 0; //flag to exit the loop


    do{
       printf("Enter player ID: ");
       scanf(" %c",&choice);
       if ( choice > low  && choice <= high ){
	   var = 1;
       }
       else{
	    printf("Invalid choice!\n");
       }

    } while( var == 0 );

    return choice;
}

//Roll the dice in this case 1, 2 or 3 times
unsigned int playerRoll(){
    int each_roll;
    int roll, i;
    int var = 0;
    int sum_of_random = 0;
    //Let the player roll 1-3 dice.

    do{
       printf(", how many dice will you roll? ");
        scanf(" %d",&roll);

       if (roll>=1   && roll <= 3 ){
	   var = 1;
       }
       else{
	    printf("Invalid choice!\n");
       }

    } while( var == 0 ); //Error Checking

    printf("You rolled: ");

    //For loop for each roll
    for(i=0;i<roll;i++){

        each_roll = getRandom(1,6);
        printf("%d ",each_roll);
        sum_of_random = sum_of_random + each_roll;

    }
    //Displaying the total amount of spaces
    printf("\nAdvancing %d spaces\n",sum_of_random);

    return sum_of_random;

}

//Get a Random # between inclusive range
int getRandom(int low, int high){

    int random = 0;
    random= low + rand() % (low + 1 - high);
    return random;

}



//Milestone 4 Functions
void displayInstructions(void){
    printf("*******************\n");
    printf("* Full Game Rules *\n");
    printf("*******************\n");
    printf("Up to 8 players compete to be the first to obtain $500\n");
    printf("Game takes place on a square board with 5 tile types\n");
    printf("->Empty Tile: No effect\n");
    printf("->Win Tile (W): Win a random prize\n");
    printf("->Lose Tile (L): Lose a random prize\n");
    printf("->Grand Prize Tile (G): Win a grand prize\n");
    printf("->Checkout Tile (C): Sells all your prizes for cash\n");
    printf("Players can roll 1 - 3 dice to determine how many tiles they move each turn\n");
    printf("If a player lands on the same tile as another player, that player steals a prize and moves 1 tile back\n");

}

void addToLeaderboard (int game, struct Player* winner){

}

void displayHighestScore (void){

}
