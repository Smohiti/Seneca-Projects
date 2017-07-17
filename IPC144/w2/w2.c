#include <stdio.h>
int main (void){
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

	printf("Charactre Creation\n");
	printf("Please enter your desired sates for your character:\n");

	printf("Enter Strength:");
	scanf ("%d" ,&strength);
		
	printf("Enter Speed:");
	scanf ("%d" ,&speed);

	printf("Enter Defense:");
	scanf ("%d" ,&defense);

	printf("Enter Intelligence:");
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
