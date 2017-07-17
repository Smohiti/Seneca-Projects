/*
I declare that the attached assignment is wholly my own work in accordance with Seneca Academic Policy. No 
part of this assignment has been copied manually or electronically from any other source (including web 
sites) or distributed to other students

Name:       Student ID: 
*/







#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#define SIZE 10

void Srandom() {
	srand(time(NULL));
}

// checks the user UserInp is numeric
int getvalidinteger(int min, int max);

//checks the user UserInp UserInp is  alphabetic 
int getvalidcharacter(char min, char max);

// ask user to type  the user name
void initplayer(int* PlayerScore, int PlayerPrize[], unsigned int* PrizeCount, char* PlayerName, int* PlayerPosition);

// this function gets a random NUM inbetween the specified range
int getRandom(int a, int b);

//dice rolls, in range of 3
unsigned int PlayerRoll();

char gettiletype(unsigned int index);

//chek the player position
char getdisplaytile(unsigned int index, unsigned int PlayerPosition, char PlayerName);

// print the tile
void displayBoard(unsigned int size, unsigned int PlayerPosition, char PlayerName);

//create prize
void winprize(int PlayerPrize[], unsigned int *PrizeCount);

// create grand prize
void wingrandprize(int PlayerPrize[], unsigned int* PrizeCount);

//create random NUM
int loseitem(int PlayerPrize[], unsigned int* PrizeCount);

//check sum of all prize
int checkout(int* PlayerScore, int PlayerPrize[], unsigned int* PrizeCount);

//propmt user to enter letter to choose menue
int playgame(unsigned int boardsize, int *PlayerScore, int PlayerPrize[], unsigned int *PrizeCount, char *PlayerName, int *PlayerPosition);

int main(void){

	Srandom();
	unsigned int PrizeCount = 0;
	char PlayerName, Hname, UserInp = 'o';
	int PlayerPrize[SIZE] = {0};
	int maxPoint = 100, PlayerScore = 0, PlayerPosition = 0, boardsize;
	int k = 0, j = 2;
	

	do{
		printf("Welcome to CHECKOUT\nMain Menu\n\np-(p)lay q-(q)uit r-inst(r)uctions s-HI(s)core:\n");
		
		scanf("%s", &UserInp);

		if (UserInp == 'p'){
			printf("Nunmebr of players is 1\n");

			initplayer(&PlayerScore, PlayerPrize, &PrizeCount, &PlayerName, &PlayerPosition);
			printf("Enter board size: ");
			scanf("%d", &boardsize);

			playgame(boardsize, &PlayerScore, PlayerPrize, &PrizeCount, &PlayerName, &PlayerPosition);
			k = k + PlayerPosition;		
			
			
			do{			
				j = playgame(boardsize, &PlayerScore, PlayerPrize, &PrizeCount, &PlayerName, &k);
				
				if (j==1){
					printf("You won the game!\n");
					maxPoint = PlayerScore;
					Hname = PlayerName;			
					break;
				}
				else if (j==0){
					printf("You lost\n");
					break;
				}

			} while (&PlayerPosition != 0);
		}
		switch(UserInp){
		case 'r':
		//		else if (UserInp == 'r')
			printf("Type a letter to enter the game\n\n");
			break;
		case 's':
//		else if (UserInp == 's'){
			printf("__\n"
				"  \\_______\n"
				"   \\++++++|\n"
				"    \\=====|\n"
				"     0--- 0\n");


			printf("HI SCORE: %d Player Name: %c\n\n", maxPoint, Hname);
			break;
			
		}

	} while (UserInp != 'q');
	printf("This game is so much more fun than bash...\n");
	return 0;
}








int getvalidinteger(int min, int max) {
	int UserInp = 0;

	printf("Select: ");
	scanf("%d", &UserInp);

	do {
		printf("Invalid UserInp, try again: ");
		scanf("%d", &UserInp);
	} while (UserInp < min || UserInp > max);
	return UserInp;
}

 

