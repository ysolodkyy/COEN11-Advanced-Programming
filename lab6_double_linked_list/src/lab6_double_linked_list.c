/*
 ============================================================================
 Name        : lab6_double_linked_list.c
 ============================================================================
 */


#include <stdio.h>
#include <stdlib.h>

struct guest
{
	int number_guests;
	char name[11];
	struct guest *next;
	struct guest *prev;
};


// now I need to come up with an array that will allow me to categorize these by size. but it should be an array of pointers!

struct guest *list[] = {NULL, NULL, NULL, NULL}; // initialize all the pointers to NULL

void insert();
void print();
void delete();
void quit();

int main(void)

{
	int selection;

	while(1) // this time keep the functionality to 3 functions
	{
		printf("\n\nenter selections:\n(1) front insert() the list \n(2) delete() \n(3) show the list \n(0) exit.  ");
		scanf("%d", &selection);

		switch (selection)
		{
		case 1:
			insert();
			break;
		case 2:
			delete();
			break;

		case 3:
			print();
			break;

		case 0:
			quit();
			break;

		default:
			printf("\nselection %d: wrong choice. enter selctions 1-4 ", selection);
			break;

		}

	}
	return EXIT_SUCCESS;
}



void insert()
{
	struct guest * new_node = (struct guest *) malloc(sizeof(struct guest));

	// enter stuff into each one of the elements

	printf("\nenter the name: ");
	scanf("%s", new_node->name);

	printf("\n%s", new_node->name);

	printf("\nenter the # guests: ");
	scanf("%d", &new_node->number_guests);

	printf("\n%d", new_node->number_guests);




	if(new_node->number_guests >= 1 && new_node->number_guests <= 2)
	{
		if(list[0] == NULL)
		{
			new_node->next = NULL;
			list[0] = new_node;
			new_node->prev = list[0];

		}

		else
		{
			new_node->next = list[0];
			list[0] = new_node;
			new_node->prev = list[0];
		}


	}
	else 	if(new_node->number_guests >= 3 && new_node->number_guests <= 4)
	{
		if(list[1] == NULL)
		{
			new_node->next = NULL;
			list[1] = new_node;
			new_node->prev = list[1];
		}

		else
		{
			new_node->next = list[1];
			list[1] = new_node;
			new_node->prev = list[1];
		}


	}
	else 	if(new_node->number_guests >= 5 && new_node->number_guests <= 6)
	{
		if(list[2] == NULL)
		{
			new_node->next = NULL;
			list[2] = new_node;
			new_node->prev = list[2];
		}

		else
		{
			new_node->next = list[2];
			list[2] = new_node;
			new_node->prev = list[2];
		}
	}

	else
	{
		if(list[3] == NULL)
		{
			new_node->next = NULL;
			list[3] = new_node;
			new_node->prev = list[3];

		}

		else
		{
			new_node->next = list[3];
			list[3] = new_node;
			new_node->prev = list[3];
		}


	}
}


void print()
{


	for(int k = 0; k<4; k++)
	{
		struct guest *index = list[k];
		printf("\n\nlist[%d]:", k);

		while(index !=NULL)
		{
			printf("\n%s", index->name);
			printf(": party of %d", index->number_guests);
			index = index->next;
		}
	}
}



void quit()
{

	for(int k = 0; k<4; k++)
	{
		struct guest *index = list[k];
		struct guest *delete;

		printf("\nlist[%d]:", k);
		while(index !=NULL)
		{
			delete = index;
			index = index->next;
			free(delete);
		}
	}

	exit(0);
}



void delete() // delete the number: remember it is a FIFO so I need to get to the end.
{
	int guest_number, k;
	printf("\nenter the number of guests to delete");
	scanf("%d", &guest_number);



	if(guest_number >=1 && guest_number <=2)
	{
		k = 0;
	}

	else if(guest_number >=3 && guest_number <=4)
	{
		k = 1;
	}

	else if(guest_number >=5 && guest_number <=6)
	{
		k = 2;
	}
	else
	{
		k = 3;
	}

	struct guest *addr = list[k];
	struct guest *node; // this node will be used the store the address of the last (earliest in terms of entry) with the given number


	if (addr == NULL)
	{
		printf("\n!!! category empty !!!");
	}
	else
	{
		while(addr != NULL)
		{
			if(addr->number_guests== guest_number)
			{
				node = addr; // this will select the node we want to delete
			}
			addr = addr->next;
		}

		if (node->prev == list[k])
		{
			list[k] = node->next;
			node->next->prev=list[k];
			free(node);
		}
		// special case (3): the node is last in the list.

		else if(node->next == NULL)
		{
			node->prev->next = NULL;
			free(node);
		}

		// general case: the node is somewhere in the middle

		else
		{
			node->prev->next = node->next;
			node->next->prev=node->prev;
			free(node);

		}

	}

}
