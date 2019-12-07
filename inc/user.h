#ifndef USER_H
#define USER_H

#include <stdio.h>

typedef struct list
{
	struct list *last;
	char name[15];
	long tele;
	long QQ_number;
	_Bool isusual;
	struct list *next;
}LIST;

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

void outrange(){
	fprintf(stderr, "haven't this choice\n");
}

void openfail(){
	fprintf(stderr, "can't open\n");
}

void closefail(){
	fprintf(stderr, "can't close\n");
}

// choose the mode
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
		outrange();
		return (-2);
	}
	else
	{
		return (choice-1);
	}
}


// input the information and the mode
int targetinfo(LIST *store,int mode){
	int i = 0;
	int t = 0;
	printf("\n");
	if ( mode > 15 )
	{
		printf("mode out of range\n");
	}
	while( mode != 0 )
	{
		t = mode % 2;
		mode /= 2;
		i++;
		int usual;
		if (t == 1)
		{
			switch (i)
			{
				case 1 :
					do
					{
						printf("Is it frequent contact:\n");
						printf("0.false\n");
						printf("1.ture\n");
						scanf("%d",&usual);
						if ( usual != 0 && usual != 1)
						{
							outrange();
						}
						else
						{
							break;
						}
					}
					while(1);
					store->isusual = (_Bool)usual;
					break;
				case 2 :
					printf("the QQ of the contact\n");
					scanf("%ld",&store->QQ_number);
					break;
				case 3 :
					printf("the telephone of the contact\n");
					scanf("%ld",&store->tele);
					break;
				case 4 :
					printf("the name of the contact\n");
					fflush(stdin);
					fgets(store->name,10,stdin);
					while (store->name[t-1] != '\n')
					{
						t++;
					}
					store->name[t-1] = 0;
					break;
				default:
					return (-1);
			}
		}
	}
	return (0);
}

#endif