/*
 ============================================================================
 Name        : struct_pointer_array.c
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

void insert();
void print();
void delete();
void quit();
void delete2();

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

		}

		else
		{
			new_node->next = list[0];
			list[0] = new_node;
		}


	}
	else 	if(new_node->number_guests >= 3 && new_node->number_guests <= 4)
	{
		if(list[1] == NULL)
		{
			new_node->next = NULL;
			list[1] = new_node;

		}

		else
		{
			new_node->next = list[1];
			list[1] = new_node;
		}


	}
	else 	if(new_node->number_guests >= 5 && new_node->number_guests <= 6)
	{
		if(list[2] == NULL)
		{
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
		if(list[3] == NULL)
		{
			new_node->next = NULL;
			list[3] = new_node;

		}

		else
		{
			new_node->next = list[3];
			list[3] = new_node;
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


void delete()
								// delete the number: remember it is a FIFO so I need to get to the end.
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
	struct guest *node, *prev_addr, *prev_node; // this node will be used the store the address of the last (earliest in terms of entry) with the given number
	//prev_addr = list[k]; // this is the same as setting it to list[k];


	if (addr == NULL)
	{
		printf("\n!!! category empty !!!");
	}
	else if (addr->next == NULL)
		// only one node in the list.
	{

		if(addr->number_guests == guest_number) // here we check the next one and so we can capture the
		{
			printf("\n#:%d at %p will be removed", addr->number_guests, addr);
			list[k] = NULL;
			free(addr);
		}

	}
	else
	{	printf("\nenter the else statement");


	if(addr->number_guests == guest_number && addr->next->number_guests != guest_number)
	{
		printf("\ndo we ever get here? ");
		list[k] = addr->next;
		free(addr);
	}

	else if(addr->number_guests == guest_number && addr->next->number_guests == guest_number)
	{
		printf("\ndo we ever get here? ");
		addr->next = addr->next->next;
		free(addr->next);
	}

	else
	{

		while(addr->next!=NULL)
		{
			prev_addr = addr;

			// need to take care of the situation where the number to be deleted is first in the list
			if(addr->next->number_guests == guest_number) // here we check the next one and so we can capture the
			{
				//printf("\n node to delete #:%d at %p", addr->number_guests, addr);
				prev_node=addr;
				node = addr->next; // and since I know the node I know node_.next;
			}

			addr = addr->next;
		}

		printf("\n update the nodes. ");
		prev_node->next = node->next; // this is the final line
		free(node);
	}


	// now update the list.

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


void delete2()
// delete the number: remember it is a FIFO so I need to get to the end.
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

	struct guest *node, *prev_addr, *prev_node; // this node will be used the store the address of the last (earliest in terms of entry) with the given number
	//prev_addr = list[k]; // this is the same as setting it to list[k];


	if (addr == NULL)
	{
		printf("\n!!! no such number !!!");
	}

	else
	{	printf("\nenter the else statement");



	if(addr->number_guests == guest_number && addr->next->number_guests != guest_number)
	{
		printf("\n start with two different numbers ");
		list[k] = addr->next;
		free(addr);
	}

	else if(addr->number_guests == guest_number && addr->next->number_guests == guest_number)
	{
		printf("\n start with two identical numbers ");
		addr->next = addr->next->next;
		free(addr->next);
	}

	else
	{

		while(addr->next!=NULL)
		{
			prev_addr = addr;

			// need to take care of the situation where the number to be deleted is first in the list
			if(addr->next->number_guests == guest_number) // here we check the next one and so we can capture the
			{
				//printf("\n node to delete #:%d at %p", addr->number_guests, addr);
				prev_node=addr;
				node = addr->next; // and since I know the node I know node_.next;
			}

			addr = addr->next;
		}

		printf("\n update the nodes. ");
		prev_node->next = node->next; // this is the final line
		free(node);
	}


	// now update the list.

	}
}
