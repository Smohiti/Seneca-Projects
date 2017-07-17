#include <stdio.h>

int main(void) {
	int pStrength = 10, pDefense = 20, pIntelligence = 40, pHP = 10;
	int eStrength = 30, eDefense = 40, eIntelligence = 25, eHP = 10;
	int select = 0;

	printf("Battle Start!\n\n");
	while(pHP > 0 && eHP > 0){

	        printf("Your HP: %d Enemy HP: %d\n", pHP, eHP);
        	printf("1 - Attack\n2 - Magic");
       		printf("\n\nSelect your move: ");
       		scanf("%d", &select);

	        if(select == 1){
			eHP = eHP - ((float) pStrength / eDefense * 5);
			printf("\nYou attacked the enemy!\n");
		
                }
      		else if(select == 2){
			eHP = eHP - (((float) pIntelligence / eIntelligence) * 5 );
        		printf("\nYou shocked the enemy!\n");
		}
    		if(eHP <= 0) {
        		printf("You won!\n\n");
    		} else{
		        pHP = pHP - ((float) eStrength / pDefense * 5);
			printf("The enemy attacked you!\n");
		}
    		if(pHP <= 0) {
        		printf("You died!\n\n");
    		}
	}
    	return 0;
}
