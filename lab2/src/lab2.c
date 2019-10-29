/*
 ============================================================================
 Description : lab2
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

# define CAPACITY 4

char *name_list[CAPACITY];
int num_guests[CAPACITY];
int count = 0;

// now I need to define functions that will perform the functions.

void addName();

void showList();

void removeLast(int number);

int main(void)
{
	int selection;


	while(1)
	{
		printf("\n\nenter seelctions:\n(1) add party to the list; \n(2) remove party from the list; \n(3) show names on the list; \n(4) exit.  ");
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

	if(count < CAPACITY)
	{

		temp = (char *) malloc(11*sizeof(char)); // reassign a new memory location to the temp poiter each time the loop runs

		printf("\n\ntype name:");

		scanf("%s", temp);

		name_list[count] = temp;

		printf("number of guests:");

		scanf("%d", &num_guests[count]);

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
			printf("\n guest name: %s", name_list[i]);
			printf(", party of %d", num_guests[i]);
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
			if(num_guests[index] == number)
			{
				break;
			}
			index ++;
		}

		printf("\nremove %s with the party of %d", name_list[index], num_guests[index]);

		for(int i = index; i < (count-1); i++)
		{
			name_list[i] =  name_list[i+1];
			num_guests[i] = num_guests[i+1];
		}

		count--;
	}
}

/*
// functional controls -- disable for now.
 */

/*
char name_list[11]; // made this array of length 11 arbitrarily. remember that arrays are pointers!
	int number;

	printf("\n enter the name_list of the customer:");
	scanf("%s", name_list);


 */

/*


	printf("\n current count: %d", count);
	//printf("\n %s", name_list[count]);

	for (int i = 0; i < CAPACITY; i++)
	{

		printf("\n:%s", name_list[i]);
		printf("\n:%d", num_guests[i]);
	}

	addName();

	showList();

	printf("\n current count: %d", count);

	addName();

	showList();

	printf("\n current count: %d", count);

	addName();

	showList();

	printf("\n current count: %d", count);


	//	printf("\n the count after adding is %d", count);
	//	//printf("\n %s", name_list[count]);
	//
	//





 */
