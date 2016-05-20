//============================================================================
// Name        : orderquery.h
// Author      : lancer
// Version     : 2.1
// Copyright   : made by lancer
// Description : Cinema Management System in C, Ansi-style
//============================================================================

order* OrderQuery(order *p);

order* OrderQuery(order *p)
{
	int k,i;
	int len;
	int num;
	int line;
	int choose;
	char tempnum[8];
	char strnum[8];
	order *q;
	q=p->next;
	if(o!=0)
	{
		line=5;
		system("cls");
		printf("┌─────────────────┐\n");
		printf("│           查询订单信息           │\n");
		printf("│─────────────────│\n");
		printf("│                                  │\n");
		printf("│           [1]-----订单号         │\n");
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
			printf("│  订单号:                         │\n");
			printf("└─────────────────┘\n");
			Position(12,2);
			scanf("%s",tempnum);
			num=strlen(tempnum);
			while(q!=NULL&&itoa(q->ordernum,strnum,10)&&memcmp(tempnum,strnum,num))
			{
				p=p->next;
				q=p->next;
			}
			if(!memcmp(tempnum,strnum,num))
			{
				Position(1,4);
				printf("┌─────────────────┐\n");
				printf("│             订单信息             │\n");
				printf("│─────────────────│\n");
				printf("│─────────────────│\n");
				printf("│  订单：                 %7d  │\n",q->ordernum);
				printf("│─────────────────│\n");
				printf("│  片名:");
				len=strlen(q->filmname);
				for(i = 0;i < 25-len;i++)
				{
					printf(" ");
				}
				printf("%s  │\n",q->filmname);
				printf("│─────────────────│\n");
				printf("│  片长：                 %3.lf分钟  │\n",q->length);
				printf("│─────────────────│\n");
				printf("│  日期:           %4d年%2d月%2d日  │\n",q->year,q->month,q->day);
				printf("│─────────────────│\n");
				printf("│  场次:              %2d:%2d-%2d:%2d  │\n",q->openhour,q->openmin,q->closehour,q->closemin);
				printf("│─────────────────│\n");
				printf("│  院厅:                     %2d厅  │\n",q->hallnum);
				printf("│─────────────────│\n");
				printf("│  座位:                 %2d排%2d座  │\n",q->shit[0],q->shit[1]);
				printf("│─────────────────│\n");
				printf("│  小计:                 %6.2lf元  │\n",q->fare);
				printf("│─────────────────│\n");
				printf("│                                  │\n");
				printf("└─────────────────┘\n");
				getch();
				system("cls");
				return q;
			}
			else
			{
				Position(1,4);
				printf("┌─────────────────┐\n");
				printf("│ [!]提示:无该订单记录,请输入数据! │\n");
				printf("└─────────────────┘\n");
				getch();
				system("cls");
				return NULL;
			}
			break;
			case 7 :
			goto flag;
			break;
		}
	}
	else
	{
		system("cls");
		printf("┌─────────────────┐\n");
		printf("│  [!]提示:无订单数据,请输入数据!  │\n");
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
