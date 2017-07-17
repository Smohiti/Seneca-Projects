#include <stdio.h>
void clearScreen(void){
	int line = 0;
	for(line = 1; line <=40; line++){
		printf("\n");
		}
}
void welcome(void){
	
        printf("\n--Main Menu--\n");
	printf("\n0 - Welcome Screen\n");
	printf("1 - New Game\n");
        printf("2 - Load Game\n");
        printf("3 - Exit\n");

}
	
void welcomeScreen (void){
	printf("Welcome To The Game, To Continue Press 1 To New Game, 2 To Load Gmae and 3 To Exit Game\n");
}
void newGame (void){
        printf("Not Implemented\n");
}
void loadGame (void){
        printf("Not Implemented\n");
}

int validate( int low, int high){
	int sel  = 0 ;
	printf("\nSelect:");
	scanf("%d", &sel);
	while(sel < low || sel > high){
		printf("Invalid input, try again:");
		scanf("%d", &sel);
	}
	return sel;		
}
int main (void){
	int input = 0;
        clearScreen();
	welcome();
	while( input == 0 || input == 1 || input == 2){
		 input = validate(0,3);

		if( input ==0){
			welcomeScreen();
			welcome();	
		}	
                else if( input == 1){
                        newGame();
               		welcome();
		 }
                else if(input == 2){
                        loadGame();
               		welcome();
		 }
                else {
                        printf("Good Bye!\n");
                }
      }
 

	return 0;
}
