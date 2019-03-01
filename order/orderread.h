//============================================================================
// Name        : orderread.h
// Author      : lancer
// Version     : 2.1
// Copyright   : made by lancer
// Description : Cinema Management System in C, Ansi-style
//============================================================================

order *OrderRead();

order *OrderRead() 
{
	FILE *fp;
	order *phead,*pend,*pnew;
	if((fp=fopen("data/infoorder.txt","rt+"))==NULL)
	{
		system("cls");
		printf("┌──────────────────────────────────┐\n");
		printf("│       [!]提示:文件打开失败!      │\n");
		printf("└──────────────────────────────────┘\n");
		getch();
		exit(0);
	}
	o=0;
	pnew=0;
	phead=(order*)malloc(sizeof(order));
	phead->next=NULL;
	pend=phead;
	while(!feof(fp)) 
	{
		pnew=(order*)malloc(sizeof(order));
		//fscanf(fp,ORDER,&pnew->ordernum,&pnew->shit[0],&pnew->shit[1],&pnew->filmname,&pnew->score,&pnew->length,&pnew->fare,&pnew->day,&pnew->month,&pnew->year,&pnew->openhour,&pnew->openmin,&pnew->closehour,&pnew->closemin);
		//fscanf(fp,"%d\n",&pnew->ordernum);
		fscanf(fp,"%d %d %d %d\n",&pnew->ordernum,&pnew->hallnum,&pnew->shit[0],&pnew->shit[1]);
		fscanf(fp,"%s %lf %lf %lf\n",pnew->filmname,&pnew->score,&pnew->length,&pnew->fare);
		fscanf(fp,"%d %d %d %d %d %d %d\n",&pnew->day,&pnew->month,&pnew->year,&pnew->openhour,&pnew->openmin,&pnew->closehour,&pnew->closemin);
		pend->next=pnew;
		pend=pnew;
		o++;
	}
	pend->next=NULL;
	fclose(fp);
	return phead;
}
