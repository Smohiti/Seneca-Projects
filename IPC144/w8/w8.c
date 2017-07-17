#include <stdio.h>

struct Player{
    int level;
    int str;
    int speed;
    int def;
    int intel;
    int luck;
    int hp;
};
struct Item{
    int type;
    int power;
};
struct Item loadItem();
struct Player loadPlayer();
struct Item loadItem();

void printData(struct Player player1, struct Item itemList[], int listsize){
    int i = 0;

    printf("Collected Input: \n");
    printf("Lvl   Str   Spd   Def   Int   Lck   MHP\n");
    printf(" %d    %d    %d    %d    %d    %d    %d",player1.level,player1.str,player1.speed,player1.def,player1.intel,player1.luck,player1.hp);
    printf("\n\n");
    printf("Type  Power\n");
    for(i=0;i<listsize;i++)
        printf("  %d    %d\n",itemList[i].type,itemList[i].power);
    return;
}



int main(){
    struct Player player1 = loadPlayer();
    struct Item itemList[2];
    itemList[0]=loadItem();
    itemList[1]=loadItem();
    printData(player1,itemList,2);
    return 0;
}
struct Item loadItem(){
    struct Item item;

    printf("Please Enter the following item info:\n");
    printf("Type: ");
    scanf("%d",&item.type);
    printf("Power: ");
    scanf("%d",&item.power);
    printf("\n");

    return item;
}
struct Player loadPlayer(){
    struct Player player;
    printf("Please enter the following player info:\n");
    printf("Level: ");
    scanf("%d",&player.level);
    printf("Strength: ");
    scanf("%d",&player.str);
    printf("Speed: ");
    scanf("%d",&player.speed);
    printf("Defense: ");
    scanf("%d",&player.def);
    printf("Intelligence: ");
    scanf("%d",&player.intel);
    printf("Luck: ");
    scanf("%d",&player.luck);
    printf("Max HP: ");
    scanf("%d",&player.hp);
    printf("\n");
    return player;
}
