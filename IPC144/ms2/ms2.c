/*I declare that the attached assignment is wholly my own work in 
accordance with Seneca Academic Policy.  No part of this assignment has 
been copied manually or electronically from any other source (including 
web sites) or distributed to other students.  
Name  M.Saeed Mohiti   Student ID 116236159
*/
#include <stdio.h>
#include <stdlib.h>
 
#ifdef USING_SRAND
#include <time.h>
#endif
 
typedef char bool;
#define true 1 
#define false 0
 
#define playerPrizesCapacity 10
#define initialHighScore 100
#define boardSizeLow 5
#define boardSizeHigh 15
#define winningThreshold 200
#define prizeLow 10
#define prizeHigh 100
#define grandPrizeLow 100
#define grandPrizeHigh 200
 
int             getValidInteger(int low, int high);
char            getValidCharacter(char low, char high);
void            initPlayer(int* playerScore, int playerPrizes[], unsigned int* prizeCount,
                    char* playerName, int* playerPosition);
void            playGame(unsigned int boardSize, int* playerScore, int playerPrizes[],
                    unsigned int* prizeCount, char* playerName, int* playerPosition);
char            getDisplayTile(unsigned int index, unsigned int playerPosition, char playerName);
void            displayBoard(unsigned int size, unsigned int playerPosition, char playerName);
int             getRandom(int low, int high);
unsigned int    playerRoll();
void            winPrize(int playerPrizes[], unsigned int* prizeCount);
void            winGrandPrize(int playerPrizes[], unsigned int* prizeCount);
int             loseItem(int playerPrizes[], unsigned int* prizeCount);
int             checkout(int* playerScore, int playerPrizes[], unsigned int* prizeCount);
 
 
int getValidInteger(int low, int high)
{
    int number;
    while (true){
        int scanned = scanf("%d", &number);
        char c = getchar();
        while (c != '\n')
            c = getchar();
 
        if (scanned == 1 && number >= low && number <= high)
            break;
        printf("Invalid input, try again: ");  
    }
    return number;
}
 
char getValidCharacter(char low, char high)
{
    char character;;
    scanf("%c", &character);
 
    char c = character;
    while (c != '\n')
        c = getchar();
 
    while (character < low || character > high){
        printf("Invalid input, try again: ");
        scanf("%c", &character);
 
        char c = character;
        while (c != '\n')
            c = getchar();
    }
    return character;
}
 
void initPlayer(int* playerScore, int playerPrizes[], unsigned int* prizeCount,
        char* playerName, int* playerPosition)
{
    *playerScore = 0;
    *prizeCount = 0;
    *playerPosition = 0;
 
    unsigned int i = 0;
    for (i = 0; i < playerPrizesCapacity; i++)
        playerPrizes[i] = 0;
 
    printf("Enter player ID: ");
    *playerName = getValidCharacter(33, 126);
}
       
void playGame(unsigned int boardSize, int* playerScore, int playerPrizes[],
        unsigned int* prizeCount, char* playerName, int* playerPosition)
{
    int playerWins = false;
    while (!playerWins){
        displayBoard(boardSize, *playerPosition, *playerName);
 
        printf("score: %d   inventory (%u items):", *playerScore, *prizeCount);
        unsigned int iterator = 0;
        for (iterator = 0; iterator < *prizeCount; iterator++)
            printf(" %d,", playerPrizes[iterator]);
        printf("\n");
 
        unsigned int rollResult = playerRoll();
        printf("Advancing %u spaces\n", rollResult);
        *playerPosition = (*playerPosition + rollResult) % (boardSize * 4 - 4);
 
        char tileType = getDisplayTile(*playerPosition, *playerPosition+1, *playerName);
        switch (tileType){
            case 'G':
                winGrandPrize(playerPrizes, prizeCount);
                break;
            case 'W':
                winPrize(playerPrizes, prizeCount);
                break;
            case 'L':
                loseItem(playerPrizes, prizeCount);
                break;
            case 'C':
                playerWins = checkout(playerScore, playerPrizes, prizeCount);
                break;
            default:
                printf("nothing happens, go again.\n");
                break;
        };
    }
    printf("You won the game!\n");
}
 
char getDisplayTile(unsigned int index, unsigned int playerPosition, char playerName)
{
    if (index == playerPosition)    return playerName;
    if (index == 0)                 return 'C';
    if (index % 7 == 0)             return 'G';
    if (index % 5 == 0)             return 'L';
    if (index % 3 == 0)             return 'W';
    return ' ';
}
 
