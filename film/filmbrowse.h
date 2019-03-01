//============================================================================
// Name        : filmbrowse.h
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

void FilmBrowse(film *p);

void FilmBrowse(film *p)
{
	film *q;						//影片链表移动节点指针
	date *t;						//场次链表头结点指针
	date *d;						//场次链表移动节点指针
	int i,j;						//循环岗哨
	int len;						//片名长度
	int u=0;						//场次数量
	int choosefilm;					//选择影片
	int choosedate;					//选择场次
	q=p;
	if(n!=0)
	{
		system("cls");
		printf("┌──────────────────────────────────┐\n");
		printf("│           浏览影片信息           │\n");
		printf("│──────────────────────────────────│\n");
		while(p!=NULL)
		{
			printf("│  %s",p->filmname);
			len=strlen(p->filmname);
			for(i = 0;i < 23-len;i++)
			{
				printf(" ");
			}
			printf("%3.1lf评分  │\n",p->score);
			printf("│  片长：%3.lf分钟         %6.2lf元  │\n",p->length,p->fare);
			printf("│──────────────────────────────────│\n");
			p=p->next;
		}
		printf("│                                  │\n");
		printf("└──────────────────────────────────┘\n");
		choosefilm=Cursor(4,3*n+1,2,34,0,3);
		//选中目标电影后从链表头部遍历到链表相应位置
		for(i=0;i<(choosefilm-4)/3;i++)
		{
			q=q->next;
		}
		system("cls");
		printf("┌──────────────────────────────────┐\n");
		printf("│           浏览影片信息           │\n");
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
		line=9;
		t=q->premiere->next;
		d=t;
		while(t!=NULL)
		{
			Position(1,line);
			printf("│  %2d:%2d-%2d:%2d               %2d厅  │\n",t->openhour,t->openmin,t->closehour,t->closemin,t->hallnum);
			printf("│──────────────────────────────────│\n");
			t=t->next;
			line+=2;
			u++;
		}
		printf("│                                  │\n");
		printf("└──────────────────────────────────┘\n");
		choosedate=Cursor(9,2*u+7,2,34,0,2);
		for(i=0;i<(choosedate-9)/2;i++)
		{
			d=d->next;
		}
		HallView(q,d);
	}
	else
	{
		system("cls");
		printf("┌──────────────────────────────────┐\n");
		printf("│ [!]提示:无该影片记录,请输入数据! │\n");
		printf("└──────────────────────────────────┘\n");
	}
	getch();
	system("cls");
}
