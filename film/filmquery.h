//============================================================================
// Name        : filmquery.h
// Author      : lancer
// Version     : 2.1
// Copyright   : made by lancer
// Description : Cinema Management System in C, Ansi-style
//============================================================================

/*
typedef struct film                 //电影
{
    char filmname[22];              //片名
    double score;                   //评分
    double length;                  //片长
    double fare;                    //票价
    struct date *premiere;          //首映
    struct film *next;
}film;
*/

film* FilmQuery(film *p);

film* FilmQuery(film *p)
{
	int i;							//控制循环
	int len;						//片名长度
	int choose;
	char name;
	char tempname[22];				//输入片名
	int namelen;
	double tempscore;				//输入评分
	double templength;				//输入片长
	double tempfare;				//输入票价
	date *t;						//场次节点指针
	if(n!=0)
	{
		line=4;
		system("cls");
		printf("┌─────────────────┐\n");
		printf("│           查询影片信息           │\n");
		printf("│─────────────────│\n");
		printf("│           [1]-----片名           │\n");
		printf("│           [2]-----评分           │\n");
		printf("│           [3]-----片长           │\n");
		printf("│           [4]-----票价           │\n");
		printf("│           [0]-----取消           │\n");
		printf("└─────────────────┘\n");
		choose=Cursor(4,8,12,26,8,1);
		system("cls");
		switch(choose)
		{
			case 4 :
			printf("┌─────────────────┐\n");
			printf("│  片名:                           │\n");
			printf("└─────────────────┘\n");
			Position(10,2);
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
			namelen=strlen(tempname);
			while(p!=NULL&&memcmp(tempname,p->filmname,namelen))
			{
				p=p->next;
			}
			if(!memcmp(tempname,p->filmname,namelen))
			{
				Position(1,4);
				printf("┌─────────────────┐\n");
				printf("│             影片信息             │\n");
				printf("│─────────────────│\n");
				printf("│  %s",p->filmname);
				len=strlen(p->filmname);
				for(i = 0;i < 23-len;i++)
				{
					printf(" ");
				}
				printf("%3.1lf评分  │\n",p->score);
				printf("│  片长：%3.lf分钟         %6.2lf元  │\n",p->length,p->fare);
				printf("│─────────────────│\n");
				printf("│  %4d年%2d月%2d日                  │\n",p->premiere->next->year,p->premiere->next->month,p->premiere->next->day);
				printf("│─────────────────│\n");
				line=12;
				t=p->premiere->next;
				while(t!=NULL)
				{
					Position(1,line);
					printf("│  %2d:%2d-%2d:%2d                     │\n",t->openhour,t->openmin,t->closehour,t->closemin);
					printf("│─────────────────│\n");
					t=t->next;
					line+=2;
				}
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
				printf("│ [!]提示:无该影片记录,请输入数据! │\n");
				printf("└─────────────────┘\n");
				getch();
				system("cls");
				return NULL;
			}
			break;
			case 5 :
			printf("┌─────────────────┐\n");
			printf("│  评分:                           │\n");
			printf("└─────────────────┘\n");
			Position(10,2);
			scanf("%lf", &tempscore);
			while(p!=NULL&&p->score!=tempscore)
			{
				p=p->next;
			}
			if(p->score==tempscore)
			{
				Position(1,4);
				printf("┌─────────────────┐\n");
				printf("│             影片信息             │\n");
				printf("│─────────────────│\n");
				printf("│  %s",p->filmname);
				len=strlen(p->filmname);
				for(i = 0;i < 23-len;i++)
				{
					printf(" ");
				}
				printf("%3.1lf评分  │\n",p->score);
				printf("│  片长：%3.lf分钟         %6.2lf元  │\n",p->length,p->fare);
				printf("│─────────────────│\n");
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
				printf("│ [!]提示:无该影片记录,请输入数据! │\n");
				printf("└─────────────────┘\n");
				getch();
				system("cls");
				return NULL;
			}
			break;
			case 6 :
			printf("┌─────────────────┐\n");
			printf("│  片长:                           │\n");
			printf("└─────────────────┘\n");
			Position(10,2);
			scanf("%lf", &templength);
			while(p!=NULL&&p->length!=templength)
			{
				p=p->next;
			}
			if(p->length==templength)
			{
				Position(1,4);
				printf("┌─────────────────┐\n");
				printf("│             影片信息             │\n");
				printf("│─────────────────│\n");
				printf("│  %s",p->filmname);
				len=strlen(p->filmname);
				for(i = 0;i < 23-len;i++)
				{
					printf(" ");
				}
				printf("%3.1lf评分  │\n",p->score);
				printf("│  片长：%3.lf分钟         %6.2lf元  │\n",p->length,p->fare);
				printf("│─────────────────│\n");
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
				printf("│ [!]提示:无该影片记录,请输入数据! │\n");
				printf("└─────────────────┘\n");
				getch();
				system("cls");
				return NULL;
			}
			break;
			case 7 :
			printf("┌─────────────────┐\n");
			printf("│  票价:                           │\n");
			printf("└─────────────────┘\n");
			Position(10,2);
			scanf("%lf", &tempfare);
			while(p!=NULL&&p->fare!=tempfare)
			{
				p=p->next;
			}
			if(p->fare==tempfare)
			{
				Position(1,4);
				printf("┌─────────────────┐\n");
				printf("│             影片信息             │\n");
				printf("│─────────────────│\n");
				printf("│  %s",p->filmname);
				len=strlen(p->filmname);
				for(i = 0;i < 23-len;i++)
				{
					printf(" ");
				}
				printf("%3.1lf评分  │\n",p->score);
				printf("│  片长：%3.lf分钟         %6.2lf元  │\n",p->length,p->fare);
				printf("│─────────────────│\n");
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
				printf("│ [!]提示:无该影片记录,请输入数据! │\n");
				printf("└─────────────────┘\n");
				getch();
				system("cls");
				return NULL;
			}
			break;
			case 8 :
			goto flag;
			break;
		}
	}
	else
	{
		system("cls");
		printf("┌─────────────────┐\n");
		printf("│  [!]提示:无影片数据,请输入数据!  │\n");
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
