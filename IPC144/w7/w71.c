#include <stdio.h>

#include <stdlib.h>




int Find_Item(int id[],int size,int item)

{

int i = 0;

for (i = 0; i < size; ++i){

if (id[i] == item)

return i;

}

return -1;

}




int Add_Item(int id[],int quantity[], int size, int item)

{

int index = Find_Item(id, size, item);

if (index != -1){

quantity[index] += 1;

return 1;

} else{

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




int Use_Item(int id[],int quantity[],int size,int item)

{

int index = Find_Item(id, size, item);

if (index == -1)

return 0;




if (quantity[index] > 0){

quantity[index] -= 1;

return 1;

}




return 0;

}




void Print_Item(int item)

{

char data[5][20] = {"Potion ","HP Booster ","Strength Booster ","Defense Booster"};




if (item < 0 || item > 4)

return;




printf("%sX", data[item]);

}

void printUserMenu(){

printf("1.Get New Item\n2.Show Inventory\n3.Use Item\n4.Quit. \n");

}

int main() {

int id[3];

int quantity[3];

int i;

int size = 3;

int choice;

int item;

for (i = 0; i < size; ++i){

id[i] = 0;

quantity[i] = 0;

}




while (1){

printf("1.Get New Item\n2.Show Inventory\n3.Use Item\n4.Quit. \n");

printf("\nSelect Option: ");

scanf("%d", &choice);

if (choice < 0 || choice > 4){

printf("Invalid Input\n");

continue;

} else if (choice == 4){

break;

} else if (choice == 1){

item = rand() % 5;

if (item < 0)

item = -item;

if (1 == Add_Item(id, quantity, size, item))

printf("\nNew Item Added!\n\n");

else

printf("\nInventory is already full!\n\n");

} else if (choice == 2){

printf("\n");

for(i = 0;i < 3; i++)

{

printf("%d. ",id[i]);

Print_Item(id[i]); //Use the function explained above.

printf("%d\n",quantity[i]);

}

printf("\n");

} else if (choice == 3){

printf("Select item: ");

scanf("%d", &item);

if (Use_Item(id, quantity, size, item) == 1)

printf("You dont have that item!\n\n");

else

printf("Item used!\n\n");




}

}




return 0;

}
