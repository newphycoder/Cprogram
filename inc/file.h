#ifndef FILE_H
#define FILE_H

int add(){
	int i = 1;
	int find_result = -1;
	FILE *fp;
	LIST info;
	LIST *head;
	targetinfo(&info,15);
	fprint_title(stdout);
	writein(stdout,&info,3);
	fp = fopen(".//data//contacts.txt","a");
	if ( fp  == 0 )
	{
		openfail();
		return (-1);
	}
	while ( i != 8 )
	{
		find_result = find(fp,&info,&head,i);
		i *= 2;
	}
	if ( find(fp,&info,&head,15) != -1 )
	{
		printf("already have the \n");
	}
	else
	{
		writein(fp,&info,2);
	}
	if( fclose(fp) )
	{
		closefail();
		return (-1);
	}
	return (1);
}

int search(){
	FILE *fp;
	LIST *head=NULL,info;
	int mode;
	int find_result;

	mode = modechoose(2);
	targetinfo(&info,mode);

	// find & print
	fp = fopen(".//data//contacts.txt","r");
	if ( fp  == 0 )
	{
		openfail();
		return (-1);
	}
	find_result = find(fp,&info,&head,mode);
	if ( find_result != -1 )
	{
		fprint_title(stdout);
		writein(stdout,head,3);
		freememory(head);
	}
	else
	{
		printf("can't find the target\n");
	}
	if( fclose(fp) )
	{
		closefail();
		return(-1);
	}
	return (2);
}

int modify(){
	int mode,find_result;
	LIST *head,info,*p;
	FILE *fp;

	printf("\n");
	printf("search mode:\n");
	mode = modechoose(1);
	targetinfo(&info,mode);

	fp = fopen(".//data//contacts.txt","r+");
	if ( fp  == 0 )
	{
		openfail();
		return (-1);
	}
	find_result = find(fp,&info,&head,mode);
	if ( find_result != -1 )
	{
		fprint_title(stdout);
		writein(stdout,head,3);
		p = head;
		do
		{
			printf("changing the information by the list\n");
			printf("\n");
			printf("change mode\n");
			mode = modechoose(2);
			targetinfo(p,mode);
			p = p->next;
		}
		while(p);
		writein(fp,head,0);
		freememory(head);
	}
	else
	{
		printf("can't find the target\n");
	}
	if( fclose(fp) )
	{
		closefail();
		return(-1);
	}
	return (3);
}

int delect(){
	int mode,find_result;
	LIST *head,info,*p;
	FILE *fp;

	// get information that don't delect
	printf("\n");
	printf("search mode:\n");
	mode = modechoose(1);
	targetinfo(&info,mode);

	fp = fopen(".//data//contacts.txt","r+");
	if ( fp  == 0 )
	{
		openfail();
		return (-1);
	}
	find_result = nfind(fp,&info,&head,mode);
	if ( find_result != 0 )
	{
		printf("can't find the target\n");
		return (4);
	}
	if( fclose(fp) )
	{
		closefail();
		return(-1);
	}

	// write in the file 
	fp = fopen(".//data//contacts.txt","w");
	if ( fp  == 0 )
	{
		openfail();
		return (-1);
	}
	writein(fp,head,1);
	freememory(head);
	if( fclose(fp) )
	{
		closefail();
		return(-1);
	}

	return (4);
}

int browse(){
	LIST *p=NULL,*head=NULL;
	FILE *fp;
	fp = fopen(".//data//contacts.txt","r");
	if ( fp  == 0 )
	{
		openfail();
		return (-1);
	}
	while( !feof(fp) )
	{
		p = (LIST*) malloc( sizeof(LIST) );
		if(get(fp,p) != -1)
		{
			p->next = head;
			if ( head != NULL)
			{
				head->last = p;
			}
			head = p;
		}
		else
		{
			free(p);
		}
	}
	if( fclose(fp) )
	{
		closefail();
		return(-1);
	}

	writein(stdout,head,3);
	freememory(head);
	return(6);
}

int load(){
	LIST info,*head = NULL;
	info.isusual = 1;
	FILE *fp;
	char filename[30];

	fp = fopen(".//data//contacts.txt","r");
	if ( fp  == 0 )
	{
		openfail();
		return (-1);
	}
	if ( find(fp,&info,&head,8) == -1 )
	{
		printf("no usual contact\n");
	}
	if( fclose(fp) )
	{
		closefail();
		return(-1);
	}

	printf("\n");
	sort(&head);

	printf("which file you want to save:\n");
	scanf("%s",filename);

	fp = fopen(filename,"w");
	if ( fp  == 0 )
	{
		openfail();
		return (-1);
	}
	fprint_title(stdout);
	writein(stdout,head,3);
	fprint_title(fp);
	writein(fp,head,1);
	if( fclose(fp) )
	{
		closefail();
		return(-1);
	}

	freememory(head);
	return (7);
}

#endif