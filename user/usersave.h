//============================================================================
// Name        : usersave.h
// Author      : lancer
// Version     : 2.1
// Copyright   : made by lancer
// Description : Cinema Management System in C, Ansi-style
//============================================================================

int UserSave(user *p);

int UserSave(user *p)
{
	char ch;
	int line;
	int choose;
	char mod[4];
	FILE *fp;
	user *user=NULL;
	system("cls");
	printf("┌─────────────────┐\n");
	printf("│           保存用户信息           │\n");
	printf("│─────────────────│\n");
	printf("│                                  │\n");
	printf("│           [1]-----追加           │\n");
	printf("│           [2]-----覆盖           │\n");
	printf("│           [0]-----取消           │\n");
	printf("│                                  │\n");
	printf("└─────────────────┘\n");
	choose=Cursor(5,7,12,26,7,1);
	switch(choose)
	{
		case 5 :
		strcpy(mod,"at+");
		break;
		case 6 :
		strcpy(mod,"rt+");
		break;
		case 7 :
		return -1;
	}
	if((fp=fopen("data/infouser.txt",mod))==NULL)
	{
		system("cls");
		printf("┌─────────────────┐\n");
		printf("│       [!]提示:文件打开失败!      │\n");
		printf("└─────────────────┘\n");
		getch();
		exit(0);
	}
	for(user=p->next;user!=NULL;user=user->next)
	{
		fprintf(fp,"%d %s %s\n",user->power,user->id,user->password);
	}
	fclose(fp);
	return 0;
}
