//============================================================================
// Name        : filmsave.h
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
    double length;                     //片长
    double fare;                    //票价
    struct date *premiere;          //首映
    struct film *next;
}film;
*/

film* FilmSave(film *p);

film* FilmSave(film *p)
{
	int choose;
	char mod[4];
	FILE *fp;
	film *q;
	date *t;
	line=5;
	system("cls");
	printf("┌──────────────────────────────────┐\n");
	printf("│           保存影片信息           │\n");
	printf("│──────────────────────────────────│\n");
	printf("│                                  │\n");
	printf("│           [1]-----追加           │\n");
	printf("│           [2]-----覆盖           │\n");
	printf("│           [0]-----取消           │\n");
	printf("│                                  │\n");
	printf("└──────────────────────────────────┘\n");
	choose=Cursor(5,7,11,25,7,1);
	switch(choose)
	{
		case 5 :
		strcpy(mod,"at+");
		break;
		case 6 :
		strcpy(mod,"rt+");
		break;
		case 7 :
		return NULL;
	}
	if((fp=fopen("data/infofilm.txt",mod))==NULL)
	{
		system("cls");
		printf("┌──────────────────────────────────┐\n");
		printf("│       [!]提示:文件打开失败!      │\n");
		printf("└──────────────────────────────────┘\n");
		getch();
		exit(0);
	}
	for(q=p->next;q!=NULL;q=q->next)
	{
		fprintf(fp,FILMF,q->filmname,q->score,q->length,q->fare);
		for(t=q->premiere->next;t!=NULL;t=t->next)
		{
			fprintf(fp,TIMEF,t->year,t->month,t->day,t->openhour,t->openmin,t->closehour,t->closemin,t->hallnum);
		}
		fprintf(fp,"0 0 0 0 0 0 0 0\n");
	}
	fclose(fp);
	return NULL;
}
