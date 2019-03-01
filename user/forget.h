//============================================================================
// Name        : forget.h
// Author      : lancer
// Version     : 2.1
// Copyright   : made by lancer
// Description : Cinema Management System in C, Ansi-style
//============================================================================

int Forget();

int Forget()
{
	int i;
	user *p,*q;
	char tempid[15],tempasswd[15],ch,id,word;
	system("cls");
	printf("┌────────────────────────────────┐\n");
	printf("│┌──────────────────────────────┐│\n");
	printf("││           忘记密码           ││\n");
	printf("│└──────────────────────────────┘│\n");
	printf("│┌──────────────────────────────┐│\n");
	printf("││                              ││\n");
	printf("││   ┌──────────────────────┐   ││\n");
	printf("││   │                      │   ││\n");
	printf("││   │帐号:                 │   ││\n");
	printf("││   │                      │   ││\n");
	printf("││   │密码:                 │   ││\n");
	printf("││   │                      │   ││\n");
	printf("││   └──────────────────────┘   ││\n");
	printf("││                              ││\n");
	printf("│└──────────────────────────────┘│\n");
	printf("└────────────────────────────────┘\n");
	Position(15,9);
	//scanf("%s",tempid);
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
	q=UserRead();
	p=q;
	while(p!=NULL)
	{
		if(strcmp(tempid,p->id)==0)
		{
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
			strcpy(p->password,tempasswd);
			UserSave(q);
			Sleep(200);
			return 1;
		}
		else
		{
			p=p->next;
		}
	}
	Position(1,9);
	printf("├┴──────────────────────────────┴┤\n");
	printf("│      [!]提示:无用户，请注册!     │\n");
	printf("├┬──────────────────────────────┬┤\n");
	getch();
	return 0;
}
