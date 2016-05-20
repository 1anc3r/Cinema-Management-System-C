//============================================================================
// Name        : main.c
// Author      : lancer
// Version     : 2.1
// Copyright   : made by lancer
// Description : Cinema Management System in C, Ansi-style
//============================================================================

#include "func.h"

int main(void)
{
    //各菜单的返回值
    int mainkey,filmkey,hallkey,orderkey,userkey;
    int power;                      //权限
    film *filmpoint;                //影片头节点指针
    order *orderpoint;              //订单头节点指针
    user *userpoint;                //用户头节点指针
    HWND hwnd = FindWindow("ConsoleWindowClass", NULL);     //获取弹窗
    CONSOLE_CURSOR_INFO cursor_info = { 1, 0 };             //隐藏光标
    SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursor_info);
    system("title Cinema Management System");    //窗口标题
    MessageBox(hwnd, TEXT(
        "                   ←↑↓→方向键控制                   \n"
        "                   ENTER键下一步                    \n"
        "                   SPACE键确认/取消(座位)           \n"
        "                   ESC键上一步                      \n"
        "                                                    \n"
        "                            Cinema Management System\n"
        "                                            ――Made By Lancer\n"
        ), TEXT("欢迎使用影院管理系统"), MB_OK);
    NewFile();                      //若没有文件则创建文件
    filmpoint=FilmRead();           //从影片文件中读取信息
    orderpoint=OrderRead();         //从订单文件中读取信息
    userpoint=UserRead();           //从用户文件中读取信息
    flag:
    power=Setup();                  //登录系统并获取权限
    if(power==0)
    {
        goto flag;
    }
    while(1)
    {
        mainmenu:
        mainkey=MainMenu();
        system("cls");
        while(mainkey==6)           //影片信息管理系统
        {
            if(power==2||power==3)  //仅允许经理和管理员权限
            {
                filmkey=FilmMenu();
                switch(filmkey)
                {
                    case 6 :
                    filmpoint=FilmEnter();          //录入影片信息
                    break;
                    case 7 :
                    FilmBrowse(filmpoint->next);    //浏览影片信息
                    break;
                    case 8 :
                    FilmQuery(filmpoint);           //查询影片信息
                    break;
                    case 9 :
                    FilmModify(filmpoint);          //修改影片信息
                    break;
                    case 10 :
                    FilmDelete(filmpoint);          //删除影片信息
                    break;
                    case 11 :
                    filmpoint=FilmSort(filmpoint);  //排序影片信息
                    FilmBrowse(filmpoint->next);    //并显示
                    break;
                    case 12 :
                    FilmSave(filmpoint);            //保存影片信息
                    break;
                    case 13 :
                    filmpoint=FilmRead();           //读取影片信息
                    break;
                    case 14 :
                    goto mainmenu;
                }
            }
            else
            {
                system("cls");
                printf("┌─────────────────┐\n");
                printf("│             没有权限!            │\n");
                printf("└─────────────────┘\n");
                Sleep(200);
                goto mainmenu;
            }
        }
        while(mainkey==7)           //影厅管理系统
        {
            if(power==2||power==3)  //仅允许经理和管理员权限
            {
                hallkey=HallMenu();
                switch(hallkey)
                {
                    case 6 :
                    FilmBrowse(filmpoint->next);    //浏览影厅信息
                    break;
                    case 7 :
                    FilmSave(filmpoint);            //读取影厅信息
                    break;
                    case 8 :
                    filmpoint=FilmRead();           //读取影厅信息
                    break;
                    case 9 :
                    goto mainmenu;
                }
            }
            else
            {
                system("cls");
                printf("┌─────────────────┐\n");
                printf("│             没有权限!            │\n");
                printf("└─────────────────┘\n");
                Sleep(200);
                goto mainmenu;
            }
        }
        while(mainkey==8)           //订单管理系统
        {
            orderkey=OrderMenu();
            switch(orderkey)
            {
                case 6 :
                Order();                            //售票
                break;
                case 7 :
                // OrderDelete(orderpoint);            //删除订单信息
                // OrderSave(orderpoint);              //保存订单信息
                break;
                case 8 :
                OrderQuery(orderpoint);             //查询订单信息
                break;
                case 9 :
                OrderCount(filmpoint->next,orderpoint);             //统计订单信息
                break;
                case 10 :
                OrderSave(orderpoint);              //保存订单信息
                break;
                case 11 :
                orderpoint=OrderRead();             //读取订单信息
                break;
                case 12 :
                goto mainmenu;
                break;
            }
        }
        while(mainkey==9)           //用户管理系统
        {
            if(power==3)            //仅允许管理员权限
            {

                userkey=UserMenu();
                switch(userkey)
                {
                    case 6 :
                    Register();                     //注册用户
                    break;
                    case 7 :
                    UserBrowse(userpoint->next);    //浏览用户信息
                    break;
                    case 8 :
                    UserQuery(userpoint);           //查询用户信息
                    break;
                    case 9 :
                    UserModify(userpoint);          //修改用户信息
                    break;
                    case 10 :
                    UserDelete(userpoint);          //删除用户信息
                    break;
                    case 11 :
                    userpoint=UserSort(userpoint);  //排序用户信息
                    UserBrowse(userpoint->next);    //并显示
                    break;
                    case 12 :
                    UserSave(userpoint);            //保存用户信息
                    break;
                    case 13 :
                    userpoint=UserRead();           //读取用户信息
                    break;
                    case 14 :
                    goto mainmenu;
                }
            }
            else
            {
                system("cls");
                printf("┌─────────────────┐\n");
                printf("│             没有权限!            │\n");
                printf("└─────────────────┘\n");
                Sleep(200);
                goto mainmenu;
            }
        }
        while(mainkey==10)
        {
            goto flag;
        }
        while(mainkey==11)
        {
            system("cls");
            printf("┌┬────────────────┐\n");
            printf("├┼───────────────┐│\n");
            printf("││   感谢使用影院信息管理系统!  ││\n");
            printf("│└───────────────┼┤\n");
            printf("└────────────────┴┘\n");
            exit(0);
        }
    }
    getch();
    return 0;
}
