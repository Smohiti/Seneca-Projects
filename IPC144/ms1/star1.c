#include <stdio.h>
 
void displayBoard(unsigned int N){
 
    //Reads number of rows from user
 
    //Iterates over each row one by one
    for(int i=1; i<=N; i++)
    {
        //Iterates over each column of the i-th row
        for(int j=1; j<=N; j++)
        {
            if( i==1 || i==N || j==1 || j==N)
            {
                //Print star for first and last row and for first and last column
              //  printf("*");
		printf("  ___\n ");
                printf("|   |\n ");
                printf("|___|\n");

            }
            else
            {
                printf(" ");
            }
        }
 
        //Move to the next line/row
        printf("\n");
    }
}
int main(){
	int s = 1;
        printf("getTileType test passed!\nEnter board size: ");
        scanf("%d", &s);
        displayBoard(s);

 
}

