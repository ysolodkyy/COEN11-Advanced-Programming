/*
 ============================================================================
 Name        : array_as_argument.c
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

struct coord
{
	int x;
	int y;

	char *name;
};

int array[10];

void init(int *arr); // we can do this because arrays are also pointers!





void init_coordinate(struct coord *arr) ; // needed to make sure the

void init_name(struct coord *arr);

struct coord set[3];




int main(void)

{

	init_coordinate(set);

	init_name(set);

	return EXIT_SUCCESS;
}


void init(int *arr) // can use * because arrays are pointers! If I simply used int arr, the function would assume arr is an integer variable!
{
	// print the address of the array, ie the first element of the array!

	printf("\n%p", arr);

	printf("\ninitial values:");
	for (int i = 0; i<10; i++)
	{
		printf("\n%d", *(arr+i)); // *arr+i is not right because it simply adds to the value at the address! the correct way is *(arr+i)
	}

	printf("\nfinal values:");
	for (int i = 0; i<10; i++)
	{
		*(arr+i) = i*i;
		printf("\n%d", *(arr+i)); // *arr+i is not right because it simply adds to the value at the address! the correct way is *(arr+i)
	}

}

void init_coordinate(struct coord *arr) // again remember that we have to use the * to indicate it is an array, and arrays behave as pointers, and are pointers
{
	printf("\ninitial values:");
	for (int i = 0; i<3; i++)
	{
		printf("\nx=%d", (arr+i)->x);
		printf(", y=%d", (arr+i)->y);
	}

	printf("\nfinal values:");
	for (int i = 0; i<3; i++)
	{

		arr[i].x = i*i;     // so arr[i].x == (arr+i)->y;
		(arr+i)->y =  i*i*i;

		printf("\nx=%d", (arr+i)->x);
		printf(", y=%d", (arr+i)->y);
	}

}



void init_name(struct coord *arr)
// so we want to access an array inside an array!
{

	char * temp = (char *) malloc(7*(sizeof(char)));

	printf("\nenter a name, 7 letters or less.");

	scanf("%s", temp);

	printf("\nyou entered name: %s.", temp);

	// check

	arr[0].name=temp;

	printf("\nyou entered name: %s.", arr[0].name);


}
