#ifndef LINK_H
#define LINK_H

#include <string.h>


// print a certain
int contact_print(LIST *listp,int total){
	printf("\n");
	char name[]="name";
	char tele[]="telephone";
	char QQ_number[]="QQ_number";
	char usual[]="isusual";
	printf("%-18s%-14s%-12s%s\n",
		name,tele,QQ_number,usual);
	for(int i = 0; i < total; i++)
	{
		printf("%-18s%-14ld%-12ld\t",
			listp->name,listp->tele,
			listp->QQ_number);
		if (listp->isusual)
		{
			printf("ture\n");
		}
		else
		{
			printf("false\n");
		}
		listp = listp->next;
	}
	return (0);
}
/*
LIST *find(LIST *target,int mode){

}
*/
int writein(FILE *fp,LIST *listp){
	fprintf(fp,"%s%-14ld%-12ld\t",
			listp->name,listp->tele,
			listp->QQ_number);
	fflush(fp);
	printf("??\n");
		if (listp->isusual)
		{
			fprintf(fp,"1\n");
		}
		else
		{
			fprintf(fp,"0\n");
		}
	printf("??\n");
	return (0);
}

#endif