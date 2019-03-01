//============================================================================
// Name        : ordersave.h
// Author      : lancer
// Version     : 2.1
// Copyright   : made by lancer
// Description : Cinema Management System in C, Ansi-style
//============================================================================

void OrderSave(order *p);

void OrderSave(order *p)
{
	FILE *fp;
	order *q=NULL;
	if((fp=fopen("data/infoorder.txt","wt+"))==NULL)
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
		fprintf(fp,"%d %d %d %d\n",q->ordernum,q->hallnum,q->shit[0],q->shit[1]);
		fprintf(fp,"%s %lf %lf %lf\n",q->filmname,q->score,q->length,q->fare);
		fprintf(fp,"%d %d %d %d %d %d %d\n",q->day,q->month,q->year,q->openhour,q->openmin,q->closehour,q->closemin);
	}
	fclose(fp);
}
