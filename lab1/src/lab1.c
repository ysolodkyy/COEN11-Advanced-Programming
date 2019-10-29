/*
 ============================================================================
Description: Division test.

for this function we only want to match the quotient, so there is no need to fuss around with the remainder.

useful links:

https://www.programiz.com/c-programming/c-operators#operator


 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int division(int divisor, int dividend);

int main(void)
{
	int counter = 0;
	int divisor, dividend;

	// step 1: generate random numbers:

	// call out the srand() function.

	srand((int) time(NULL)); // random seed

	// step 2: do the rest

	for (int i = 0; i < 10; i++)
	{
		printf("\ni= %d", i);

		divisor  = rand()%12+1;
		dividend = rand()%13;

		printf("\ndivisor = %d",divisor);
		printf("\ndividend = %d",dividend);


		counter = counter + division(divisor, dividend);


		printf("\ncounter = %d.\n\n",counter);

	}

	printf("\n\n\t\t total correct answers: %d.\n you get %f percent right", counter, (float) counter/10);
	return EXIT_SUCCESS;
}


int division(int divisor, int dividend)

{
	int answer;
	int quotient = dividend/divisor;


	printf("\n%d / %d = ?", dividend, divisor);

	scanf("%d", &answer);

	printf("\nquotient = %d",quotient);


	if (answer == quotient)
	{
		return 1;
	}
	else

		return 0;
}
