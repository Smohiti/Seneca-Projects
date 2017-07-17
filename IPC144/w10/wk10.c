#include <stdio.h>
#include <string.h>

void clear()
{
while(getchar()!='\n')
{}
}

int Validate_Alphanumberic(const char str[]) {
    int k,len,a=1;

    len = strlen(str);
    for (int i = 0; i < len; i++)
    {
        k = str[i];

        if ((k >= 65 && k <= 90)||(k >=97 && k <= 122)||(k >=48 && k <=57)||(k == 32))
        {
        }
        else
        {
            puts("Invalid,try again: ");
            clear();
            a=0;
            i=len;
           }
    }
return a;
};


void Get_Valid(char str[])
{


    int isture=0,i,len;

    char input[10]={'\0'};

    do
    {
        scanf("%[^\n]",input);
        isture = Validate_Alphanumberic(input);
   
    } while (isture==0);

strcpy(str,input);

if(strlen(str)>9)
str[9]='\0';

clear();

};


int main(){

    
    char str0[10], str1[10], str2[10], str3[10], str4[10];
    
    printf("Please enter items names:\n");
	printf("Item 1: ");
    Get_Valid(str0);
	printf("Item 2: ");
    Get_Valid(str1);
	printf("Item 3: ");
    Get_Valid(str2);
	printf("Item 4: ");
    Get_Valid(str3);
	printf("Item 5: ");
    Get_Valid(str4);
    
  
    printf("\n0-%.10s\n", str0);
    printf("1-%.10s\n", str1);
    printf("2-%.10s\n", str2);
    printf("3-%.10s\n", str3);
    printf("4-%.10s\n", str4);
        
};



