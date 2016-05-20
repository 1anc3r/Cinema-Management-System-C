//============================================================================
// Name        : usermodify.h
// Author      : lancer
// Version     : 2.1
// Copyright   : made by lancer
// Description : Cinema Management System in C, Ansi-style
//============================================================================

void UserModify(user *p);

void UserModify(user *p)
{
	int i;
	int len;
	int choose;
	user *q;
	q=UserQuery(p);
	if(q!=NULL)
	{
		line=4;
		system("cls");
		printf("┌─────────────────┐\n");
		printf("│           修改用户信息           │\n");
		printf("│─────────────────│\n");
		printf("│           [1]-----账号           │\n");
		printf("│                                  │\n");
		printf("│           [3]-----密码           │\n");
		printf("│                                  │\n");
		printf("│           [0]-----取消           │\n");
		printf("└─────────────────┘\n");
		choose=Cursor(4,8,12,26,8,2);
		system("cls");
		switch(choose)
		{
			case 4 :
			Position(1,1);
			printf("┌─────────────────┐\n");
			printf("│  新账号:                         │\n");
			printf("└─────────────────┘\n");
			Position(12,2);
			scanf("%s",&q->id);
			break;
			case 6 :
			Position(1,1);
			printf("┌─────────────────┐\n");
			printf("│  新密码:                         │\n");
			printf("└─────────────────┘\n");
			Position(12,2);
			scanf("%s",&q->password);
			break;
			case 8 :
			goto flag;
			break;
		}
		Position(1,4);
		printf("┌─────────────────┐\n");
		printf("│             用户信息             │\n");
		printf("│─────────────────│\n");
		printf("│%d %s %s",q->power,q->id,q->password);
		for(i=0;i<31-strlen(q->id)-strlen(q->password);i++)
		{
			printf(" ");
		}
		printf("│\n│─────────────────│\n");
		printf("│                                  │\n");
		printf("└─────────────────┘\n");
		getch();
		system("cls");
	}
	else
	{
		system("cls");
		printf("┌─────────────────┐\n");
        printf("│  [!]提示:无用户数据,请输入数据!  │\n");
        printf("└─────────────────┘\n");
		getch();
		system("cls");
	}
	flag:
	system("cls");
	printf("┌─────────────────┐\n");
	printf("│       [!]提示:修改完毕!          │\n");
	printf("│       任意键返回主菜单...        │\n");
	printf("└─────────────────┘\n");
	getch();
	system("cls");
}
