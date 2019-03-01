//============================================================================
// Name        : filmdelete.h
// Author      : lancer
// Version     : 2.1
// Copyright   : made by lancer
// Description : Cinema Management System in C, Ansi-style
//============================================================================

/*
typedef struct film                 //电影
{
    char filmname[22];              //片名
    double score;                   //评分
    double length;                  //片长
    double fare;                    //票价
    struct date *premiere;          //首映
    struct film *next;
}film;
*/

void FilmDelete(film *p);

void FilmDelete(film *p)
{
    int i;                          //循环岗哨
    int len;                        //片名长度
    int choose;
    film *o,*q;                     //影片待删除节点及其前一节点
    q=p->next;
    o=FilmQuery(p);
    if(o!=NULL)
    {
        line=5;
        system("cls");
        printf("┌──────────────────────────────────┐\n");
        printf("│           删除影片信息           │\n");
        printf("│──────────────────────────────────│\n");
        printf("│                                  │\n");
        printf("│           [1]-----确认           │\n");
        printf("│                                  │\n");
        printf("│           [0]-----取消           │\n");
        printf("│                                  │\n");
        printf("└──────────────────────────────────┘\n");
        choose=Cursor(5,7,11,25,7,2);
        system("cls");
        switch(choose)
        {
            case 5 :
            while(q->next!=NULL&&(strcmp(o->filmname,q->filmname)!=0))
            {
                p=p->next;
                q=p->next;
            }
            if(strcmp(o->filmname,q->filmname)==0)
            {
                p->next=q->next;
                free(q);
                n--;
            }
            break;
            case 7 :
            break;
        }
        system("cls");
    }
    else
    {
        printf("┌──────────────────────────────────┐\n");
        printf("│ [!]提示:无该影片数据,请输入数据! │\n");
        printf("└──────────────────────────────────┘\n");
        getch();
        system("cls");
    }
    system("cls");
    printf("┌──────────────────────────────────┐\n");
    printf("│       [!]提示:删除完毕!          │\n");
	printf("│        任意键返回主菜单...       │\n");
    printf("└──────────────────────────────────┘\n");
    getch();
    system("cls");
}
