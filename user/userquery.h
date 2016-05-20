//============================================================================
// Name        : userquery.h
// Author      : lancer
// Version     : 2.1
// Copyright   : made by lancer
// Description : Cinema Management System in C, Ansi-style
//============================================================================

user *UserQuery(user *p);

user *UserQuery(user *p)
{
	int i;
	int choose;
	char tempid[15],tempasswd[15];
	if(m!=0)
	{
		line=5;
		system("cls");
		printf("┌─────────────────┐\n");
		printf("│           查询用户信息           │\n");
		printf("│─────────────────│\n");
		printf("│                                  │\n");
		printf("│           [1]-----账号           │\n");
		printf("│                                  │\n");
		printf("│           [0]-----取消           │\n");
		printf("│                                  │\n");
		printf("└─────────────────┘\n");
		choose=Cursor(5,7,12,26,7,2);
        system("cls");
        switch(choose)
		{
			case 5 :
			printf("┌─────────────────┐\n");
			printf("│  账号:                           │\n");
			printf("└─────────────────┘\n");
			Position(10,2);
			scanf("%s",&tempid);
			while(p->next!=NULL&&(strcmp(tempid,p->id)!=0))
			{
				p=p->next;
			}
			if(strcmp(tempid,p->id)==0)
			{
				Position(1,4);
				printf("┌─────────────────┐\n");
				printf("│             用户信息             │\n");
				printf("│─────────────────│\n");
				printf("│%d %s %s",p->power,p->id,p->password);
				for(i=0;i<31-strlen(p->id)-strlen(p->password);i++)
				{
					printf(" ");
				}
				printf("│\n│─────────────────│\n");
				printf("│                                  │\n");
				printf("└─────────────────┘\n");
				getch();
				system("cls");
				return p;
			}
			else
			{
				Position(1,4);
				printf("┌─────────────────┐\n");
				printf("│ [!]提示:无该用户记录,请输入数据! │\n");
				printf("└─────────────────┘\n");
				getch();
				system("cls");
				return NULL;
			}
			break;
			case 6 :
			goto flag;
			break;
		}
	}
	else
	{
		system("cls");
		printf("┌─────────────────┐\n");
		printf("│  [!]提示:无用户数据,请输入数据!  │\n");
		printf("└─────────────────┘\n");
		getch();
		system("cls");
		return NULL;
	}
	flag:
	system("cls");
	printf("┌─────────────────┐\n");
	printf("│       [!]提示:查询完毕!          │\n");
	printf("│       任意键返回主菜单...        │\n");
	printf("└─────────────────┘\n");
	getch();
	system("cls");
	return NULL;
}
