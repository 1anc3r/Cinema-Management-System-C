//============================================================================
// Name        : filmsort.h
// Author      : lancer
// Version     : 2.1
// Copyright   : made by lancer
// Description : Cinema Management System in C, Ansi-style
//============================================================================

/*
typedef struct film//电影
{
    char filmname[40];//电影名 %s
    double score;//评分 %3.2lf
    int length;//片长 %d
    double fare;//票价 %6.2lf
    struct date *premiere;//首映
}film;
*/

film *FilmSort(film *p);

film *FilmSort(film *p)
{
    int choose;
    film *post,*card,*temp,*i,*j;
    if(n!=0)
    {
        line=4;
        system("cls");
        printf("┌──────────────────────────────────┐\n");
        printf("│           排序影片信息           │\n");
        printf("│──────────────────────────────────│\n");
        printf("│           [1]-----片名           │\n");
        printf("│           [2]-----评分           │\n");
        printf("│           [3]-----片长           │\n");
        printf("│           [4]-----票价           │\n");
        printf("│           [0]-----取消           │\n");
        printf("└──────────────────────────────────┘\n");
        choose=Cursor(4,8,11,25,8,1);
        system("cls");
        post=(film*)malloc(sizeof(film));
        post->next=p;
        card=post;
        while(card->next->next!=NULL)
        {
            for(i=card,j=card->next;j->next!=NULL;j=j->next)
            {
                switch(line)
                {
                    case 4 :
                    if((j->next->filmname[0])<(i->next->filmname[0])) i=j;
                    break;
                    case 5 :
                    if((j->next->score)<(i->next->score)) i=j;
                    break;
                    case 6 :
                    if((j->next->length)<(i->next->length)) i=j;
                    break;
                    case 7 :
                    if((j->next->fare)<(i->next->fare)) i=j;
                    break;
                    case 8 :
                    goto flag;
                }
            }
            if(i!=j)
            {
                temp=i->next;
                i->next=temp->next;
                temp->next=card->next;
                card->next=temp;
            }
            card=card->next;
        }
        p=post->next;
        free(post);
        return p;
    }
    else
    {
        printf("┌──────────────────────────────────┐\n");
        printf("│  [!]提示:无影片数据,请输入数据!  │\n");
        printf("└──────────────────────────────────┘\n");
    }
    getch();
    system("cls");
    flag:
    return p;
}
