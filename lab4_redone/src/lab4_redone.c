/*
 ============================================================================
attempting to redo lab 4 using the resize array code as the basis, the functionality is essentially the same, but the data types are different.
for whatever reason I cannon make this code work with lists being passed as arguments : int *arr. Works great for global variable only.
(1) so now let's change the datatype to something more exciting
struct person

{
int age;
char name[7];
};
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
# define N 3

int SIZE = N; // I will try to maybe change the size if there is a need to modify the size of the array



struct person

{
	int age;
	float gpa;
	char name[7];
};


struct person *list; // remember: arrays are pointers! This is only a pointer -- NO Memory has been allocated yet!

int counter = 0;
int alloc = 0;


void insert(); // very crude function at first

void delete();


void show();

int main(void)
{

	int selection;

	while(1)
	{
		printf("\n\nenter selections:\n(1) insert() the list; \n(2) delete() from the list; \n(3) show the list; \n(4) exit.  ");
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
			show();
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

	free(list); // free the memory allocated to the list
	return EXIT_SUCCESS;

}


void insert()

{	printf("\ninsert():");

if (alloc !=1 ) // allocate initial memory.
{
	list = (struct person *) malloc(SIZE*sizeof(struct person)); // it would make more sense to have this in the main() function !
	alloc = 1; // update alloc so we don't allocate new memory each time we call the function
}

printf("\n counter= %d, SIZE = %d, alloc = %d", counter, SIZE, alloc);


if (counter >= SIZE)
{

	printf("\n !!! counter has exceeded the size! doubling the size:");
	SIZE = 2*SIZE; // (1) double the size:
	list = realloc(list, SIZE* sizeof(struct person));
}


printf("\nenter the name");
scanf("%s", list[counter].name);


printf("\n enter age:");
scanf("%d", &list[counter].age); //scanf("%d", &*(list+counter));

printf("\n enter gpa:");
scanf("%f", &list[counter].gpa);

counter++;

}


void show()
{
	printf("\nshow():");
	for (int i= 0; i < counter; i++)
	{
		//printf("\n memory location (list+%d): %p",i, (list+i));
		//printf("\n value at location *(list+%d)=%d",i, *(list+i)); // seems to work
		printf("\nlist[%d]: name: %s, age: %d, GPA = %.2f.",i, list[i].name, list[i].age, list[i].gpa);
	}

}


void delete()
{

	char temp[7];

	printf("\n enter the name to delete:");
	scanf("%s", temp);
	printf("\n name to delete: %s", temp);


	int index=0;

	while(index <= counter)
	{
		if(!strcmp(list[index].name,temp))
		{
			counter--;
			break;
		}
		else if(index == counter && (strcmp(list[index].name,temp)))
			printf("\n no match found!");
		index++;

	}

	// now update the memory locations:

	for (int i = index; i<counter;i++)
	{
		list[i] = list[i+1];
	}

	if (counter <= SIZE/2 && SIZE > 3)
		// we'll do shrinking of the array as needed here
	{

		SIZE = SIZE/2; // (1) double the size:
		printf("\n (1) halve the size:");
		list = realloc(list, SIZE* sizeof(struct person));

	}

}
