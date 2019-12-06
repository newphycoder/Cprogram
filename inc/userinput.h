#ifndef USER_H
#define USER_H

#include <stdio.h>

void print(int num,char (*option)[30]){
	int i = 0;
	printf("\n");
	printf("which operate do you want\n");
	for(i = 0; i<num; i++)
	{
		printf("%s\n",*option);
		option++;
	}
}

int option(){
	int len;
	int choice;

	//print the information
	char info[][30]=
		{
			"1.terminate",
			"2.add a new contact",
			"3.search a contact",
			"4.modify a contact",
			"5.remove a contact",
			"6.show all contacts",
			"7.load frequent contacts"
		};
	len = sizeof(info)/sizeof(*info);
	print(len,info);
	scanf("%d",&choice);


	if (choice > len || choice <1)
	{
		fprintf(stderr, "haven't this choice\n");
		return (EOF);
	}
	else
	{
	return (choice);
	}
}

#endif