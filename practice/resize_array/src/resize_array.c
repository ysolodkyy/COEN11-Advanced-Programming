/*
 ============================================================================
Allocate an array dynamically and then resize it!
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

# define N 3

int SIZE = N; // I will try to maybe change the size if there is a need to modify the size of the array

int *list; // remember: arrays are pointers! This is only a pointer -- NO Memory has been allocated yet!

int counter = 0;
int alloc = 0;


void insert(); // very crude function at first

void delete();

void delete1(int *arr);

void show(int *arr);

void insert1(int *arr);


int main(void)
{

		// allocate memory for the list
		list = (int *) malloc(SIZE*sizeof(int)); // it would make more sense to have this in the main() function !


		int selection;

	while(1)
	{
		printf("\n\nenter selections:\n(1) insert() the list; \n(2) delete() from the list; \n(3) show the list; \n(4) exit.  ");
		scanf("%d", &selection);

		switch (selection)
		{
		case 1:
			insert1(list); //insert(); //addName(list);
			break;
		case 2:
			delete1(list); //delete();
			break;

		case 3:
			show(list);
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
	list = (int *) malloc(SIZE*sizeof(int)); // it would make more sense to have this in the main() function !
	alloc = 1; // update alloc so we don't allocate new memory each time we call the function
}

printf("\n counter= %d, SIZE = %d, alloc = %d", counter, SIZE, alloc);


if (counter >= SIZE)
{

	printf("\n !!! counter has exceeded the size! doubling the size:");
	SIZE = 2*SIZE; // (1) double the size:
	list = realloc(list, SIZE* sizeof(int));
}

printf("\n enter a integer:");
scanf("%d", &list[counter]); //scanf("%d", &*(list+counter));
counter++;

// verify for now
printf("\n entered integer:%d", list[counter-1]);
}


void show(int *arr)
{
	printf("\nshow():");
	for (int i= 0; i < counter; i++)
	{
		//printf("\n memory location (list+%d): %p",i, (list+i));
		//printf("\n value at location *(list+%d)=%d",i, *(list+i)); // seems to work
		printf("\n value at location list[%d]=%d",i, arr[i]);
	}

}

void insert1(int *arr)
{	printf("\ninsert1():");

printf("\n counter= %d, SIZE = %d, alloc = %d", counter, SIZE, alloc);


if (counter >= SIZE)
{

	printf("\n !!! counter has exceeded the size! doubling the size:");
	SIZE = 2*SIZE; // (1) double the size:
	arr = realloc(arr, SIZE* sizeof(int));
}

printf("\n enter a integer:");
scanf("%d", &(arr[counter])); //scanf("%d", &*(list+counter));
counter++;

// verify for now
printf("\n entered integer:%d", arr[counter-1]);
}




void delete()
				{

	int digit, index=0;
	printf("\n enter the digit to delete:");
	scanf("%d", &digit);

	while(index <= counter)
	{
		if(list[index]==digit)
		{
			counter--;
			break;
		}
		else if(index == counter && list[index] !=digit)
			printf("\n no match found!");
		index++;

	}

	// now update the memory locations:

	for (int i = index; i<counter;i++)
	{
		list[i] = list[i+1];
	}

	if (counter <= SIZE/2)
		// we'll do shrinking of the array as needed here
	{

		SIZE = SIZE/2; // (1) double the size:
		printf("\n (1) half the size:");
		list = realloc(list, SIZE* sizeof(int));

	}

				}



void delete1(int *arr)
{

	int digit, index=0;
	printf("\n enter the digit to delete:");
	scanf("%d", &digit);

	while(index <= counter)
	{
		if(arr[index]==digit)
		{
			counter--;
			break;
		}
		else if(index == counter && arr[index] !=digit)
			printf("\n no match found!");
		index++;

	}

	// now update the memory locations:

	for (int i = index; i<counter;i++)
	{
		arr[i] = arr[i+1];
	}

	if (counter <= SIZE/2)
		// we'll do shrinking of the array as needed here
	{

		SIZE = SIZE/2; // (1) double the size:
		printf("\n (1) half the size:");
		arr = realloc(list, SIZE* sizeof(int));

	}

}

