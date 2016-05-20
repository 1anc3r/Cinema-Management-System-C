//============================================================================
// Name        : hallread.h
// Author      : lancer
// Version     : 2.1
// Copyright   : made by lancer
// Description : Cinema Management System in C, Ansi-style
//============================================================================

date* HallRead();

date* HallRead()
{
	date *phead,*pend,*pnew,*t;
	film *f;
	f=FilmRead()->next;
	phead=(date*)malloc(sizeof(date));
	phead->next=NULL;
	pend=phead;
	while(f!=NULL)
	{
		t=f->premiere->next;
		while(t!=NULL)
		{
			pnew=(date*)malloc(sizeof(date));
			pnew=t;
			pend->next=pnew;
			pend=pnew;
			t=t->next;
		}
		pend->next=NULL;
		f=f->next;
	}
	return phead;
}
