

/*
I declare that the attached assignment is wholly my own work in accordance with 
Seneca Academic Policy. No
part of this assignment has been copied manually or electronically from any other 
source (including web
sites) or distributed to other students

Name:        Student ID:
*/

#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#define SIZE 10
#define MinPrize 10
#define MaxPrize 100
#define MinGPrize 100
#define MaxGprize 200
#define ScoreSize 500
#define Psize 15
void clearbuffer() {
	while (getchar() != '\n');
}
void Srandom() {
	srand(time(NULL));
}
struct Player {
	char playername[35];
	char name;
	int score;
	int Prize[SIZE];
	int PrizeCount;
	int playerpos;
};

void displayinstructions(void);
void displayhighscore(void);
// checks the user entry is numeric
int GetValidInteger(int UPrompt, int min, int max);
//checks the user entry is  alphabetic 
int getvalidcharacter(char min, char max);
// ask user to type  the user name

void addtoleaderboard(int game, struct Player* winner);
void initplayer(struct Player *player);
// this function gets a random number inbetween the specified range
int getRandom(int a, int b);
//dice rolls, in range of 3
unsigned int PlayerRoll(struct Player *player, int CurrentP);

char GetTileType(unsigned int index);
//chek the player position
char GetDisplayTile(unsigned int index, struct Player players[], unsigned int 
playerCount, int CurrentP);
// print the tile
void displayBoard(unsigned int size, struct Player players[], unsigned int 
playerCount, int CurrentP);
//create prize
void WinPrize(struct Player* player);
//add prize
void addprize(struct Player* player, int a);
// create grand prize
void WinGPrize(struct Player *player);
//create random NUM
int LoseItem(struct Player* player);
//steal prize from player
int stealitem(struct Player* player);
//check sum of all prize
int checkout(struct Player *player);
//propmt user to enter letter to choose menue
int PlayGame(unsigned int boardsize, struct Player players[], unsigned int 
playerCount, int CurrentP);

int main(void) {
	FILE *fp = fopen("leaderboard.dat", "w");
	fclose(fp);
	Srandom();
	int boardsize = 0, playerCount = 0, maxPoint = 100, BoardGame = 0;
	char UPrompt = 'o', Hname;
	int c = 2, j, i = 0;

	do {
		printf("Welcome to CHECKOUT\nMain Menu\n\np-(p)lay q-(q)uit r-inst(r)uctions s-HI(s)core:\n");
		scanf("%s", &UPrompt);
		if (UPrompt == 'p') {
			BoardGame++;
			printf("Enter number of players :");
			scanf("%d", &playerCount);
			while (playerCount < 1 || playerCount > 8) {
				printf("Invalid number of players, try again: ");
				scanf("%d", &playerCount);
			}
			struct Player players[playerCount];
			if (playerCount < 1 || playerCount > 8)
				clearbuffer();
			for (j = 0; j <playerCount; j++)
				initplayer(&players[j]);
			printf("Enter board size : ");
//			scanf("%d", &boardsize);
			boardsize = GetValidInteger(boardsize, 5, 15);


			int CurrentP = 0;
			do {
				c = PlayGame(boardsize, players, playerCount, CurrentP);

				printf("\n");
				if (c == 1) {
					printf("%s checkedout with $%d\n", players[CurrentP].playername, players[CurrentP].score);

					for (int f = 0; f < playerCount; f++) {
						if (players[CurrentP].score >= players[f].score) {
							maxPoint = players[CurrentP].score;
							Hname = players[CurrentP].name;
							addtoleaderboard(BoardGame, &players[CurrentP]);
						}
					}
					if (players[CurrentP].score >= ScoreSize) {
						printf("%s, you won the game!\n", players[CurrentP].playername);
						break;
					}
					
				}
				else if (c == 0) {
			//		printf("You lost the game\n");
					printf("__\n"
						"  \\_______\n"
						"   \\++++++|\n"
						"    \\=====|\n"
						"     0--- 0\n");
					printf("%s checkedout with $%d\n", players[CurrentP].playername, players[CurrentP].score);

					for (int f = 0; f < playerCount; f++) {
						if (players[CurrentP].score >= players[f].score) {
							maxPoint = players[CurrentP].score;
							Hname = players[CurrentP].name;
							addtoleaderboard(BoardGame, &players[CurrentP]);
						}
					}
					printf("You have nothing to lose\n");
					players[CurrentP].Prize[SIZE - 1] = 0;
				}
				int k = 0;
				do {
					if (players[CurrentP].playerpos == players[k].playerpos) {
						if (players[CurrentP].name != players[k].name) {
							printf("You choosed the tile as %c\n", players[k].name);
							printf("You move back one tile\n");
							if (players[k].PrizeCount > 0) {
								int j = stealitem(&players[k]);
								printf("You stole prize from %c\n", players[k].name);
								addprize(&players[CurrentP], j);
								printf("the  prize of %d  added to %c's inventory\n", j, players[CurrentP].name);
							}
							else {
								int i = 0;
								do {
									if (players[i].name != players[CurrentP].name && players[i].PrizeCount < 1 && players[i].playerpos == players[CurrentP].playerpos)
										
										printf("You were unable to steal from %c\n", players[i].name);
									i++;
								} while (i < playerCount);
							}
							for (int r = 0; r<playerCount; r++) {
								int a = players[CurrentP].playerpos -= 1;
								if (players[CurrentP].name == players[r].name) {
									if (GetTileType(a) == 'W') {
										WinPrize(&players[CurrentP]);
										break;
									}
									else if (GetTileType(a) == 'G') {
										WinGPrize(&players[CurrentP]);
										break;
									}
									else if (GetTileType(a) == 'L') {
										LoseItem(&players[CurrentP]);
										break;
									}
									break;
								}
							}
						}
					}
					k++;
				} while (k <= playerCount);
				CurrentP++;

				if (CurrentP == playerCount)
					CurrentP = 0;
			} while (c != 0 || c != 1);

		}
		switch (UPrompt) {
		case 'r':
			displayinstructions();
		//	printf("Type a letter to enter the game\n\n");
			break;
		case 's':
			displayhighscore();
			


	//		printf("HI SCORE: %d Player Name: %c\n\n", maxPoint, Hname);
		//	break;

		}

	} while (i < playerCount);
	printf("This game is so much more fun than bash...\n");
	return 0;
}



