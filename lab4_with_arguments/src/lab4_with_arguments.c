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

union stats
{
	int years_retired;
	float salary;
	char school[9];
};

struct person

{
	int age;
	union stats status;
	char name[7];
};


struct person *list; // remember: arrays are pointers! This is only a pointer -- NO Memory has been allocated yet!

struct person *list2; // for testing purposes


int counter = 0;


void insert(struct person *); // very crude function at first
void delete(struct person *);
void show(struct person *);

int main(void)
{
	list = (struct person *) malloc(SIZE*sizeof(struct person)); // it would make more sense to have this in the main() function !

	list2 = (struct person *) malloc(SIZE*sizeof(struct person)); // it would make more sense to have this in the main() function !

	int selection;


	while(1)
	{


		printf("\n\nenter selections:\n(1) insert() the list; \n(2) delete() from the list; \n(3) show the list; \n(4) exit.  ");
		scanf("%d", &selection);

		switch (selection)
		{
		case 1:
			insert(list2);
			break;
		case 2:
			delete(list2);
			break;

		case 3:
			show(list2);
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
	free(list2); // free the memory allocated to the list

	return EXIT_SUCCESS;

}


void insert(struct person *arr)

{	printf("\ninsert():");


printf("\n counter= %d, SIZE = %d", counter, SIZE);


if (counter >= SIZE)
{

	printf("\n !!! counter has exceeded the size! doubling the size:");
	SIZE = 2*SIZE; // (1) double the size:
	arr = realloc(arr, SIZE* sizeof(struct person));
}


printf("\nenter the name");
scanf("%s", arr[counter].name);


printf("\n enter age:");
scanf("%d", &arr[counter].age); //scanf("%d", &*(list+counter));

if (arr[counter].age <= 21)
{
	printf("\n enter school:");
	scanf("%s", arr[counter].status.school);
}

else if (arr[counter].age > 21 && arr[counter].age <=65 )
{
	printf("\n enter salary:");
	scanf("%f", &arr[counter].status.salary);
}

else
{
	printf("\n enter years_retired:");
	scanf("%d", &arr[counter].status.years_retired);
}


counter++;

}


void show(struct person *arr)
{
	printf("\nshow():");
	for (int i= 0; i < counter; i++)
	{
		//printf("\n memory location (list+%d): %p",i, (list+i));
		//printf("\n value at location *(list+%d)=%d",i, *(list+i)); // seems to work


		if (arr[i].age <= 21)
		{
			printf("\nlist[%d]: name: %s, age: %d, school = %s.",i, arr[i].name, arr[i].age, arr[i].status.school);
		}

		else if (arr[i].age > 21 && arr[i].age <=65 )
		{
			printf("\nlist[%d]: name: %s, age: %d, salary = %.2f.",i, arr[i].name, arr[i].age, arr[i].status.salary);
		}

		else
		{
			printf("\nlist[%d]: name: %s, age: %d, years in retirement = %d.",i, arr[i].name, arr[i].age, arr[i].status.years_retired);
		}

	}

}


void delete(struct person *arr)
{

	char * temp = (char *) malloc(7*sizeof(char)); //char temp[7];
	printf("\n enter the name to delete:");
	scanf("%s", temp);
	printf("\n name to delete: %s", temp);


	int index=0;

	while(index <= counter)
	{
		if(!strcmp(arr[index].name,temp)) // see strcmp() documentation!!
		{
			counter--;
			break;
		}


		else if(index == counter && (strcmp(arr[index].name,temp)))
			printf("\n no match found!");
		index++;

	}

	// now update the memory locations:

	for (int i = index; i<counter;i++)
	{
		arr[i] = arr[i+1];
	}

	if (counter <= SIZE/2 && SIZE > 3)
		// we'll do shrinking of the array as needed here
	{

		SIZE = SIZE/2; // (1) double the size:
		printf("\n (1) halve the size:");
		arr = realloc(arr, SIZE* sizeof(struct person));

	}

	free(temp);
}
