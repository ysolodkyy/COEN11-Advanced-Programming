/*
 ============================================================================
 Name        : union.c
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>


union stat
{
	int years_retired;
	float salary;
	char school[9];
};


struct human
{
	char * name;
	int age;
	union stat status;
};

int SIZE = 3; // initial size of the array
int counter = 0;

struct human *list; // so now I want to create an array of arbitrary length




int main(void)
{

	union stat var1;

	int scan = 1;

	while(scan > 0)
	{

		if(scan == 1)
		{
			printf("\nenter years:");
			scanf("%d", &var1.years_retired);
		}
		else if (scan == 2)
		{
			printf("\nenter salary:");
			scanf("%f", &var1.salary);
		}
		else
		{

			printf("\nenter school:");
			scanf("%s", var1.school);;
		}


		printf("%s", var1);

		printf("\nenter scan:");
		scanf("%d", &scan);
	}

	return EXIT_SUCCESS;
}
