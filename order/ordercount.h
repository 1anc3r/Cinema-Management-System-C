//============================================================================
// Name        : ordercount.h
// Author      : lancer
// Version     : 2.1
// Copyright   : made by lancer
// Description : Cinema Management System in C, Ansi-style
//============================================================================

void OrderCount(film *fp,order *op);

void OrderCount(film *fp,order *op)
{
	double sum;
	order *oq;
	oq=op->next;
	film *q;						//影片链表移动节点指针
	date *t;						//场次链表头结点指针
	date *d;						//场次链表移动节点指针
	int i,j;						//循环岗哨
	int len;						//片名长度
	int u=0;						//场次数量
	int choosefilm;					//选择影片
	int choosedate;					//选择场次
	q=fp;
	system("cls");
	printf("┌──────────────────────────────────┐\n");
	printf("│           统计票务信息           │\n");
	printf("├──────────────────────────────────┤\n");
	while(fp!=NULL)
	{
		printf("│  %s",fp->filmname);
		len=strlen(fp->filmname);
		for(i = 0;i < 23-len;i++)
		{
			printf(" ");
		}
		printf("%3.1lf评分  │\n",fp->score);
		printf("│  片长：%3.lf分钟         %6.2lf元  │\n",fp->length,fp->fare);
		printf("├──────────────────────────────────┤\n");
		fp=fp->next;
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
	printf("│           统计票务信息           │\n");
	printf("├──────────────────────────────────┤\n");
	printf("│  %s",q->filmname);
	len=strlen(q->filmname);
	for(i = 0;i < 23-len;i++)
	{
		printf(" ");
	}
	printf("%3.1lf评分  │\n",q->score);
	printf("│  片长：%3.lf分钟         %6.2lf元  │\n",q->length,q->fare);
	printf("├──────────────────────────────────┤\n");
	printf("│  %4d年%2d月%2d日                  │\n",q->premiere->next->year,q->premiere->next->month,q->premiere->next->day);
	printf("├──────────────────────────────────┤\n");
	line=9;
	t=q->premiere->next;
	d=t;
	while(t!=NULL)
	{
		Position(1,line);
		printf("│  %2d:%2d-%2d:%2d               %2d厅  │\n",t->openhour,t->openmin,t->closehour,t->closemin,t->hallnum);
		printf("├──────────────────────────────────┤\n");
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
	if(o!=0)
	{
		sum=0.0;
		while(oq!=NULL)
		{
			if(oq->hallnum==d->hallnum)
			{
				sum+=oq->fare;
			}
			oq=oq->next;
		}
		printf("\n├──────────────────────────────────┤\n");
		printf("│  合计:                 %6.2lf元  │\n",sum);
		printf("└──────────────────────────────────┘\n");
	}
	else
	{
		Position(1,14);
		printf("┌──────────────────────────────────┐\n");
		printf("│  [!]提示:无订单记录,请输入数据!  │\n");
		printf("└──────────────────────────────────┘\n");
	}
	getch();
	system("cls");
}
