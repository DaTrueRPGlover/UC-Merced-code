#include <stdio.h>

int main(){
	int rep = 0;
	int miss = 0;
	int value = 0;
	int value2 = 0;

	printf("Enter the number of repetitions for the punishment phrase: ");
	scanf("%d", &rep);
	while (rep <= 0) {
		printf("You entered an invalid value for the number of repetitions!\n");
		printf("Enter the number of repetitions for the punishment phrase again: ");
		scanf("%d", &rep);
	}
//	rep = value;
//	value = 0;
	
	printf("Enter the line where you wish to introduce the typo: ");
	scanf("%d",&miss);
	while (miss <= 0 || miss > rep) {
		printf("You entered an invalid value for the typo placement!\n");
		printf("Enter the line where you wish to introduce the typo again: ");
		scanf("%d", &miss);
	}
//	miss = value2;
	
	for(int i = 0; i < rep; i++){
		if (rep <= 0 || miss <= 0 || miss > rep) {
			break;
		}
		if(i == miss - 1){
			printf("Cading in C is fun end intreseting!\n");
		}
		else{ 
			printf("Coding in C is fun and interesting!\n"); 
		}
	}
	
	return 0;
}