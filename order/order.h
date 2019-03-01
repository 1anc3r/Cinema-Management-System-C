//============================================================================
// Name        : order.h
// Author      : lancer
// Version     : 2.1
// Copyright   : made by lancer
// Description : Cinema Management System in C, Ansi-style
//============================================================================

void Order();

void Order()
{
	int i,j;								//座位二维数组的下标
	int gth;								//片名长度,因定义了len所以用gth,length
	int u=0;								//场次数量
	int row,len;							//光标所在行和列,特殊计算后与二维数组的下标相对应
	int randnum;							//随机数用于产生订单号
	int (*seat)[14];						//座位二维数组
	char filename[23]="";					//场次文件名
	char stryear[5],strmonth[3],strday[3],stropenhour[3],stropenmin[3],strclosehour[3],strclosemin[3],strhallnum[3];
	int flagofseat=0;						//是否选定座位
	int flagoffilm=0;						//是否加载文件
	int choosefilm;
	int choosedate;
	film *p;								//电影头节点指针
	film *q;								//电影移动指针
	date *d;								//场次头节点指针
	date *b;								//场次移动指针
	order *first,*move,*last;				//用户订单链表
	HANDLE hOut;							//控制台输出流句柄
	hOut = GetStdHandle(STD_OUTPUT_HANDLE);	//获取句柄,改变颜色
	/****************************************************/
	step1:
	p=FilmRead();
	p=p->next;
	q=p;
	line=4;
	system("cls");
	printf("┌──────────────────────────────────┐\n");
	printf("│          第一步:选择电影         │\n");
	printf("│──────────────────────────────────│\n");
	while(p!=NULL)
	{
		printf("│  %s",p->filmname);
		gth=strlen(p->filmname);
		for(i = 0;i < 23-gth;i++)
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
	if(choosefilm==0)
	{
		goto flagofexit;
	}
	for(i=0;i<(choosefilm-4)/3;i++)
	{
		q=q->next;
	}
	d=q->premiere->next;
	/****************************************************/
	step2:
	b=d;
	line=9;
	system("cls");
	printf("┌──────────────────────────────────┐\n");
	printf("│          第二步:选择场次         │\n");
	printf("│──────────────────────────────────│\n");
	printf("│  %s",q->filmname);
	gth=strlen(q->filmname);
	for(i = 0;i < 23-gth;i++)
	{
		printf(" ");
	}
	printf("%3.1lf评分  │\n",q->score);
	printf("│  片长：%3.lf分钟         %6.2lf元  │\n",q->length,q->fare);
	printf("│──────────────────────────────────│\n");
	printf("│  %4d年%2d月%2d日                  │\n",b->year,b->month,b->day);
	printf("│──────────────────────────────────│\n");
	while(b!=NULL)
	{
		Position(1,line);
		printf("│  %2d:%2d-%2d:%2d               %2d厅  │\n",b->openhour,b->openmin,b->closehour,b->closemin,b->hallnum);
		printf("│──────────────────────────────────│\n");
		b=b->next;
		line+=2;
		u++;
	}
	printf("│                                  │\n");
	printf("└──────────────────────────────────┘\n");
	choosedate=Cursor(9,2*u+7,2,34,0,2);
	if(choosedate==0)
	{
		goto step1;
	}
	for(i=0;i<(choosedate-9)/2;i++)
	{
		d=d->next;
	}
	/****************************************************/
	step3:
	system("cls");
	printf("┌──────────────────────────────────┐\n");
	printf("│          第三步:选择座位         │\n");
	printf("│──────────────────────────────────│\n");
	printf("│  %s",q->filmname);
	gth=strlen(q->filmname);
	for(i = 0;i < 23-gth;i++)
	{
		printf(" ");
	}
	printf("%3.1lf评分  │\n",q->score);
	printf("│  片长：%3.lf分钟         %6.2lf元  │\n",q->length,q->fare);
	printf("│──────────────────────────────────│\n");
	printf("│  %4d年%2d月%2d日                  │\n",d->year,d->month,d->day);
	printf("│──────────────────────────────────│\n");
	printf("│  %2d:%2d-%2d:%2d               %2d厅  │\n",d->openhour,d->openmin,d->closehour,d->closemin,d->hallnum);
	printf("│──────────────────────────────────│\n");
	printf("│□可选  ");
	SetConsoleTextAttribute(hOut, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY );
	printf("■已选  ");
	SetConsoleTextAttribute(hOut, FOREGROUND_RED | FOREGROUND_INTENSITY );
	printf("■已售            ");
	SetConsoleTextAttribute(hOut, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE );
	printf("│\n│──────────────────────────────────│\n");
	printf("│┌────────────────────────────────┐│\n");
	printf("││              银幕              ││\n");
	printf("│└────────────────────────────────┘│\n");
	printf("│                                  │\n");
	printf("│┌ ┐                               │\n");
	printf("││1│ □□□□□□□□□□□□□□ ││\n");
	printf("││2│ □□□□□□□□□□□□□□ ││\n");
	printf("││3│ □□□□□□□□□□□□□□ ││\n");
	printf("││4│ □□□□□□□□□□□□□□ ││\n");
	printf("││5│ □□□□□□□□□□□□□□ ││\n");
	printf("││6│ □□□□□□□□□□□□□□ ││\n");
	printf("│└ ┘                               │\n");
	printf("│                                  │\n");
	printf("└──────────────────────────────────┘\n");
	if(flagoffilm==0)
	{
		itoa(d->year,stryear,10);
		itoa(d->month,strmonth,10);
		itoa(d->day,strday,10);
		itoa(d->openhour,stropenhour,10);
		itoa(d->openmin,stropenmin,10);
		itoa(d->closehour,strclosehour,10);
		itoa(d->closemin,strclosemin,10);
		itoa(d->hallnum,strhallnum,10);
		strcat(filename,stryear);
		strcat(filename,strmonth);
		strcat(filename,strday);
		strcat(filename,stropenhour);
		strcat(filename,stropenmin);
		strcat(filename,strclosehour);
		strcat(filename,strclosemin);
		strcat(filename,strhallnum);
		strcat(filename,".txt");
		seat=SeatRead(s,filename);
		flagoffilm=1;
	}
	for(i=0;i<6;i++)
	{
		for(j=0;j<14;j++)
		{
			Position(row,len);
			if(seat[i][j]==0)
			{
				Position(j*2+8,i+18);
				printf("□");
			}
			if(seat[i][j]==1)
			{
				Position(j*2+8,i+18);
				SetConsoleTextAttribute(hOut, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY );
				printf("■");
				SetConsoleTextAttribute(hOut, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE );
			}
			if(seat[i][j]==2)
			{
				Position(j*2+8,i+18);
				SetConsoleTextAttribute(hOut, FOREGROUND_RED | FOREGROUND_INTENSITY );
				printf("■");
				SetConsoleTextAttribute(hOut, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE );
			}
		}
	}
	row=8,len=18;
	Position(row,len);
	printf("※");
	while((ch=getch())!=0x0d)
	{
		while(ch==0x48)
		{
			if(len==18)
			{
				break;
			}
			else
			{
				Position(row,len);
				if(seat[len-18][(row-8)/2]==0)
				{
					printf("□");
				}
				else if(seat[len-18][(row-8)/2]==1){
					SetConsoleTextAttribute(hOut, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY );
					printf("■");
					SetConsoleTextAttribute(hOut, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE );
				}
				else if(seat[len-18][(row-8)/2]==2){
					SetConsoleTextAttribute(hOut, FOREGROUND_RED | FOREGROUND_INTENSITY );
					printf("■");
					SetConsoleTextAttribute(hOut, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE );
				}
				len--;
				Position(row,len);
				printf("※");
				break;
			}
		}
		while(ch==0x50)
		{
			if(len==23)
			{
				break;
			}
			else
			{
				Position(row,len);
				if(seat[len-18][(row-8)/2]==0)
				{
					printf("□");
				}
				else if(seat[len-18][(row-8)/2]==1){
					SetConsoleTextAttribute(hOut, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY );
					printf("■");
					SetConsoleTextAttribute(hOut, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE );
				}
				else if(seat[len-18][(row-8)/2]==2){
					SetConsoleTextAttribute(hOut, FOREGROUND_RED | FOREGROUND_INTENSITY );
					printf("■");
					SetConsoleTextAttribute(hOut, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE );
				}
				len++;
				Position(row,len);
				printf("※");
				break;
			}
		}
		while(ch==0x4b)
		{
			if(row==8)
			{
				break;
			}
			else
			{
				Position(row,len);
				if(seat[len-18][(row-8)/2]==0)
				{
					printf("□");
				}
				else if(seat[len-18][(row-8)/2]==1){
					SetConsoleTextAttribute(hOut, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY );
					printf("■");
					SetConsoleTextAttribute(hOut, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE );
				}
				else if(seat[len-18][(row-8)/2]==2){
					SetConsoleTextAttribute(hOut, FOREGROUND_RED | FOREGROUND_INTENSITY );
					printf("■");
					SetConsoleTextAttribute(hOut, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE );
				}
				row-=2;
				Position(row,len);
				printf("※");
				break;
			}
		}
		while(ch==0x4d)
		{
			if(row==34)
			{
				break;
			}
			else
			{
				Position(row,len);
				if(seat[len-18][(row-8)/2]==0)
				{
					printf("□");
				}
				else if(seat[len-18][(row-8)/2]==1){
					SetConsoleTextAttribute(hOut, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY );
					printf("■");
					SetConsoleTextAttribute(hOut, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE );
				}
				else if(seat[len-18][(row-8)/2]==2){
					SetConsoleTextAttribute(hOut, FOREGROUND_RED | FOREGROUND_INTENSITY );
					printf("■");
					SetConsoleTextAttribute(hOut, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE );
				}
				row+=2;
				Position(row,len);
				printf("※");
				break;
			}
		}
		while(ch==0x20)
		{
			if(seat[len-18][(row-8)/2]==1&&flagofseat==1)
			{
				seat[len-18][(row-8)/2]=0;
				flagofseat=0;
				Position(row,len);
				printf("□");
				break;
			}
			if(seat[len-18][(row-8)/2]==0&&flagofseat==0)
			{
				seat[len-18][(row-8)/2]=1;
				flagofseat=1;
				Position(row,len);
				SetConsoleTextAttribute(hOut, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY );
				printf("■");
				SetConsoleTextAttribute(hOut, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE );
				break;
			}
			if(seat[len-18][(row-8)/2]==0&&flagofseat==1)
			{
				Position(1,13);
				printf("┌──────────────────────────────────┐\n");
				printf("│             一人一座!            │\n");
				printf("└──────────────────────────────────┘\n");
				Sleep(200);
				goto step3;
			}
			if(seat[len-18][(row-8)/2]==2&&(flagofseat==0||flagofseat==1))
			{
				Position(1,13);
				printf("┌──────────────────────────────────┐\n");
				printf("│             座位已售!            │\n");
				printf("└──────────────────────────────────┘\n");
				Sleep(200);
				goto step3;
			}
		}
		if(ch==0x1b)
		{
			goto step2;
		}
	}
	if(seat[len-18][(row-8)/2]==2)
	{
		Position(1,13);
		printf("┌──────────────────────────────────┐\n");
		printf("│             该座已售!            │\n");
		printf("└──────────────────────────────────┘\n");
		Sleep(200);
		goto step3;
	}
	/****************************************************/
	step4:
	if(seat[len-18][(row-8)/2]!=1)
	{
		goto step3;
	}
	srand((unsigned)time(NULL)); /*随机种子*/
	randnum=rand()%(10000000-999999+1)+999999;
	system("cls");
	printf("┌──────────────────────────────────┐\n");
	printf("│          第四步:确认选择         │\n");
	printf("│──────────────────────────────────│\n");
	printf("│            选座票信息            │\n");
	printf("│──────────────────────────────────│\n");
	printf("│  订单：                 %7d  │\n",randnum);
	printf("│──────────────────────────────────│\n");
	printf("│  片名:");
	gth=strlen(q->filmname);
	for(i = 0;i < 25-gth;i++)
	{
		printf(" ");
	}
	printf("%s  │\n",q->filmname);
	printf("│──────────────────────────────────│\n");
	printf("│  片长：                 %3.lf分钟  │\n",q->length);
	printf("│──────────────────────────────────│\n");
	printf("│  日期:           %4d年%2d月%2d日  │\n",d->year,d->month,d->day);
	printf("│──────────────────────────────────│\n");
	printf("│  场次:              %2d:%2d-%2d:%2d  │\n",d->openhour,d->openmin,d->closehour,d->closemin);
	printf("│──────────────────────────────────│\n");
	printf("│  院厅:                     %2d厅  │\n",d->hallnum);
	printf("│──────────────────────────────────│\n");
	printf("│  座位:                 %2d排%2d座  │\n",len-18+1,(row-8)/2+1);
	printf("│──────────────────────────────────│\n");
	printf("│  小计:                 %6.2lf元  │\n",q->fare);
	printf("│──────────────────────────────────│\n");
	printf("│            确认支付？            │\n");
	printf("└──────────────────────────────────┘\n");
	while((ch=getch())!=0x0d)
	{
		if(ch==0x1b)
		{
			goto step3;
		}
	}
	seat[len-18][(row-8)/2]=2;
	SeatSave(seat,filename);
	move=OrderRead();
	first=move;
	last=(order*)malloc(sizeof(order));
	srand((unsigned)time(NULL)); /*随机种子*/
	last->ordernum=randnum;
	last->shit[0]=len-18+1;
	last->shit[1]=(row-8)/2+1;
	strcpy(last->filmname,q->filmname);
	last->score=q->score;
	last->length=q->length;
	last->fare=q->fare;
	last->day=d->day;
	last->year=d->year;
	last->month=d->month;
	last->openhour=d->openhour;
	last->openmin=d->openmin;
	last->closehour=d->closehour;
	last->closemin=d->closemin;
	last->hallnum=d->hallnum;
	o++;
	while(move->next!=NULL)
	{
		move=move->next;
	}
	move->next=last;
	OrderSave(first);
	//订单文件操作
	/****************************************************/
	flagofexit:
	system("cls");
	Sleep(200);
	if(flagofseat==1)
	{
		printf("┌──────────────────────────────────┐\n");
		printf("│             交易成功!            │\n");
		printf("└──────────────────────────────────┘\n");
	}
	else
	{
		if(flagofseat!=0)
		{
			printf("┌──────────────────────────────────┐\n");
			printf("│             交易失败!            │\n");
			printf("└──────────────────────────────────┘\n");
		}
		else
		{
			printf("┌──────────────────────────────────┐\n");
			printf("│             欢迎使用!            │\n");
			printf("└──────────────────────────────────┘\n");
		}
	}
	getch();
	OrderRead();
}