int getvalidcharacter(char min, char max) {
	char UserInp;;

	printf("Select: ");
	scanf("%c", &UserInp);

	do {
		printf("Invalid input, try again: ");
		scanf("%c", &UserInp);
	} while (UserInp < min || UserInp > max);
	return UserInp;
}



void initplayer(int* PlayerScore, int PlayerPrize[], unsigned int*
	PrizeCount, char* PlayerName, int* PlayerPosition) {

	*PlayerScore = 0;
	PlayerPrize[SIZE] = 0;
	*PrizeCount = 0;
	*PlayerPosition = 0;
	printf("Enter player ID: ");
	scanf("%s", &*PlayerName);
}





int getRandom(int a, int b) {
	int random = 0;
	random = a + rand() % (b + 1 - a);
	return random;
}


unsigned int PlayerRoll() {
	int x, y, z, sum, UserInp;
	printf("Your turn, how many dice will you roll? ");
	scanf("%d", &UserInp);
	do {
		printf("Invalid input, try again: ");
		scanf("%d", &UserInp);
	} while (UserInp <= 0 || UserInp > 3);
	if (UserInp == 3) {
		Srandom();
		x = getRandom(1, 6);
		y = getRandom(1, 6);
		z = getRandom(1, 6);

		sum = x + y + z;
		printf("You rolled: %d %d %d\n", x, y, z);
		printf("Advancing %d spaces\n", sum);
		return sum;
	}
	else if (UserInp == 2) {
		Srandom();
		x = getRandom(1, 6);
		y = getRandom(1, 6);
		sum = x + y;
		printf("You rolled: %d %d\n", x, y);
		printf("Advancing %d spaces\n", sum);
		return sum;
	}
	else {
		Srandom();
		x = getRandom(1, 6);
		printf("You rolled: %d\n", x);
		printf("Advancing %d spaces\n", x);
		return x;
	}
}



char gettiletype(unsigned int index) {
	char letter;
	if (index == 0) {
		letter = 'C';
	}
	else if (index % 7 == 0) {
		letter = 'G';
	}
	else if (index % 5 == 0) {
		letter = 'L';
	}
	else if (index % 3 == 0) {
		letter = 'W';
	}
	else {
		letter = ' ';
	}
	return letter;
}


char getdisplaytile(unsigned int index, unsigned int PlayerPosition, char PlayerName) {

	if (index != PlayerPosition) {
		char letter = gettiletype(index);
		return letter;
	}
	else
		return PlayerName;


}