void displayinstructions(void) {
	printf("*******************\n *Full Game Rules*\n*******************\n");
	printf("Up to 8 players cmpete to be the first to obtain $500\nGames takes place on a square board with 5 tile types\n->Empty Tile: No Effect\n->Win Tile (W): Win a random prize\n->Lose Tile (L): Lose a random prize\n->Grand Prize (G): Win a grand prize\n->Checkout Tile (C): Sells all your prizes for cash\n");
	printf("Players can roll 1-3 dice to determine how many tiles they move each turn\n");
	printf("If a player lands on the same tile as another player, that player steals a prize and moves 1 tile back\n\n");
}
void displayhighscore(void) {
	int Point;
	char Name, PlayerName[Psize];
	
	FILE *fp = fopen("leaderboard.dat", "r");
	if (fp != NULL) {
		do {	
			fscanf(fp, "GAME:%*d %[^(](%c)-%d%*c", PlayerName, &Name, &Point);
		}while (!feof(fp));
		fclose(fp);
	}
	else
		printf("Unable to read from file!\n");
	printf("*************************\n");
	printf("Player With the Highest Score\n");
	printf("*************************\n");
	printf("Player Name	ID	Score\n");
	printf("%s	(%c)	$%d\n\n", PlayerName, Name, Point);
}

int GetValidInteger(int UPrompt, int min, int max ) {
        int UserInp = 0,valid=0;

        valid=scanf("%d", &UserInp);
        while(getchar()!='\n');
        while (valid!=1 || UserInp < min || UserInp > max){

                printf("Invalid entry, try again: ");
                valid=scanf("%d", &UserInp);
}
        return UserInp;
}



int getvalidcharacter(char min, char max) {
	char UPrompt;;

	scanf("%c", &UPrompt);

	do {
		printf("Invalid entry, try again: ");
		scanf("%c", &UPrompt);
	} while (UPrompt < min || UPrompt > max);
	return UPrompt;
}

void addtoleaderboard(int game, struct Player* winner) {
	FILE *fp = fopen("leaderboard.dat", "a");
	if (fp != NULL) {
		fprintf(fp, "Game:%d %s(%c)-%d\n", game, winner->playername, winner->name, winner->score);
		fclose(fp);
	}
	else
		printf("Error! system not able to open the file!");
}


void initplayer(struct Player *player) {
	printf("Enter player's name: ");
	clearbuffer();
	scanf("%[^\n]", player->playername);
	printf("Enter player ID: ");
	scanf("%s", &player->name);
	player->score = 0;
	for (int i = 0; i < SIZE; i++)
		player->Prize[i] = 0;
	player->PrizeCount = 0;
	player->playerpos = 0;
}



