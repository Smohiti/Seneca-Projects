#include <stdio.h>


void rest_at_inn(float *days_remaining, int *hp_remaining, int *MAX) {

    *hp_remaining = 10;
    *days_remaining -= 1;
    if (*days_remaining > 0)
        printf("You rested up the at the inn\n\n");
    else /*(*days_remaining<=0)*/
        printf("Game Over!\n");

}


void train(float *days_remaining, int *hp_remaining, int *experience) {

    *experience += 10;
    *hp_remaining = *hp_remaining - 2;
    *days_remaining = *days_remaining - 0.5;
    printf("You did some training!\n\n");

}


void battle_demon_lord(int *current_hp) {

    *current_hp = 0;
    printf("He's too strong!\n\n");
    printf("Game Over!\n");
}


void Quit_Game() {

    printf("Good bye!\n\n");

}

int main() {

    
    float days_remaining = 8;
    int current_hp = 10;
    int hp_remaining = 10;
    int MAX = 10;
    int experience = 0;
    int selection;


     while (days_remaining > 0 && current_hp > 0 && selection != 4){

        printf("\n\nDays remaining: %.1f  HP: %d  EXP: %d\n\n", days_remaining, hp_remaining, experience);
        printf("1 - Rest at Inn\n");
        printf("2 - Train\n");
        printf("3 - Fight the Demon Lord\n");
        printf("4 - Quit Game\n\n");
        printf("Select:");
        scanf("%d", &selection);
        

      
            if(selection == 1)
                rest_at_inn(&days_remaining, &hp_remaining, &MAX);
                
            if(selection == 2)
                train(&days_remaining, &hp_remaining, &experience);
                
            if(selection == 3)
                battle_demon_lord(&current_hp);
                
            if(selection == 4)
                Quit_Game();
      }         
        


    return 0;

}