void displayBoard(unsigned int size, unsigned int PlayerPosition, char PlayerName) {
	int count;
	const int NUM = size;
	int i, j, a, b;
	int numerator = ((NUM * 4) - 5);
	int numerator1 = size;

	int ppos = 0;
	int k;
	ppos = PlayerPosition;
	do {
		ppos = ppos - (numerator + 1);
	} while (ppos > numerator);
	

	for (count = 0; count <= (size - 1); count++) {
		printf(" ___ ");
	}
	printf("\n");
	for (count = 0; count <= (size - 1); count++) {
		printf("| %c |", getdisplaytile(count, ppos, PlayerName));
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
		printf("| %c |", getdisplaytile(numerator, ppos, PlayerName));
		for (i = 0; i < (NUM - 2); i++)
			printf("     ");
		printf("| %c |", getdisplaytile(numerator1, ppos, PlayerName));
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
		printf("| %c |", getdisplaytile(count, ppos, PlayerName));
	printf("\n");
	for (count = ((NUM * 2) + (NUM - 3)); count >= ((NUM * 2) - 2); count--)
		printf("|___|");
	printf("\n");
}

//create prize
void winprize(int PlayerPrize[], unsigned int *PrizeCount) {
	if (*PrizeCount < SIZE) {
		Srandom();
		int a = getRandom(10, 100);
		*PrizeCount = *PrizeCount + 1;

		for (int i = 0; i < SIZE; i++) {
			if (PlayerPrize[i] == 0) {
				PlayerPrize[i] = a;
				printf("You won a prize of %d!\n\n", a);
				break;
			}
		}
	}
	else
		printf("Inventory is already full!\n\n");
}


void wingrandprize(int PlayerPrize[], unsigned int* PrizeCount) {
	if (*PrizeCount < SIZE) {
		Srandom();
		int a = getRandom(100, 200);
		*PrizeCount = *PrizeCount + 1;
		for (int i = 0; i < SIZE; i++) {
			if (PlayerPrize[i] == 0) {
				PlayerPrize[i] = a;
				printf("You won a grand prize of %d!\n\n", a);
				break;
			}
		}
	}
	else
		printf("Inventory is already full!");
}


int loseitem(int PlayerPrize[], unsigned int* PrizeCount) {
	int itemsSeen, numerator, temp;
	if (*PrizeCount > 0) {
		Srandom();
		int a = getRandom(1, *PrizeCount);
		int i = PlayerPrize[a - 1];
		for (numerator = a - 1; numerator < *PrizeCount; numerator++) {
			PlayerPrize[numerator] = PlayerPrize[numerator + 1];
		}
		*PrizeCount -= 1;
		printf("You lose a prize valued at $%d!\n", i);
	}
	return temp;
}


int checkout(int* PlayerScore, int PlayerPrize[], unsigned int* PrizeCount) {
	int a;
	*PlayerScore = PlayerPrize[0] + PlayerPrize[1] + PlayerPrize[2] + PlayerPrize[3] + PlayerPrize[4] + PlayerPrize[5] + PlayerPrize[6] + PlayerPrize[7] + PlayerPrize[8] + PlayerPrize[9];

	if (*PlayerScore >= 200)
		a = 1;
	else
		a = 0;

	return a;
}

int playgame(unsigned int boardsize, int *PlayerScore, int PlayerPrize[], unsigned
	int *PrizeCount, char *PlayerName, int *PlayerPosition) {

	displayBoard(boardsize, *PlayerPosition, *PlayerName);
	printf("Score: %d", *PlayerScore);

	printf("  Inventory(%d items): ", *PrizeCount);
	for (int i = 0; i < *PrizeCount; i++)
		printf("%d, ", PlayerPrize[i]);

	printf("\n");
	int a = PlayerRoll();
	int c = 2;


	int lap = (boardsize * 4 - 4);

	*PlayerPosition = *PlayerPosition + a;
	while (*PlayerPosition >= lap)
		*PlayerPosition = *PlayerPosition - (lap);


	int name = *PlayerName;
	int sum = 0;
	if (*PlayerPosition == 0) {
		c = checkout(PlayerScore, PlayerPrize, PrizeCount);
		printf("You checkedout!\n");
	}
/*
	switch (gettiletype) {
	case 'W':
		gettiletype(*PlayerPosition);
		winprize(PlayerPrize, PrizeCount);
		break;
	case 'L':
		gettiletype(*PlayerPosition);
		loseitem(PlayerPrize, PrizeCount);
		break;
	case 'G':
		gettiletype(*PlayerPosition);
		wingrandprize(PlayerPrize, PrizeCount);
		break;
	default:
		gettiletype(*PlayerPosition);
		printf("Nothing happens, go again.\n");
		break;


	}
*/

	if (gettiletype(*PlayerPosition) == ' ')
		printf("Nothing happens, go again.\n");
	if (gettiletype(*PlayerPosition) == 'W')
		winprize(PlayerPrize, PrizeCount);
	if (gettiletype(*PlayerPosition) == 'L')
		loseitem(PlayerPrize, PrizeCount);
	if (gettiletype(*PlayerPosition) == 'G')
		wingrandprize(PlayerPrize, PrizeCount);


	*PlayerScore = PlayerPrize[0] + PlayerPrize[1] + PlayerPrize[2] + PlayerPrize[3] + PlayerPrize[4] + PlayerPrize[5] + PlayerPrize[6] + PlayerPrize[7] + PlayerPrize[8] + PlayerPrize[9];


	printf("\n");


	return c;
}