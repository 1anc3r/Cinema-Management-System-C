//============================================================================
// Name        : filmmodify.h
// Author      : lancer
// Version     : 2.1
// Copyright   : made by lancer
// Description : Cinema Management System in C, Ansi-style
//============================================================================

void FilmModify(film *p);

void FilmModify(film *p)
{
	int i;                          //循环岗哨
    int len;                        //片名长度
    int choose;
	char name;						//修改片名单字符
	char tempname[22];				//修改片名单字符集
	film *q;						//待修改影片节点
	date *t;						//待修改影片节点首映
	q=FilmQuery(p);
	if(q!=NULL)
	{
		flag:
		line=4;
		system("cls");
		printf("┌──────────────────────────────────┐\n");
		printf("│           修改影片信息           │\n");
		printf("│──────────────────────────────────│\n");
		printf("│           [1]-----片名           │\n");
		printf("│           [2]-----评分           │\n");
		printf("│           [3]-----片长           │\n");
		printf("│           [4]-----票价           │\n");
		printf("│           [0]-----取消           │\n");
		printf("└──────────────────────────────────┘\n");
		choose=Cursor(4,8,11,25,8,1);
		system("cls");
		switch(choose)
		{
			case 4 :
			printf("┌──────────────────────────────────┐\n");
			printf("│  新片名:                         │\n");
			printf("└──────────────────────────────────┘\n");
			Position(12,2);
			i=0;
			while((name=getch())!='\r')
			{
				if(i<22&&name!='\b')
				{
					tempname[i++]=name;
					printf("%c",name);
				}
				if(i>0&&name=='\b')
				{
					--i;
					putchar('\b');
					putchar(' ');
					putchar('\b');
				}
				if(i==22)
				{
					continue;
				}
			}
			putchar('\n');
			tempname[i]='\0';
			strcpy(q->filmname,tempname);
			break;
			case 5 :
			printf("┌──────────────────────────────────┐\n");
			printf("│  新评分:                         │\n");
			printf("└──────────────────────────────────┘\n");
			Position(12,2);
			scanf("%lf",&q->score);
			if(q->score<0||q->score>9.999)
			{
				Position(1,4);
				printf("┌──────────────────────────────────┐\n");
				printf("│        [!]提示:错误格式!         │\n");
				printf("└──────────────────────────────────┘\n");
				getch();
				goto flag;
			}
			break;
			case 6 :
			printf("┌──────────────────────────────────┐\n");
			printf("│  新片长:                         │\n");
			printf("└──────────────────────────────────┘\n");
			Position(12,2);
			scanf("%lf",&q->length);
			if(q->score<0||q->score>999.9)
			{
				Position(1,4);
				printf("┌──────────────────────────────────┐\n");
				printf("│        [!]提示:错误格式!         │\n");
				printf("└──────────────────────────────────┘\n");
				getch();
				goto flag;
			}
			break;
			case 7 :
			printf("┌──────────────────────────────────┐\n");
			printf("│  新票价:                         │\n");
			printf("└──────────────────────────────────┘\n");
			Position(12,2);
			scanf("%lf",&q->fare);
			if(q->score<0||q->score>999.9)
			{
				Position(1,4);
				printf("┌──────────────────────────────────┐\n");
				printf("│        [!]提示:错误格式!         │\n");
				printf("└──────────────────────────────────┘\n");
				getch();
				goto flag;
			}
			break;
			case 8 :
			goto flagofexit;
			break;
		}
		Position(1,4);
		printf("┌──────────────────────────────────┐\n");
		printf("│             影片信息             │\n");
		printf("│──────────────────────────────────│\n");
		printf("│  %s",q->filmname);
		len=strlen(q->filmname);
		for(i = 0;i < 23-len;i++)
		{
			printf(" ");
		}
		printf("%3.1lf评分  │\n",q->score);
		printf("│  片长：%3.lf分钟         %6.2lf元  │\n",q->length,q->fare);
		printf("│──────────────────────────────────│\n");
		printf("│  %4d年%2d月%2d日                  │\n",q->premiere->next->year,q->premiere->next->month,q->premiere->next->day);
		printf("│──────────────────────────────────│\n");
		line=12;
		t=q->premiere->next;
		while(t!=NULL)
		{
			Position(1,line);
			printf("│  %2d:%2d-%2d:%2d                     │\n",t->openhour,t->openmin,t->closehour,t->closemin);
			printf("│──────────────────────────────────│\n");
			t=t->next;
			line+=2;
		}
		printf("│                                  │\n");
		printf("└──────────────────────────────────┘\n");
		getch();
		system("cls");
	}
	else
	{
		system("cls");
		printf("┌──────────────────────────────────┐\n");
		printf("│  [!]提示:无影片数据,请输入数据!  │\n");
		printf("└──────────────────────────────────┘\n");
		getch();
		system("cls");
	}
	flagofexit:
	system("cls");
	printf("┌──────────────────────────────────┐\n");
	printf("│       [!]提示:修改完毕!          │\n");
	printf("│       任意键返回主菜单...        │\n");
	printf("└──────────────────────────────────┘\n");
	getch();
	system("cls");
}
