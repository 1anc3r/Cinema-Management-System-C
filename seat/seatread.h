//============================================================================
// Name        : seatread.h
// Author      : lancer
// Version     : 2.1
// Copyright   : made by lancer
// Description : Cinema Management System in C, Ansi-style
//============================================================================

ss SeatRead(int seat[][14],char filename[23]);

ss SeatRead(int seat[][14],char filename[23])
{
	int array[6][14]={0},i,j;
	FILE *fp;
	char tmpstr[26]="data/";
	strcat(tmpstr,filename);
	if((fp=fopen(tmpstr,"rt+"))==NULL)
	{
		system("cls");
		printf("┌─────────────────┐\n");
		printf("│       [!]提示:文件打开失败!      │\n");
		printf("└─────────────────┘\n");
		getch();
		exit(0);
	}
	while(!feof(fp))
	{
		for(i=0;i<6;i++)
		{
			for(j=0;j<14;j++)
			{
				fscanf(fp,"%d ",&array[i][j]);
				seat[i][j]=array[i][j];
			}
		}
		break;
	}
	fclose(fp);
	return seat;
}
