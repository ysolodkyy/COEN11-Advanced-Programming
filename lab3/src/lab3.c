/*
 ============================================================================
 Description : lab3
 ============================================================================
 */

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


struct guest list[MAX_TABLES];

// now I need to define functions that will perform the functions.

void addName();

void showList();

void removeLast(int number);

int main(void)
{
	int selection;


	while(1)
	{
		printf("\n\nenter selections:\n(1) add party to the list; \n(2) remove party from the list; \n(3) show names on the list; \n(4) exit.  ");
		scanf("%d", &selection);

		switch (selection)
		{
		case 1:
			addName();
			break;
		case 2:
			printf("\nwhat's the size of the party?");

			int var;
			scanf("%d", &var);
			removeLast(var);
			break;

		case 3:
			showList();
			break;

		case 4:
			printf("\nselection %d: exit(0) the program  ", selection);
			exit(0);
			break;

		default:
			printf("\nselection %d: wrong choice. enter selctions 1-4 ", selection);
			break;

		}

	}

	return EXIT_SUCCESS;
}

void addName()
// this function will read in the name_list and the number of people associated with the name_list.
{

	printf("\naddName():");
	char *temp;

	if(count < MAX_TABLES)
	{

		temp = (char *) malloc(11*sizeof(char)); // reassign a new memory location to the temp poiter each time the loop runs

		printf("\n\ntype name:");

		scanf("%s", temp);

		list[count].guest_name=temp;

		printf("number of guests:");

		scanf("%d", &list[count].num_guests);

		count++;
	}

	else
	{
		printf("\nlist full!!! full capacity = %d", count);
	}

}

void showList()

{
	if (count == 0)
	{
		printf("\n the list is empty.");
	}

	else
	{
		printf("\n showlist(): \n");
		for (int i = 0; i < count; i++)
		{
			printf("\n guest name: %s", list[i].guest_name);
			printf(", party of %d", list[i].num_guests);
		}
	}
}

void removeLast(int number)
{
	if (count ==0)
	{
		printf("\nlist is empty");
	}
	else
	{

		printf("\nremoveLast():");

		int index = 0;

		while(index < count)
		{
			if(list[index].num_guests == number)
			{
				break;
			}
			index ++;
		}

		printf("\nremove %s with the party of %d", list[index].guest_name, list[index].num_guests);

		for(int i = index; i < (count-1); i++)
		{
			list[i].guest_name =  list[i+1].guest_name;
			list[i].num_guests = list[i+1].num_guests;
		}

		count--;
	}
}