void displayBoard(unsigned int size, unsigned int playerPosition, char playerName)
{
    unsigned int tile = 0, tileNumber = 0, space = 0, tileNumberRev = 0;
    char type;
 
    if (size == 1){
        type = getDisplayTile(tileNumber, playerPosition, playerName);
        printf(" ___ \n| %c |\n|___|\n", type);
    }
    else {
 
        for (tile = 0; tile < size; tile++)
            printf(" ___ ");
        printf("\n");
 
        for (tile = 0; tile < size; tile++){
            type = getDisplayTile(tileNumber++, playerPosition, playerName);
            printf("| %c |", type);
        }
        printf("\n");
 
        for (tile = 0; tile < size; tile++)
            printf("|___|");
        printf("\n");
 
        tileNumberRev = 4 * size - 5;
 
        for (tile = 2; tile < size; tile++){
            printf(" ___ ");
            for (space = 0; space < (size - 2); space++)
                printf("     ");
            printf(" ___ ");
            printf("\n");
 
            type = getDisplayTile(tileNumberRev--, playerPosition, playerName);
            printf("| %c |", type);
            for (space = 0; space < (size - 2); space++)
                printf("     ");
            type = getDisplayTile(tileNumber++, playerPosition, playerName);
            printf("| %c |", type);
            printf("\n");
 
            printf("|___|");
            for (space = 0; space < (size - 2); space++)
                printf("     ");
            printf("|___|");
            printf("\n");
        }
 
 
        for (tile = 0; tile < size; tile++)
            printf(" ___ ");
        printf("\n");
 
        for (tile = 0; tile < size; tile++){
            type = getDisplayTile(tileNumberRev--, playerPosition, playerName);
            printf("| %c |", type);
        }
        printf("\n");
 
        for (tile = 0; tile < size; tile++)
            printf("|___|");
        printf("\n");      
    }
}
 
int getRandom(int low, int high)
{
    int delta = high - low;
    if (delta < 0)
        return getRandom(high, low);
    return low + (rand() % (delta+1));
}
 
unsigned int playerRoll()
{
    printf("your turn, how many dice will you roll? ");
    unsigned int i, diceNumbers = getValidInteger(1, 3), diceSum = 0, rollResult;
    printf("You rolled:");
    for (i = 0; i < diceNumbers; i++){
        rollResult = 1 + (rand() % 6);
        printf(" %d", rollResult);
        diceSum +=  rollResult;
    }
    printf("\n");
    return diceSum;
}
 
void winPrize(int playerPrizes[], unsigned int* prizeCount)
{
    if (*prizeCount == playerPrizesCapacity){
        printf("sorry, your inventory is full.\n");
        return;
    }
    else {
        int prize = getRandom(prizeLow, prizeHigh);
        playerPrizes[(*prizeCount)++] = prize;
        printf("you won a prize of %d\n", prize);
    }
}
 
void winGrandPrize(int playerPrizes[], unsigned int* prizeCount)
{
    if (*prizeCount == playerPrizesCapacity){
        printf("sorry, your inventory is full.\n");
        return;
    }
    else {
        int prize = getRandom(grandPrizeLow, grandPrizeHigh);
        playerPrizes[(*prizeCount)++] = prize;
        printf("you won a grand prize of %d\n", prize);
    }
 
}
 
int loseItem(int playerPrizes[], unsigned int* prizeCount)
{
    if (*prizeCount == 0){
        printf("nothing to lose\n");
        return -1;
    }
 
    unsigned int iterator, index = rand() % (*prizeCount);
    printf("Player lost a prize value at %d!\n", playerPrizes[index]);
 
    for (iterator = index; iterator < (*prizeCount)-1; iterator++)
        playerPrizes[iterator] = playerPrizes[iterator+1];
    playerPrizes[(*prizeCount)--] = 0;
 
    return index;
}
 
int checkout(int* playerScore, int playerPrizes[], unsigned int* prizeCount)
{
    unsigned int iterator;
    unsigned int checked = 0;
    for (iterator = 0; iterator < *prizeCount; iterator++)
        checked += playerPrizes[iterator];
    *prizeCount = 0;
   
    *playerScore += checked;
    printf("You checked out for $%d.00 score is now: $%d.00\n", checked, *playerScore);
    return ((*playerScore) >= winningThreshold);
}
 
int main()
{
    unsigned int highScore = initialHighScore;      
    char bestPlayerName = 0;                       
    printf("Welcome to CHECKOUT\n");
 
    int playerScore;
    int playerPrizes[playerPrizesCapacity];
    unsigned int prizeCount;
    char playerName = 0;
    int playerPosition;
 
    unsigned int boardSize;
 
    while (true){
        printf("\nMain Menu");
        printf("\np-(p)lay q-(q)uit r-inst(r)uctions s-HI(s)core:\n");
        char option = getValidCharacter('p', 's');
	printf("number of player is 1\n");       
        switch (option) {
            case 'q':
                printf("This game is more fun than bash...\n");
                return 0;
 
            case 'r':
                printf("No instruction needed, you already know how to play this game :)\n");
                break;
 
            case 's':
                printf("__\n"
                       "  \\_______\n"
                       "   \\++++++|\n"
                       "    \\=====|\n"
                       "     0--- 0\n");
                printf("HIGH SCORE: %d Player Name: %c\n", highScore, bestPlayerName);
                break;
 
            case 'p':
                #ifdef USING_SRAND
                    srand(time(NULL));
                #endif
               
                initPlayer(&playerScore, playerPrizes, &prizeCount, &playerName, &playerPosition);
 
                printf("Enter board size: ");
                boardSize = getValidInteger(boardSizeLow, boardSizeHigh);
 
                playGame(boardSize, &playerScore, playerPrizes, &prizeCount,
                        &playerName, &playerPosition);
 
                if (playerScore > highScore){
                    highScore = playerScore;
                    bestPlayerName = playerName;
                }
                break;
 
            default:
                printf("Invalid option. Please try again.\n");
                break;
        };
    };
 
    return 0;
}
