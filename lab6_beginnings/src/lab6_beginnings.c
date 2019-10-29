/*
 ============================================================================
 reference : https://overiq.com/c-programming-101/array-of-pointers-in-c/
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

struct guest
{
	int number_guests;
	char name[11];
	struct guest *next;
};


// now I need to come up with an array that will allow me to categorize these by size. but it should be an array of pointers!

struct guest *list[] = {NULL, NULL, NULL, NULL}; // initialize all the pointers to NULL


// now let's get the three functions defined (1) insert() to the list, (2) delete() selected number, and (3) print() all lists.

void insert();
//void delete();
void print(); // this function is supposed to traverse all lists
//struct guest *find_name(struct guest *);

int main(void)

{

	int selection;

	while(1) // this time keep the functionality to 3 functions
	{
		printf("\n\nenter selections:\n(1) front insert() the list \n(2) pop() from the list \n(3) show the list \n(0) exit.  ");
		scanf("%d", &selection);

		switch (selection)
		{
		case 1:
			insert();
			break;
		case 2:
			//delete();
			break;

		case 3:
			print();
			break;

		case 0:
			printf("\nselection %d: exit(0) the program  ", selection);
			exit(0); // need to come up with the quit function !
			break;

		default:
			printf("\nselection %d: wrong choice. enter selctions 1-4 ", selection);
			break;

		}

	}
	return EXIT_SUCCESS;
}



void insert()
// this function is to behave differently and to add a node at the beginning of the list.
{
	struct guest * new_node = (struct guest *) malloc(sizeof(struct guest)); // create a new node and allocate memory.

	// capture data
	printf("\nenter the name:");
	scanf("%s", new_node->name);

	printf("enter the number of guests:");
	scanf("%d", &(new_node->number_guests));


	printf("\n%s", new_node->name);
	printf("\n%d", new_node->number_guests);


	if(new_node->number_guests >=1 && new_node->number_guests <=2)
	{
		printf("\nin branch 1-2");

		if(list[0] == NULL)
		{
			new_node->next = NULL;
			list[0] = new_node;

		}
		else
		{
			new_node->next = list[0];
			list[0] = new_node;
		}

	}

	else if(new_node->number_guests >=3 && new_node->number_guests <=4)
	{
		printf("\nin branch 3-4");

		if(list[1] == NULL)
		{	printf("\ninside the if statement");

		new_node->next = NULL;
		list[1] = new_node;
		}
		else
		{
			new_node->next = list[1];
			list[1] = new_node;

		}
	}

	else if(new_node->number_guests >=5 && new_node->number_guests <=6)
	{
		printf("\nin branch 5-6");

		if(list[2] == NULL)
		{	printf("\ninside the if statement");

		new_node->next = NULL;
		list[2] = new_node;
		}
		else
		{
			new_node->next = list[2];
			list[2] = new_node;

		}
	}

	else
	{
		printf("\nin branch 7 or greater");

		if(list[3] == NULL)
		{
			printf("\ninside the if statement");

			new_node->next = NULL;
			list[3] = new_node;
		}
		else
		{	printf("\ninside the else statement");

		new_node->next = list[3];
		list[3] = new_node;

		}
	}
}



void print()
{
	for (int i = 0; i<4; i++ )
	{
		struct guest * index = list[i]; // use the index to traverse through the list

		if(index == NULL)
		{
			printf("\n the list is empty");
		}
		else
		{
			while (index != NULL)
			{
				printf("\nGuest:  %s, party of %d", index->name, index->number_guests);
				index = index->next;
			}

		}
	}
}
