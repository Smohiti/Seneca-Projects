#include <stdio.h>

#include <stdlib.h>

#define SIZE 3

#define FULL 5

int Find_Item(int id[], int size, int item){
    int index = -1;
    for(int i=0;i<size;i++){
        if(id[i] == item){
            index = i;
            i =size;
        }
    }
    return index;
}
int Add_Item(int id[], int quantity[], int size, int item){
    int index=-1,exit=-1;
	index=Find_Item(id,size,item);
	if (index>=0 && index<=4){
	quantity[index]++;
	exit=1;
	}
	else if(index==-1){
		for (int i=0; i<size ;i++){
            if(id[i]>=0){
                if(quantity[i] == 0){
                    id[i]=item;
                    quantity[i]+=1;
                    exit=1;
                    i=size;
                }
                else{
                    exit=0;
				 }
            }
        }
    }
    if(exit==1)
        printf("\nNew item Added !\n");
    if(exit==0)
        printf("Inventory is already full!\n");
    return exit;
}
int Use_Item(int id[], int quantity[], int size, int item){
    int j=-1,a=-1;
    a=Find_Item(id,size,item);
    if(a==-1){
        printf("\nYou don't have that item \n");
        j=0;
    }
    else{
        for (int i=0; i<size ;i++){
            if(id[i]==item){
                if(quantity[i]>=0){
                    if(quantity[i]-1>=0){
                        quantity[i]-=1;
                        j=1;
                        printf("\nItem Used\n");
                    }
                    else{
                        j=0;
                        printf("\nYou don't have that item.\n");
                    }
                }
            }
        }
    }
    return j;
}
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
int main (){
    int size =3;
    int id[SIZE] = {0,0,0};
    int quantity[SIZE] = {0,0,0};
    int userInput = 0;
    int itemnum = -1;
    while(userInput != 4){
        printf("1. Get New Item\n");
        printf("2. Show Inventory\n");
        printf("3. Use Item\n");
        printf("4. Quit.\n");
        printf("Select Option: ");
        scanf("%d", &userInput);
        int c=1, n, m;
        for (c = 1; c <= 10; c++) {
            n = (rand() % 4) + 1;
            m = n;
    }
        if(userInput == 1){
            Add_Item(id, quantity,size,m);
        }
        else if(userInput == 2){
            for(int i=0;i<size;i++){
                if(quantity[i]>0){
                    printf("%d.", id[i]);
                    Print_Item(id[i]);
                    printf("%d\n", quantity[i]);
                }
                else if(quantity[i]>0){
                    printf("Your inventory is empty!\n\n");
                    i = size;
                }
            }
        }

        else if(userInput == 3){
            printf("Select Item: ");
            scanf("%d", &itemnum);
            Use_Item(id,quantity,size,itemnum);
        }
        else{
            if(userInput!=4){
                printf("please choose right option:\n");
            }
        }
clear();
}
    return 0;
}

