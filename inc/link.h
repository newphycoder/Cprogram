#ifndef LINK_H
#define LINK_H

#include <string.h>
#include <stdlib.h>

// get info from file
int ftargetinfo(FILE *fp,LIST *store,long address){
	int t = 0;
	int usual;
	char c;
	fseek(fp,address,0);
	do
	{
		store->name[t] = (char)fgetc(fp);
		if ( store->name[t] == EOF )
		{
			return (-1);
		}
		t++;
	}
	while(store->name[t-1]!='|');
	store->name[t] = 0;
	fscanf(fp,"%ld",&store->tele);
	fscanf(fp,"%ld",&store->QQ_number);
	fscanf(fp,"%d",&usual);
	store->isusual = (_Bool)usual;
	fgetc(fp);
	return (0);
}

// print the list
int writein(FILE *fp,LIST *listp,int mode){
	while (listp != NULL)
	{
		switch (mode)
		{
			case 0 :fseek(fp,listp->address,0);
					break;
			case 1 :fseek(fp,0,1);
					break;
			case 2 :fseek(fp,0,2);
			default:break;
		}
		fprintf(fp,"%-18s%-14ld%-12ld\t",
				listp->name,listp->tele,
				listp->QQ_number);
		fflush(fp);
		if (listp->isusual)
		{
			fprintf(fp,"1\n");
		}
		else
		{
			fprintf(fp,"0\n");
		}
		listp = listp->next;
	}
	return (0);
}

// print a title
int fprint_title(FILE *fp){
	printf("\n");
	char name[]="name";
	char tele[]="telephone";
	char QQ_number[]="QQ_number";
	char usual[]="isusual";
	fprintf(fp,"%-18s%-14s%-12s%s\n",
		name,tele,QQ_number,usual);
	return(0);
}


long get(FILE *fp,LIST *store){
	long address;
	address = ftell(fp);
	if ( ftargetinfo(fp,store,address) == -1 )
	{
		return (-1);
	}
	return (address);
}

int find(FILE *fp,LIST *target,LIST **head,int mode){
	LIST store,*p;
	int t,c,i,mode_swp;
	long address;
	while( !feof(fp) )
	{
		t = 1;
		address = get(fp,&store);
		if ( address == EOF )
		{
			break;
		}
		mode_swp = mode;
		i = 0;
		while ( mode_swp != 0 )
		{
			c = mode_swp % 2;
			mode_swp /= 2;
			i++;
			if (c)
			{
				switch (i)
				{
					case 1 :if (strcmp(target->name,store.name))
								t=0;
							break;
					case 2 :if ( target->tele != store.tele )
								t=0;
							break;
					case 3 :if ( target->QQ_number != store.QQ_number )
								t=0;
							break;
					case 4 :if ( target->isusual != store.isusual)
								t=0;
				}
			}
			if ( t == 0 )
				break;
		}
		if (t)
		{
			p = *head;
			*head = (LIST*)malloc(sizeof (LIST));
			**head = store;
			(*head)->address = address;
			(*head)->last = NULL;
			(*head)->next = p;
			if (p)
			{
				p->last = *head;
			}
		}
	}
	if ( t )
	{
		return (0);
	}
	else
	{
		return (-1);
	}
}


int nfind(FILE *fp,LIST *target,LIST **head,int mode){
	LIST store,*p;
	int t,c,i;
	long address;
	while( !feof(fp) )
	{
		t = 1;
		address = get(fp,&store);
		if ( address == EOF )
		{
			break;
		}
		while ( mode != 0 )
		{
			c = mode % 2;
			mode /= 2;
			i++;
			if (c)
			{
				switch (i)
				{
					case 1 :if (strcmp(target->name,store.name))
								t=0;
							break;
					case 2 :if ( target->tele != store.tele )
								t=0;
							break;
					case 3 :if ( target->QQ_number != store.QQ_number )
								t=0;
							break;
					case 4 :if ( target->isusual != store.isusual)
								t=0;
				}
			}
			if ( t == 0 )
				break;
		}
		if ( t == 0 )
		{
			p = *head;
			*head = (LIST*)malloc(sizeof (LIST));
			**head = store;
			(*head)->address = address;
			(*head)->last = NULL;
			(*head)->next = p;
			if (p)
			{
				p->last = *head;
			}
		}
	}
	if ( t )
	{
		return (0);
	}
	else
	{
		return (-1);
	}
}

int freememory(LIST *listp){
	LIST *p;
	while (listp){
		p = listp->next;
		free(listp);
		listp = p;
	}
	return (0);
}

int sort(LIST **head){
	LIST *p = NULL;
	LIST *q = NULL;
	int t = 1;
	while( t )
	{
		t = 0;
		if ((*head)->next)
		{
			if (strcmp((*head)->name,(*head)->next->name) > 0)
			{
				(*head)->last = (*head)->next;
				(*head) = (*head)->next;
				q = (*head)->next;
				(*head)->next = (*head)->last;
				(*head)->last = NULL;
				(*head)->next->next = q;
				if ( q->next )
				{
					q->last = (*head)->next;
				}
			}

			p = (*head)->next;
	
			while (p->next)
			{
				if ( strcmp(p->name,p->next->name) > 0 )
				{
					q = p->next;
					if ( p->last )
					{
						p->last->next = q;
					}
					if ( q->next )
					{
						q->next->last = p;
					}
					q->last = p->last;
					p->next = q->next;
					p->last = q;
					q->next = p;
					t = 1;
				}
				else
				{
					p = p->next;
				}
				writein(stdout,*head,3);
			}
		}
		printf("%d\n",t);
	}
	return (0);
}


#endif