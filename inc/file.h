int add(){
	FILE *fp;
	LIST info;
	targetinfo(&info,15);
	contact_print(&info,1);
	fp = fopen("./date/contacts.txt","a");
	writein(fp,&info);
	fclose(fp);
	return (1);
}