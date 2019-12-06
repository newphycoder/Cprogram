#include "inc/user.h"
#include "inc/link.h"

int organize();

int main(int argc, char const *argv[])
{
	int choice;
	do
	{
		choice = option();
		switch (choice)
		{
			case  0:return (0);
			case -1:return (-1);
			default:;
		}
		organize
	}
	while (choice);

	return (0);
}

int organize(){
	int choice;
	choice = option();
	switch (choice)
	{
		case  0:return (-1);
		case -1:return (0);
		default:;
	}
	run
}