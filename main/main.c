#include "user.h"
#include "link.h"
#include "file.h"


int organize(int order);

int main(int argc, char const *argv[])
{
	int choice;
	do
	{
		choice = option();
		switch (choice)
		{
			case  0:break;
			case -2:break;
			default:choice = organize(choice);
		}
		if (choice == -1 )
		{
			printf("application error\n");
		}
	}
	while ( choice!=(0) );

	return (0);
}

int organize(int order){
	switch (order)
	{
		case 1 : 
			order = add();
			break;
		case 2 : 
			order = search();
			break;
		case 3 :
			order = modify();
			break;
		case 4 :
			order = delect();
			break;
		case 5 :
			order = browse();
			break;
		case 6 :
			order = load();
			break;
		default:
			order = -1;
	}
	return (order);
}