// Code Quest Game+ Character Creation
// By M.Saeed Mohiti
// Week1 + week2

#include <stdio.h>
 int main (void)
	{
	printf("+-----------------------+\n");
	printf("|                       |\n");
	printf("|      CODE QUEST       |\n");
	printf("|                       |\n");
	printf("+-----------------------+\n");
	char enter = 0;
	printf("\nPress Enter To Continue...");
	scanf("%c", &enter);

	int strength = 0;

	int speed = 0;

	int defense = 0;

	int intelligence = 0;

	int sum = 0;

	float strengthratio = 0;

	float speedratio = 0;

	float defenseratio = 0;

	float intelligenceratio = 0;

	int luck = 0;



	printf("Character Creation");

	printf("\nPlease enter your desired sates for your character:\n");



	printf("Enter strength:");

	scanf ("%d" ,&strength);

		

	printf("Enter speed:");

	scanf ("%d" ,&speed);



	printf("Enter defense:");

	scanf ("%d" ,&defense);



	printf("Enter intelligence:");

	scanf ("%d" ,&intelligence);

	

	sum = strength + speed + defense + intelligence;

	strengthratio = strength/(float)sum ;

	speedratio = speed/(float)sum;

	defenseratio = defense/(float)sum;

	intelligenceratio = intelligence/(float)sum; 

	strength = strengthratio*100;

	speed = speedratio*100;

	defense = defenseratio*100;

	intelligence = intelligenceratio*100;

	luck = sum%30;	





	printf("\nYour player's final states are:\n");

	printf("Strength:%d\n", strength);

	printf("Speed:%d\n", speed);

	printf("Defense:%d\n", defense);

	printf("Intelligence:%d\n", intelligence);

	printf("Luck:%d\n", luck);
	return 0;
	}
