//============================================================================
// Name        : filmmodify.h
// Author      : lancer
// Version     : 2.1
// Copyright   : made by lancer
// Description : Cinema Management System in C, Ansi-style
//============================================================================

void FilmModify(film *p);

void FilmModify(film *p)
{
	int i;                          //ѭ������
    int len;                        //Ƭ������
    int choose;
	char name;						//�޸�Ƭ�����ַ�
	char tempname[22];				//�޸�Ƭ�����ַ���
	film *q;						//���޸�ӰƬ�ڵ�
	date *t;						//���޸�ӰƬ�ڵ���ӳ
	q=FilmQuery(p);
	if(q!=NULL)
	{
		flag:
		line=4;
		system("cls");
		printf("��������������������������������������\n");
		printf("��           �޸�ӰƬ��Ϣ           ��\n");
		printf("��������������������������������������\n");
		printf("��           [1]-----Ƭ��           ��\n");
		printf("��           [2]-----����           ��\n");
		printf("��           [3]-----Ƭ��           ��\n");
		printf("��           [4]-----Ʊ��           ��\n");
		printf("��           [0]-----ȡ��           ��\n");
		printf("��������������������������������������\n");
		choose=Cursor(4,8,12,26,8,1);
		system("cls");
		switch(choose)
		{
			case 4 :
			printf("��������������������������������������\n");
			printf("��  ��Ƭ��:                         ��\n");
			printf("��������������������������������������\n");
			Position(12,2);
			i=0;
			while((name=getch())!='\r')
			{
				if(i<22&&name!='\b')
				{
					tempname[i++]=name;
					printf("%c",name);
				}
				if(i>0&&name=='\b')
				{
					--i;
					putchar('\b');
					putchar(' ');
					putchar('\b');
				}
				if(i==22)
				{
					continue;
				}
			}
			putchar('\n');
			tempname[i]='\0';
			strcpy(q->filmname,tempname);
			break;
			case 5 :
			printf("��������������������������������������\n");
			printf("��  ������:                         ��\n");
			printf("��������������������������������������\n");
			Position(12,2);
			scanf("%lf",&q->score);
			if(q->score<0||q->score>9.999)
			{
				Position(1,4);
				printf("��������������������������������������\n");
				printf("��        [!]��ʾ:�����ʽ!         ��\n");
				printf("��������������������������������������\n");
				getch();
				goto flag;
			}
			break;
			case 6 :
			printf("��������������������������������������\n");
			printf("��  ��Ƭ��:                         ��\n");
			printf("��������������������������������������\n");
			Position(12,2);
			scanf("%lf",&q->length);
			if(q->score<0||q->score>999.9)
			{
				Position(1,4);
				printf("��������������������������������������\n");
				printf("��        [!]��ʾ:�����ʽ!         ��\n");
				printf("��������������������������������������\n");
				getch();
				goto flag;
			}
			break;
			case 7 :
			printf("��������������������������������������\n");
			printf("��  ��Ʊ��:                         ��\n");
			printf("��������������������������������������\n");
			Position(12,2);
			scanf("%lf",&q->fare);
			if(q->score<0||q->score>999.9)
			{
				Position(1,4);
				printf("��������������������������������������\n");
				printf("��        [!]��ʾ:�����ʽ!         ��\n");
				printf("��������������������������������������\n");
				getch();
				goto flag;
			}
			break;
			case 8 :
			goto flagofexit;
			break;
		}
		Position(1,4);
		printf("��������������������������������������\n");
		printf("��             ӰƬ��Ϣ             ��\n");
		printf("��������������������������������������\n");
		printf("��  %s",q->filmname);
		len=strlen(q->filmname);
		for(i = 0;i < 23-len;i++)
		{
			printf(" ");
		}
		printf("%3.1lf����  ��\n",q->score);
		printf("��  Ƭ����%3.lf����         %6.2lfԪ  ��\n",q->length,q->fare);
		printf("��������������������������������������\n");
		printf("��  %4d��%2d��%2d��                  ��\n",q->premiere->next->year,q->premiere->next->month,q->premiere->next->day);
		printf("��������������������������������������\n");
		line=12;
		t=q->premiere->next;
		while(t!=NULL)
		{
			Position(1,line);
			printf("��  %2d:%2d-%2d:%2d                     ��\n",t->openhour,t->openmin,t->closehour,t->closemin);
			printf("��������������������������������������\n");
			t=t->next;
			line+=2;
		}
		printf("��                                  ��\n");
		printf("��������������������������������������\n");
		getch();
		system("cls");
	}
	else
	{
		system("cls");
		printf("��������������������������������������\n");
		printf("��  [!]��ʾ:��ӰƬ����,����������!  ��\n");
		printf("��������������������������������������\n");
		getch();
		system("cls");
	}
	flagofexit:
	system("cls");
	printf("��������������������������������������\n");
	printf("��       [!]��ʾ:�޸����!          ��\n");
	printf("��       ������������˵�...        ��\n");
	printf("��������������������������������������\n");
	getch();
	system("cls");
}