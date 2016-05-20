//============================================================================
// Name        : usersort.h
// Author      : lancer
// Version     : 2.1
// Copyright   : made by lancer
// Description : Cinema Management System in C, Ansi-style
//============================================================================

user *UserSort(user *p);

user *UserSort(user *p)
{
    char ch;
    int line;
    int choose;
    user *post,*card,*temp,*i,*j;
    if(m!=0)
    {
        line=5;
        system("cls");
        printf("┌─────────────────┐\n");
        printf("│           排序用户信息           │\n");
        printf("│─────────────────│\n");
        printf("│                                  │\n");
        printf("│           [1]-----权限           │\n");
        printf("│           [2]-----账号           │\n");
        printf("│           [0]-----取消           │\n");
        printf("│                                  │\n");
        printf("└─────────────────┘\n");
        choose=Cursor(5,7,12,26,7,1);
        post=(user*)malloc(sizeof(user));
        post->next=p;
        card=post;
        while(card->next->next!=NULL)
        {
            for(i=card,j=card->next;j->next!=NULL;j=j->next)
            {
                switch(choose)
                {
                    case 5 :
                    if((j->next->power)<(i->next->power)) i=j;
                    break;
                    case 6 :
                    if((j->next->id[0])<(i->next->id[0])) i=j;
                    break;
                    case 7 :
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
        printf("┌─────────────────┐\n");
        printf("│  [!]提示:无用户数据,请输入数据!  │\n");
        printf("└─────────────────┘\n");
    }
    getch();
    system("cls");
    flag:
    return p;
}