int getRandom(int a, int b) {
	int random = 0;
	random = a + rand() % (b + 1 - a);
	return random;
}

unsigned int PlayerRoll(struct Player *player, int CurrentP)
{
	printf("%s's (%c) your turn, how many dice will you roll? ", player[CurrentP].playername, player[CurrentP].name);
	int UPrompt;
	unsigned int i, diceNumbers = GetValidInteger(UPrompt, 1, 3), diceSum = 0, rollResult;
	printf("You rolled:");
	for (i = 0; i < diceNumbers; i++) {
		rollResult = 1 + (rand() % 6);
		printf(" %d", rollResult);
		diceSum += rollResult;
	}
	printf("\n");
	return diceSum;
}


char GetTileType(unsigned int index) {
	char Tile;
	if (index == 0)
		Tile = 'C';

	else if (index % 7 == 0)
		Tile = 'G';

	else if (index % 5 == 0)
		Tile = 'L';

	else if (index % 3 == 0)
		Tile = 'W';

	else
		Tile = ' ';

	return Tile;
}

char GetDisplayTile(unsigned int index, struct Player players[], unsigned int playerCount, int CurrentP) {
	char L;
	int i = 0;
	if (index == players[CurrentP].playerpos) {
		L = players[CurrentP].name;

	}
	else if (index != players[CurrentP].playerpos) {
		do {
			if (players[i].playerpos == index) {
				L = players[i].name;
				break;
			}
			else
				L = GetTileType(index);
			i++;
		} while (i < playerCount);
	}
	return L;
}



void displayBoard(unsigned int size, struct Player players[], unsigned int playerCount, int CurrentP) {
	int count, i, j;
	const int NUM = size;
	int numerator = ((NUM * 4) - 5);
	int numerator1 = size, playerpos = 0;
	
	


	for (count = 0; count <= (size - 1); count++) {
		printf(" ___ ");
	}
	printf("\n");
	for (count = 0; count <= (size - 1); count++) {
		printf("| %c |", GetDisplayTile(count, players, playerCount, CurrentP));
	}
	printf("\n");
	for (count = 0; count <= (size - 1); count++) {
		printf("|___|");
	}
	printf("\n");



	for (j = 0; j < (NUM - 2); j++) {
		printf(" ___ ");

		for (i = 0; i < (NUM - 2); i++)
			printf("     ");
		printf(" ___ ");

		printf("\n");
		printf("| %c |", GetDisplayTile(numerator, players, playerCount, CurrentP));
		for (i = 0; i < (NUM - 2); i++)
			printf("     ");
		printf("| %c |", GetDisplayTile(numerator1, players, playerCount, CurrentP));
		printf("\n");

		printf("|___|");

		for (i = 0; i < (NUM - 2); i++)
			printf("     ");
		printf("|___|");

		printf("\n");
		numerator--;
		numerator1++;
	}


	for (count = ((NUM * 2) + (NUM - 3)); count >= ((NUM * 2) - 2); count--)
		printf(" ___ ");
	printf("\n");

	for (count = ((NUM * 2) + (NUM - 3)); count >= ((NUM * 2) - 2); count--)
		printf("| %c |", GetDisplayTile(count, players, playerCount, CurrentP));
	printf("\n");
	for (count = ((NUM * 2) + (NUM - 3)); count >= ((NUM * 2) - 2); count--)
		printf("|___|");
	printf("\n");


}
/*
void WinPrize(struct Player* player)
{
if (player->PrizeCount == SIZE) {
printf(" Your inventory is full.\n");
return;
}
else {
int prize1 = getRandom(MinPrize, MaxPrize);
player->Prize[(*PrizeCount)++] = prize1;
printf("you won a prize of %d\n", prize1);
}
}
*/

void WinPrize(struct Player* player) {
	if (player->PrizeCount < SIZE) {
		Srandom();
		int a = getRandom(MinPrize, MaxPrize);
		player->PrizeCount = player->PrizeCount + 1;

		for (int i = 0; i < SIZE; i++) {
			if (player->Prize[i] == 0) {
				player->Prize[i] = a;
				printf("You won a prize valued at %d!\n", a);
				break;
			}
		}
	}
	else
		printf("Inventory is already full!\n\n");
}

