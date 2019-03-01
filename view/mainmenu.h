//============================================================================
// Name        : mainmenu.h
// Author      : lancer
// Version     : 2.1
// Copyright   : made by lancer
// Description : Cinema Management System in C, Ansi-style
//============================================================================

int MainMenu();

int MainMenu()
{
    int choose;
    system("cls");
    printf("┌────────────────────────────────┐\n");
    printf("│┌──────────────────────────────┐│\n");
    printf("││            主菜单            ││\n");
    printf("│└──────────────────────────────┘│\n");
    printf("│┌──────────────────────────────┐│\n");
    printf("││     [1]----影片管理系统      ││\n");
    printf("││     [2]----影厅管理系统      ││\n");
    printf("││     [3]----票务管理系统      ││\n");
    printf("││     [4]----用户管理系统      ││\n");
    printf("││     [5]----注销登录用户      ││\n");
    printf("││     [0]----退出管理系统      ││\n");
    printf("││                              ││\n");
    printf("││                              ││\n");
    printf("││                              ││\n");
    printf("│└──────────────────────────────┘│\n");
    printf("└────────────────────────────────┘\n");
    choose=Cursor(6,11,6,27,10,1);
    return choose;
}
