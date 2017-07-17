#include <stdio.h>
#include <stdlib.h>
void menu() {
        printf("1. Get New Item\n");
        printf("2. Show Inventory\n");
        printf("3. Use Item\n");
        printf("4. Quit\n\n");
        printf("Select option: ");
        }
int Find_Item(int id[],int size,int item){
    int i = 0;
    for (i = 0; i < size; ++i){
    if (id[i] == item)
    return i;
    }
    return -1;
}
int Add_Item(int id[],int quantity[], int size, int item){
    int index = Find_Item(id, size, item);
    if (index != -1){
        quantity[index] += 1;
    return 1;
    }
    else{
        for (index = 0; index < size; ++index){
            if (quantity[index] == 0){
                quantity[index] = 1;
                id[index] = item;
                return 1;
            }
        }
    }
    return 0;
}
int Use_Item(int id[],int quantity[],int size,int item){
    int index = Find_Item(id, size, item);
    if (index == -1)
    return 0;
    if (quantity[index] > 0){
        quantity[index] -= 1;
    return 1;
    }
    return 0;
}
/*
void Print_Item(int item){
    char data[5][20] = {"Potion ","HP Booster ","Strength Booster 
","Defense Booster"};
    if (item < 0 || item > 4)
    return;
        printf("%sX", data[item]);
}
*/
void Print_Item(int item){
    if(item==0)
        printf("Portion X");
    else if(item==1)
        printf("HP Booster X");
    else if(item==2)
        printf("Strength Booster X");
    else if(item==3)
        printf("Defence Booster X");
    else if(item==4)
        printf("Intelligence Booster X");
}
void clear(){
    while(getchar()!='\n'){
        }
}
int main() {
    int id[3];
    int quantity[3];
    int i;
    int size = 3;
    int userinp;
    int item;
    for (i = 0; i < size; ++i){
        id[i] = 0;
        quantity[i] = 0;
    }
    do{
        menu();
        scanf("%d", &userinp);
        if (userinp == 1){
            item = rand() % 4;
        if (item < 0)
            item = -item;
        else if (1 == Add_Item(id, quantity, size, item))
            printf("\nNew Item Added!\n\n");
        else
            printf("\nInventory is already full!\n\n");
        }
        if (userinp == 2){
            printf("\n");
            for(i = 0;i < 3; i++){
                printf("%d. ",id[i]);
                Print_Item(id[i]);
                printf("%d\n",quantity[i]);
            }
            printf("\n");
        }
        if (userinp == 3){
            printf("Select item: ");
            scanf("%d", &item);
        if (Use_Item(id, quantity, size, item) == 1)
            printf("You don't have that item!\n\n");
        else
            printf("Item used!\n\n");
        }
    }
    while(userinp!=4);
    return 0;
}

