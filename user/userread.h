//============================================================================
// Name        : userread.h
// Author      : lancer
// Version     : 2.1
// Copyright   : made by lancer
// Description : Cinema Management System in C, Ansi-style
//============================================================================

user *UserRead();

user *UserRead()
{
	FILE *fp;
	user *phead,*pend,*pnew;
	if((fp=fopen("data/infouser.txt","rb+"))==NULL)
	{
		system("cls");
		printf("┌─────────────────┐\n");
		printf("│       [!]提示:文件打开失败!      │\n");
		printf("└─────────────────┘\n");
		getch();
		exit(0);
	}
	pnew=0;
	m=0;
	phead=(user*)malloc(sizeof(user));
	phead->next=NULL;
	pend=phead;
	while(!feof(fp))
	{
		pnew=(user*)malloc(sizeof(user));
		fscanf(fp,"%d %s %s\n",&pnew->power,pnew->id,pnew->password);
		pend->next=pnew;
		pend=pnew;
		m++;
	}
	pend->next=NULL;
	fclose(fp);
	return phead;
}
