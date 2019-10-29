/*
 ============================================================================
we want to create a people list that has

https://stackoverflow.com/questions/10811439/malloc-an-array-of-struct-pointers
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>


union Status
{
	int years_retired;
	float salary;
	//char *school;
};

struct Human
{
	//char * name;
	int age;
	//union Status status;
};


int SIZE = 3; // initial size of the array
int counter = 0;

struct Human *list; // so now I want to create an array of arbitrary length

void insert();
//void delete();
void show();

int main(void)
{


	list = malloc(SIZE*sizeof(struct Human)); // it would make more sense to have this in the main() function !

	int selection;

	while(1)
	{
		printf("\n\nenter selections:\n(1) insert() the list; \n(2) delete() from the list; \n(3) show the list; \n(4) exit.  ");
		scanf("%d", &selection);

		switch (selection)
		{
		case 1:
			insert(); //insert(); //addName(list);
			break;
		case 2:
			//delete1(); //delete();
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



if (counter >= SIZE)
{

	printf("\n !!! counter has exceeded the size! counter = %d", counter);
	//SIZE = 2*SIZE; // (1) double the size:
	//list = realloc(list, SIZE* sizeof(int));
}

else
{

	//char *name;
	//name = (char *) malloc(11*sizeof(char)); // reassign a new memory location to the temp poiter each time the loop runs


	//printf("\n enter the name:");
	//scanf("%s", name); //scanf("%d", &*(list+counter));
	//list[counter].name = name;

	int number;
	printf("\n enter the age:");
	scanf("%d", &number); //scanf("%d", &*(list+counter));
	list[counter]->age = number;

	if (list[counter].age <= 21)
	{
		//char *school;
		printf("\n too young");
		//school = (char *) malloc(11*sizeof(char)); // reassign a new memory location to the temp poiter each time the loop runs
		//printf("\n enter the school:");
		//scanf("%s", school); //scanf("%d", &*(list+counter));
		//list[counter].status.school = school;
	}

	else if (21 < list[counter].age && list[counter].age <= 65)
	{
		float salary;
		printf("\n enter the salary amount:");
		scanf("%f", &salary); //scanf("%d", &*(list+counter));
		list[counter]->status->salary = salary;
	}


	else //if (list[counter].age > 65)
	{
		int years;
		printf("\n enter years in retirement:");
		//scanf("%d", &years); //scanf("%d", &*(list+counter));
		//list[counter].status.years_retired = years;
	}


	counter++;

	// verify for now
	//printf("\n entered integer:%d", list[counter-1]);
}
}


//void delete()
//				{
//
//	int digit, index=0;
//	printf("\n enter the digit to delete:");
//	scanf("%d", &digit);
//
//	while(index <= counter)
//	{
//		if(list[index]==digit)
//		{
//			counter--;
//			break;
//		}
//		else if(index == counter && list[index] !=digit)
//			printf("\n no match found!");
//		index++;
//
//	}
//
//	// now update the memory locations:
//
//	for (int i = index; i<counter;i++)
//	{
//		list[i] = list[i+1];
//	}
//
//	//	if (counter <= SIZE/2) -- resising doesn't work for now
//	//		// we'll do shrinking of the array as needed here
//	//	{
//	//
//	//		SIZE = SIZE/2; // (1) double the size:
//	//		printf("\n (1) half the size:");
//	//		list = realloc(list, SIZE* sizeof(int));
//	//
//	//	}
//
//				}

void show()
{
	printf("\nshow():");
	for (int i= 0; i < counter; i++)
	{
		printf("\n i= %d", i);

		//printf("\n name: %s", list[counter].name); //scanf("%d", &*(list+counter));


		printf("\n age: %d", list[counter].age); //scanf("%d", &*(list+counter));

		if (list[counter].age <= 21)
		{
			//printf("\n Status: %s", list[counter].status); //scanf("%d", &*(list+counter));
			printf("\n some name");
		}

		else if (21 < list[counter].age && list[counter].age <= 65)
		{
			printf("\n something"); //printf("\n Status: %f", list[counter].status); //scanf("%d", &*(list+counter));
		}


		else //if (list[counter].age > 65)
		{
		printf("\n something");//	printf("\n Status: %d", list[counter].status); //scanf("%d", &*(list+counter));
		}




		//printf("\n memory location (list+%d): %p",i, (list+i));
		//printf("\n value at location *(list+%d)=%d",i, *(list+i)); // seems to work
		//printf("\n value at location list[%d]=%d",i, list[i]);
	}

}
