#include <stdio.h>
int main(){
int n;
	printf("inter a number:");
	scanf("%d", &n);
	for(int count = n ; count >=0 ; count--){
		printf("%d\n",count);
	}
	return 0;
}
