//============================================================================
// Name        : login.h
// Author      : lancer
// Version     : 2.1
// Copyright   : made by lancer
// Description : Cinema Management System in C, Ansi-style
//============================================================================

int Login();

int Login()
{
	int i=0;
	user *p;
	int tempower;
	char tempid[15]="",tempasswd[15]="",ch;
	char id,word;
	system("cls");
	printf("©∞©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©¥\n");
	printf("©¶©∞©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©¥©¶\n");
	printf("©¶©¶             µ«¬º               ©¶©¶\n");
	printf("©¶©∏©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©º©¶\n");
	printf("©¶©∞©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©¥©¶\n");
	printf("©¶©¶                                ©¶©¶\n");
	printf("©¶©¶   ©∞©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©¥   ©¶©¶\n");
	printf("©¶©¶   ©¶                        ©¶   ©¶©¶\n");
	printf("©¶©¶   ©¶’ ∫≈:                   ©¶   ©¶©¶\n");
	printf("©¶©¶   ©¶                        ©¶   ©¶©¶\n");
	printf("©¶©¶   ©¶√‹¬Î:                   ©¶   ©¶©¶\n");
	printf("©¶©¶   ©¶                        ©¶   ©¶©¶\n");
	printf("©¶©¶   ©∏©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©º   ©¶©¶\n");
	printf("©¶©¶                                ©¶©¶\n");
	printf("©¶©∏©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©º©¶\n");
	printf("©∏©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©º\n");
	Position(15,9);
	i=0;
	while((id=getch())!='\r')
	{
		if(i<15&&id!='\b')
		{
			tempid[i++]=id;
			printf("%c",id);
		}
		if(i>0&&id=='\b')
		{
			--i;
			putchar('\b');
			putchar(' ');
			putchar('\b');
		}
		if(i==15)
		{
			continue;
		}
	}
	putchar('\n');
	tempid[i]='\0';
	Position(15,11);
	i=0;
	while((word=getch())!='\r')
	{
		if(i<15&&word!='\b')
		{
			tempasswd[i++]=word;
			printf("*");
		}
		if(i>0&&word=='\b')
		{
			--i;
			putchar('\b');
			putchar(' ');
			putchar('\b');
		}
		if(i==15)
		{
			continue;
		}
	}
	putchar('\n');
	tempasswd[i]='\0';
	Sleep(200);
	p=UserRead();
	while(p->next!=NULL)
	{
		if((strcmp(tempid,p->next->id)==0)&&(strcmp(tempasswd,p->next->password)==0))
		{
			tempower=p->next->power;
			return tempower;
		}
		else
		{
			p=p->next;
		}
	}
	Position(1,9);
	printf("©¿©ÿ©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©ÿ©»\n");
	printf("©¶      [!]Ã· æ:Œﬁ”√ªß£¨«Î◊¢≤·!     ©¶\n");
	printf("©¿©–©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©–©»\n");
	getch();
	return 0;
}
