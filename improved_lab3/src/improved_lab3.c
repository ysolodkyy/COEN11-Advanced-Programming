/*
 ============================================================================
 Description : lab3, but this one has 2 rooms, so the functions will have to have argument nows.
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
	char *guest_name; // we're using an array of pointers( aka pointer array) because names vary in size and we don't want to waste space 
};


struct guest list[MAX_TABLES];

// now I need to define functions that will perform the functions.

void addName(struct guest *arr); // again deed the * to indicate it is an array, or pointer, and not a variable. Still remember that arrays are passed by reference

void showList(struct guest *arr);

void removeLast(struct guest *arr);

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
			addName(list);
			break;
		case 2:
			removeLast(list);
			break;

		case 3:
			showList(list);
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

void addName(struct guest *arr)
// again need the * to indicate it is an array, or pointer, and not a variable. Still remember that arrays are passed by reference
{

	printf("\naddName():");
	char *temp;

	if(count < MAX_TABLES)
	{

		temp = (char *) malloc(11*sizeof(char)); // reassign a new memory location to the temp poiter each time the loop runs

		printf("\n\ntype name:");

		scanf("%s", temp);

		arr[count].guest_name=temp;

		printf("number of guests:");

		scanf("%d", &(arr[count].num_guests));

		count++;
	}

	else
	{
		printf("\nlist full!!! full capacity = %d", count);
	}

}

void showList(struct guest *arr)

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
			printf("\n guest name: %s", arr[i].guest_name);
			printf(", party of %d", arr[i].num_guests);
		}
	}
}


void removeLast(struct guest *arr)
{

	printf("\nwhat's the size of the party?");

	int number;
	scanf("%d", &number);

	if (count ==0)
	{
		printf("\nlist is empty");
	}
	else
	{

		printf("\nremoveLast():");

		int index = 0;
		int match = 0;
		while(index < count)
		{
			if(arr[index].num_guests == number)
			{	match = 1;
				break;
			}
			index ++;
		}

		if (match == 1)
		{

			printf("\nremove %s with the party of %d", arr[index].guest_name, arr[index].num_guests);

			for(int i = index; i < (count-1); i++)
			{
				arr[i].guest_name =  arr[i+1].guest_name;
				arr[i].num_guests = arr[i+1].num_guests;
			}

			count--;

		}
		else
		{
			printf("\nNo matching number of guests found!!");
		}
	}
}
