/*
 ============================================================================
First I will create a simple linked list.

then I will do the rest
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// define the class first

struct guest
{
	int number_guests;
	char name[7];
	struct guest * next;
};

void insert();
void append(); // very crude function at first
void print();
void delete();
void pop();
struct guest *find_name(struct guest *);


struct guest * list = NULL ; // this is the crucial step -- initialize the HEAD

int main(void)
{

	int selection;

	while(1)
	{
		printf("\n\nenter selections:\n(1) front insert() the list; \n(2) pop() from the list; \n(3) show the list; \n(4) append() to the list; \n(5) find name() in the list; \n(6) delete() from the list; \n(0) exit.  ");
		scanf("%d", &selection);

		switch (selection)
		{
		case 1:
			insert();
			break;
		case 2:
			pop();
			break;

		case 3:
			print();
			break;

		case 4:
			append();
			break;
		case 5:
			find_name(list);
			break;
		case 6:
			delete();
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

	free(list); // free the memory allocated to the list

	return EXIT_SUCCESS;
}



void append()

{
	struct guest * new_node = (struct guest *) malloc(sizeof(struct guest)); // create a new node and allocate memory.

	// capture data

	printf("\nenter the name:");
	scanf("%s", new_node->name);

	printf("enter the number of guests:");
	scanf("%d", &(new_node->number_guests));

	new_node->next = NULL; // this is a crucial step. without it we'll never end the while loop below.  NULL  says I am last node. nothing else there.

	//printf("\nthe name is  %s", new_node->name);
	//printf("\nthe number of guests entered = %d", (new_node->number_guests));

	//finished capturing data

	if (find_name(new_node) != NULL)
	{
		printf("\n can't have repeating names in the list");
		free(new_node);
	}
	else
	{

		if (list == NULL)
		{
			list = new_node; // if the list is initially empty, point it to the first node.
		}

		else
		{
			struct guest * index; // create a pointer to index through the list

			index = list; // start at the beginning of the list

			while (index->next != NULL ) // we'll escape this while loop as soon as index is NULL
			{
				index = index->next;
			}

			index->next = new_node; // && new_node ->next == NULL already!

		}

	}


}

void print()
{
	struct guest * index = list; // use the index to traverse through the list

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


void pop() // this is going to pop the last node in the list, which makes the setup a FILO. NEED TO CHANGE THAT.
{
	struct guest *prev_index, * index = list; // use the index to traverse through the list

	if(index == NULL)
	{
		//printf("\n the list is empty");
	}
	else if (index->next == NULL)
	{
		//printf("\npop() %s, party of %d", index->name, index->number_guests);
		free(index);
		list = NULL;
	}
	else

	{
		printf("\n else the while() loop");

		while (index->next != NULL)
		{
			printf("\nupdade indices inside the while loop");
			prev_index = index;
			index = index->next;
		}

		//printf("\nprev_index->next: %p", prev_index->next);
		//printf("\nindext: %p", index);

		prev_index->next = NULL;
		printf("\npop() %s, party of %d", index->name, index->number_guests);
		free(index);

	}

}


void insert()
// this function is to behave differently and to add a done at the beginning of the list.
{
	struct guest * new_node = (struct guest *) malloc(sizeof(struct guest)); // create a new node and allocate memory.

	// capture data
	printf("\nenter the name:");
	scanf("%s", new_node->name);

	printf("enter the number of guests:");
	scanf("%d", &(new_node->number_guests));

	if(list == NULL)
	{
		new_node->next = list;
		list = new_node;
	}
	else
	{
		if (find_name(new_node) != NULL)
		{
			printf("\n can't have repeating names in the list");
			free(new_node);
		}

		else
		{
			new_node->next = list;
			list = new_node;

		}
	}
}


void delete()
{

	if(list == NULL)
	{
		printf("\nthe list is empty");
	}

	else
	{
		printf("\nenter the name: ");
		char search_name[7];
		scanf("%s",search_name);


		struct guest *index, *prev_index;
		index = list;


		while(index!= NULL)
		{
			printf("\n comparing %s to %s...", index->name, search_name);

			if(!strcmp(search_name,index->name))
			{
				break;
			}
			else
			{
				prev_index = index;
				index=index->next;
			}
		}

		//printf("\noutside the while loop the pointer value is %p", index);

		if (index == NULL)
		{
			printf("\nThe name %s was not found",search_name);
		}

		else // this should never occur
		{
			if(index==list)
			{
				list = index->next;
				free(index);
			}
			else
			{
				printf("\nremoving %s", index->name);
				prev_index->next = index->next;
				free(index);

			}
		}
	}

}


struct guest *find_name( struct guest * arr) // I think this function should return the index pointer so that the other function can use the pointer to locate the name
{
	struct guest *index;
	index = list;

	if(list == NULL)
	{
		printf("\nthe list is empty");
	}

	else
	{
		//printf("\nenter the name: ");
		//char search_name[7] = arr->name;
		//scanf("%s",search_name);

		while(index!= NULL)
		{
			printf("\n comparing %s to %s...", index->name, arr->name);

			if(!strcmp(arr->name,index->name))
			{
				break;
			}
			else
			{
				index=index->next;
			}
		}

		//printf("\noutside the while loop the pointer value is %p", index);

		if (index == NULL)
		{
			printf("\nThe name %s was not found",arr->name);
		}

		else // this should never occur
		{
			printf("\n found matching name %s", index->name);
		}
	}

	return index;

}
