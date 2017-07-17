#include <stdio.h>
#include <string.h>

void clear()
{
while(getchar()!='\n')
{}
}

int Validate_Alphanumberic(const char str[]);

void Get_Valid(char str[]);


int main(){

    int i;
    
    char str0[10], str1[10], str2[10], str3[10], str4[10];
    
    printf("\nPlease enter items names:");
	printf("\nItem 1:");
    Get_Valid(str0);
	printf("\nItem 2:");
    Get_Valid(str1);
	printf("\nItem 3:");

    Get_Valid(str2);
	printf("\nItem 4:");

    Get_Valid(str3);
	printf("\nItem 5:");

    Get_Valid(str4);
    
    printf("\n");
  
    printf("\n0-%.10s", str0);
    printf("\n1-%.10s", str1);
    printf("\n2-%.10s", str2);
    printf("\n3-%.10s", str3);
    printf("\n4-%.10s", str4);
        
};

int Validate_Alphanumberic(const char str[]) {
    int i,c,j,len,a=1;

    len = strlen(str);
    for (i = 0; i < len; i++)
    {
        c = str[i];

        if ((c >= 65 &&c<=90)||(c>=97&&c <= 122)||(c>=48&&c<=57)||(c==32)) 
	{            
        }
        else
        {
            puts("\nInvalid,try again:");
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
