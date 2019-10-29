#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TABLES 4
int count = 0;





struct guest
{
	int num_guests;
	char *guest_name; // we're using an array of pointers( aka pointer array) because names vary in size and we don't want to waste space -- at least in theory but it isin't actually implemented.
};

void addName(struct guest list);


struct guest room1[MAX_TABLES];

struct guest room2[MAX_TABLES];


int main ()
{

	addName(room1);

	//printf("name%s", room1[count].guest_name);

	printf("# of guests %d", room1[count].num_guests);

	return 0;
}



void addName(struct guest list) // remember that arrays are passed by reference in C!

// this function will read in the name_list and the number of people associated with the name_list.
{

	printf("\naddName():");
	char *temp;

	if(count < MAX_TABLES)
	{

		temp = (char *) malloc(11*sizeof(char)); // reassign a new memory location to the temp poiter each time the loop runs

		printf("\n\ntype name:");

		//scanf("%s", temp);

		//list[count]->guest_name = temp;

		printf("number of guests:");

		scanf("%d", &(list[count]->num_guests)); // I want to dereference. since I am scanning I need &

		count++;
	}

	else
	{
		printf("\nlist full!!! full capacity = %d", count);
	}

}
