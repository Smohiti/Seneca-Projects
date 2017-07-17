#include <stdio.h>
 
int main()
{
    int i, j, N;
 
    //Reads number of rows from user
    printf("Enter total rows : ");
    scanf("%d", &N);
 
    //Iterates over each row one by one
    for(i=1; i<=N; i++)
    {
        //Iterates over each column of the i-th row
        for(j=1; j<=N; j++)
        {
            if(i==1 || i==N || j==1 || j==N)
            {
                //Print star for first and last row and for first and last column
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
 
    return 0;
} 

