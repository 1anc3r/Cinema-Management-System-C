//============================================================================
// Name        : register.h
// Author      : lancer
// Version     : 2.1
// Copyright   : made by lancer
// Description : Cinema Management System in C, Ansi-style
//============================================================================

int Register();

int Register()
{
	int i=0;
	int tempower;
	char tempid[15],tempasswd[15];
	char id,word,pin[10];
	user *p;
	user *phead,*pend,*pnew;
	line=9;
	system("cls");
	printf("┌─────────────────┐\n");
	printf("│┌───────────────┐│\n");
	printf("││    	注册		  ││\n");
	printf("│└───────────────┘│\n");
	printf("│┌───────────────┐│\n");
	printf("││                              ││\n");
	printf("││   ┌──────────┐   ││\n");
	printf("││   │ 请选择权限:        │   ││\n");
	printf("││   │ [1]---售票员       │   ││\n");
	printf("││   │ [2]---经理         │   ││\n");
	printf("││   │ [3]---管理         │   ││\n");
	printf("││   │                    │   ││\n");
	printf("││   └──────────┘   ││\n");
	printf("││                              ││\n");
	printf("│└───────────────┘│\n");
	printf("└─────────────────┘\n");
	Position(10,line);
	printf(">");
	while((ch=getch())!=0x0d)
	{
		while(ch==0x48)
		{
			if(line==9)
			{
				break;
			}
			else
			{
				Position(10,line);
				printf(" ");
				line--;
				Position(10,line);
				printf(">");
				break;
			}
		}
		while(ch==0x50)
		{
			if(line==11)
			{
				break;
			}
			else
			{
				Position(10,line);
				printf(" ");
				line++;
				Position(10,line);
				printf(">");
				break;
			}
		}
	}
	tempower=line-8;
	Position(1,9);
	printf("├┴───────────────┴┤\n");
	printf("│  验证码:                         │\n");
	printf("├┬───────────────┬┤\n");
	Position(12,10);
	scanf("%s",pin);
	if((tempower==1&&strcmp(pin,"ticket")==0)||(tempower==2&&strcmp(pin,"manage")==0)||(tempower==3&&strcmp(pin,"admin")==0))
	{
		system("cls");
		printf("┌─────────────────┐\n");
		printf("│┌───────────────┐│\n");
		printf("││    	注册		  ││\n");
		printf("│└───────────────┘│\n");
		printf("│┌───────────────┐│\n");
		printf("││                              ││\n");
		printf("││   ┌──────────┐   ││\n");
		printf("││   │                    │   ││\n");
		printf("││   │帐号:               │   ││\n");
		printf("││   │                    │   ││\n");
		printf("││   │密码:               │   ││\n");
		printf("││   │                    │   ││\n");
		printf("││   └──────────┘   ││\n");
		printf("││                              ││\n");
		printf("│└───────────────┘│\n");
		printf("└─────────────────┘\n");
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
			if(strcmp(tempid,p->next->id)==0)
			{
				Position(1,9);
				printf("├┴───────────────┴┤\n");
				printf("│      [!]提示:无用户，请注册!     │\n");
				printf("├┬───────────────┬┤\n");
				getch();
				return 0;
			}
			else
			{
				p=p->next;
			}
		}
		phead=(user*)malloc(sizeof(user));
		pend=phead;
		pnew=(user*)malloc(sizeof(user));
		pnew->power=tempower;
		strcpy(pnew->id,tempid);
		strcpy(pnew->password,tempasswd);
		pend->next=pnew;
		pend=pnew;
		pend->next=NULL;
		UserSave(phead);
		return 1;
	}
	else
	{
		return 0;
	}
}
