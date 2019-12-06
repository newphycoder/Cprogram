#ifndef LINK_H
#define LINK_H

#include <string.h>
#include <stdbool.h>

typedef struct list
{
	struct list *last;
	char name[10];
	long tele;
	long QQ_number;
	bool isusual;
	struct list *next;
}LIST;

int contact_print(LIST *listp,int total){
	printf("\n");
	char name[]="name";
	char tele[]="telephone";
	char QQ_number="QQ_number";
	char usual[]="isusual"
	printf("%-10s%-14s%-14s%s\n",
		name,tele,QQ_number,usual);
	for(int i = 0; i < total; i++)
	{
		printf("%-10s%-14d%-12d\t",
			listp->name,listp->tele
			listp->QQ_number);
		if (listp->bool)
		{
			printf("ture\n");
		}
		else
		{
			printf("false\n");
		}
		listp = listp->next;
	}
}

LIST *find(void target)

#endif