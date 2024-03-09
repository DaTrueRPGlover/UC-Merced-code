#include <stdio.h>
#include<stdlib.h>



int main(){
	int unum = 1;
	int digit = 1;
	int digit_sum = 0;
	float evena = 0;
	float odda = 0;
	int totaln = 1;
	int temp_num = 0;
	int evenn = 0;
	int oddn = 0;

	while (unum != 0) {

		if (totaln == 1) {
			printf("Enter the %dst number : ", totaln);
		}

		if (totaln == 2) {
			printf("Enter the %dnd number : ", totaln);
		}

		if (totaln == 3) {
			printf("Enter the %drd number : ", totaln);
		}

		else if (totaln >= 4) {
			printf("Enter the %dth number : ", totaln);
		}

		scanf("%d", &unum);

//		digit = sizeof(unum);

		temp_num = abs(unum);

		while (temp_num > 0) {
			digit = temp_num % 10;
			digit_sum += digit;
			temp_num = temp_num / 10;
		}

		if (digit_sum % 2 == 0) {
			evena += unum;
			evenn += 1;
			digit_sum = 0;
		}

		else if (digit_sum % 2 == 1) {
			odda += unum;
			oddn += 1;
			digit_sum = 0;
		}

		totaln = totaln + 1;
	}

	evenn -= 1;

	evena = evena / evenn;
	odda = odda / oddn;

	printf("\n");

	if (oddn == 0 && oddn == 0) {
		printf("There is no average to compute. \n");
	}

	if (evenn > 0) {
		printf("%lf \n", evena);
	}

	if (oddn > 0) {
		printf("%lf \n", odda);
	}

	return 0;
}
