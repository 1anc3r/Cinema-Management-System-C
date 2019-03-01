//============================================================================
// Name        : userbrowse.h
// Author      : lancer
// Version     : 2.1
// Copyright   : made by lancer
// Description : Cinema Management System in C, Ansi-style
//============================================================================

void UserBrowse(user *p);

void UserBrowse(user *p)
{
	int i,line=4;
	if(m!=0)
	{
		system("cls");
		printf("┌────────────────────────────────┐\n");
		printf("│          浏览用户信息          │\n");
		printf("│────────────────────────────────│\n");
		while(p!=NULL)
		{
			Position(1,line);
			printf("│%d %s %s",p->power,p->id,p->password);
			for(i=0;i<29-strlen(p->id)-strlen(p->password);i++)
			{
				printf(" ");
			}
			printf("│\n");
			printf("│────────────────────────────────│\n");
			p=p->next;
			line+=2;
		}
		printf("│                                │\n");
		printf("└────────────────────────────────┘\n");
	}
	else
	{
		printf("\n┌────────────────────────────────┐\n");
		printf("│[!]提示:无该用户记录,请输入数据!│\n");
		printf("└────────────────────────────────┘\n");
	}
	getch();
	system("cls");
}