void addprize(struct Player* player, int a) {
	if (player->PrizeCount < SIZE) {
		Srandom();
		player->PrizeCount = player->PrizeCount + 1;

		for (int i = 0; i < SIZE; i++) {
			if (player->Prize[i] == 0) {
				player->Prize[i] = a;
				break;
			}
		}
	}
	else
		printf("Inventory is already full!\n\n");
}

/*
void WinGPrize(struct Player *player)
{
if (player->PrizeCount == SIZE) {
printf("sorry, your inventory is full.\n");
return;
}
else {
int prize1 = getRandom(MinGPrize, MaxGprize);
player->Prize[(*PrizeCount)++] = prize;
printf("you won a grand prize of %d\n", prize1);
}

}
*/
void WinGPrize(struct Player *player) {
	if (player->PrizeCount < SIZE) {
		Srandom();
		int a = getRandom(MinGPrize, MaxGprize);
		player->PrizeCount = player->PrizeCount + 1;
		for (int i = 0; i < SIZE; i++) {
			if (player->Prize[i] == 0) {
				player->Prize[i] = a;
				printf("You won a grand prize valued at %d!\n\n", 
a);
				break;
			}
		}
	}
	else
		printf("Inventory is already full!");
}


int LoseItem(struct Player* player) {
	int itemsSeen, numerator, Var, i;
	if (player->PrizeCount > 0) {
		Srandom();
		int a = getRandom(1, player->PrizeCount);
		i = player->Prize[a - 1];
		for (numerator = a - 1; numerator < player->PrizeCount; numerator++) {
			player->Prize[numerator] = player->Prize[numerator + 1];
		}
		player->PrizeCount -= 1;
		printf("You lost prize valued at: $%d!\n", i);
	}
	return i;
}
int stealitem(struct Player* player) {
	int itemsSeen, numerator, Var, i;
	if (player->PrizeCount > 0) {
		Srandom();
		int a = getRandom(1, player->PrizeCount);
		i = player->Prize[a - 1];
		for (numerator = a - 1; numerator < player->PrizeCount; numerator++) {
			player->Prize[numerator] = player->Prize[numerator + 1];
		}
		player->PrizeCount -= 1;
	}
	return i;
}


int checkout(struct Player *player) {
	int S;
	player->score = player->Prize[0] + player->Prize[1] + player->Prize[2] + player->Prize[3] + player->Prize[4] + player->Prize[5] + player->Prize[6] + player->Prize[7] + player->Prize[8] + player->Prize[9];

	if (player->score >= ScoreSize)
		S = 1;
	else
		S = 0;

	return S;
}


int PlayGame(unsigned int boardsize, struct Player players[], unsigned int playerCount, int CurrentP) {
	int c = 2;
	

	displayBoard(boardsize, players, playerCount, CurrentP);


	int a = PlayerRoll(players,CurrentP);

	int round = (boardsize * 4 - 4);

	a += players[CurrentP].playerpos;

	while (a >= round)
		a = a - (round);
	players[CurrentP].playerpos = a;

	int sum = 0;

	if (a == 0) {
		c = checkout(&players[CurrentP]);
		printf("You checked out for $%d!\n", players[CurrentP].score);
	}

	if (GetTileType(a) == ' ')
		printf("You do nothing\n");
	if (GetTileType(a) == 'W')
		WinPrize(&players[CurrentP]);
	if (GetTileType(a) == 'L')
		LoseItem(&players[CurrentP]);
	if (GetTileType(a) == 'G')
		WinGPrize(&players[CurrentP]);
	players[CurrentP].score = players[CurrentP].Prize[0] + players[CurrentP].Prize[1] + players[CurrentP].Prize[2] + players[CurrentP].Prize[3] + players[CurrentP].Prize[4] + players[CurrentP].Prize[5] + players[CurrentP].Prize[6] + players[CurrentP].Prize[7] + players[CurrentP].Prize[8] + players[CurrentP].Prize[9];

	/*
	switch (GetTileType) {
	case 'W':
	GetTileType(*PlayerPosition);
	WinPrize(PlayerPrize, PlayerCount);
	break;
	case 'L':
	GetTileType(*PlayerPosition);
	LoseItem(PlayerPrize, PlayerCount);
	break;
	case 'G':
	GetTileType(*PlayerPosition);
	WinGPrize(PlayerPrize, PlayerCount);
	break;
	default:
	GetTileType(*PlayerPosition);
	printf("Nothing happens, go again.\n");
	break;

	}
	*/

	return c;
}
