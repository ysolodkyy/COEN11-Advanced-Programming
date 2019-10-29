/*
 ============================================================================
 Name        : strcp.c
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void print();

char temp[7];


int counter = 1;

int main(void)
{

	printf("name1:");
	scanf("%s", temp);

	printf("\nname1: %s", temp);




	print();

	return EXIT_SUCCESS;
}


void print()
{
	char name[7];

	printf("name:");
	scanf("%s", name);

	printf("name: %s", name);
	int index=0;

	printf("\n index = %d, counter =%d", index, counter);

	while(index <= counter)
	{
		printf("\n inside while");

		if(!strcmp(name,temp))
				{
			printf("strcmp(name,temp) = %d", strcmp(name,temp));
					counter--;
					break;
				}
				else if(index == counter && (strcmp(name,temp)))
					printf("\n no match found!");

				index++;

	}

}
