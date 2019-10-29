/*
 ============================================================================
access the elements of the thing
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>


union Status
{
	int years_retured;
	float salary;
	char *school;
};

struct Human
{
	char * name;
	int age;
	union Status status;
};

int SIZE = 3; // initial size of the array
int counter = 0;

struct Human *list; // so now I want to create an array of arbitrary length


int main(void)
{
	list = (struct Human *) malloc(SIZE*sizeof(struct Human *));

	// so I want to be able to access


	for (int i= 0; i < SIZE; i++)
	{
		list[i].age = i;
		list[i].name = "frank";
		list[i].status.school = "Hollywood";
	}

	for (int i= 0; i < SIZE; i++)
	{
		printf("\n  age *(list+%d)=%d",i, list[i].age);
		printf("\n name list[%d]=%s",i, list[i].name);
		printf("\n status list[%d]=%s",i, list[i].status);
	}


	list[1].name = "Taylor";
	list[1].status.school = "Brooklyn";


	if (list[0].name == list[2].name)
		printf("\n we have a match");
	else
		printf("\n error");


	free(list); // always must free the memory
	return EXIT_SUCCESS;
}
