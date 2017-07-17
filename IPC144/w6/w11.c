#include <stdio.h> 
#include <stdlib.h> 
#include <time.h>
void clearbuffer() {
	int next = 0;
	while (next != '\n'){
              next =getchar();
	}
}


void seedrandom(){
	srand(time(NULL));
}

float getrandom (float a, float b){
        double x;
        x = a + ((double) rand() / RAND_MAX * (b - a));
//      printf("DEBUG;Random number is %.2lf\n", x);
	return x;
}

int main() {
    	int contin = 0;
    	float strengthS ,speedS , defenceS , intelligenceS;
    	float level = 0, hp = 0;
	do{	
		seedrandom();		
		strengthS = getrandom(0.15,0.5);
		speedS = getrandom(0.15,0.5);
		defenceS = getrandom(0.15,0.5);
		intelligenceS = getrandom(0.15,0.5);
		level = getrandom(3.0,20.0);
        	hp = getrandom(0.5,2.0);
		
//       	printf("DEBUG  ;%.1f , %.1f , %.1f , %.1f , %.1f , %.1f\n",strengthS,speedS,defenceS,intelligenceS,level,hp);
        	printf("Enemy Generator\n\n");
        
        	printf(" Level        - %0.f\n", level);
        	printf(" HP           - %0.f\n", hp*level);
        	printf(" Strength     - %0.f\n", strengthS * level*level);
        	printf(" Speed        - %0.f\n", speedS * level*level);
        	printf(" Defence      - %0.f\n", defenceS * level*level);
        	printf(" Intelligence - %0.f\n", intelligenceS * level*level);
        	printf("\n Generate Another?");
		scanf("%d", &contin);
		clearbuffer();
			while (contin != 1 && contin != 2) {
	        		printf(" Invalid input  ");
			        scanf("%d",&contin);
				clearbuffer();

	        	}

	}
	while (contin !=2);
	return 0;
}
