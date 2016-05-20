//============================================================================
// Name        : fileread.h
// Author      : lancer
// Version     : 2.1
// Copyright   : made by lancer
// Description : Cinema Management System in C, Ansi-style
//============================================================================

/*
typedef struct film                 //电影
{
    char filmname[22];              //电影名
    double score;                   //评分
    double length;                  //片长
    double fare;                    //票价
    struct date *premiere;          //首映
    struct film *next;
}film;
*/

film* FilmRead();

film* FilmRead()
{
	FILE *fp;
	film *phead,*pend,*pnew;
	date *qhead,*qend,*qnew;
	int tempyear,tempmonth,tempday,tempopenhour,tempopenmin,tempclosehour,tempclosemin,temphallnum;
	if((fp=fopen("data/infofilm.txt","rt+"))==NULL)
	{
		system("cls");
		printf("┌─────────────────┐\n");
		printf("│       [!]提示:文件打开失败!      │\n");
		printf("└─────────────────┘\n");
		getch();
		exit(0);
	}
	pnew=0;
	qnew=0;
	n=0;
	phead=(film*)malloc(sizeof(film));
	phead->next=NULL;
	pend=phead;
	while(!feof(fp))
	{
		pnew=(film*)malloc(sizeof(film));
		fscanf(fp,FILMF,pnew->filmname,&pnew->score,&pnew->length,&pnew->fare);
		pnew->premiere=(date*)malloc(sizeof(date));
		qend=pnew->premiere;
		fscanf(fp,TIMEF,&tempyear,&tempmonth,&tempday,&tempopenhour,&tempopenmin,&tempclosehour,&tempclosemin,&temphallnum);
		while(!(tempyear==0&&tempmonth==0&&tempday==0&&tempopenhour==0&&tempopenmin==0&&tempclosehour==0&&tempclosemin==0&&temphallnum==0))
		{
			qnew=(date*)malloc(sizeof(date));
			qnew->year=tempyear;
			qnew->month=tempmonth;
			qnew->day=tempday;
			qnew->openhour=tempopenhour;
			qnew->openmin=tempopenmin;
			qnew->closehour=tempclosehour;
			qnew->closemin=tempclosemin;
			qnew->hallnum=temphallnum;
			qend->next=qnew;
			qend=qnew;
			fscanf(fp,TIMEF,&tempyear,&tempmonth,&tempday,&tempopenhour,&tempopenmin,&tempclosehour,&tempclosemin,&temphallnum);
		}
		qend->next=NULL;
		pend->next=pnew;
		pend=pnew;
		n++;
	}
	pend->next=NULL;
	fclose(fp);
	return phead;
}
