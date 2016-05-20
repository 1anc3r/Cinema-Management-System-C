//============================================================================
// Name        : usermenu.h
// Author      : lancer
// Version     : 2.1
// Copyright   : made by lancer
// Description : Cinema Management System in C, Ansi-style
//============================================================================

int UserMenu();

int UserMenu()
{
    int choose;
    system("cls");
    printf("┌─────────────────┐\n");
    printf("│┌───────────────┐│\n");
    printf("││         用户管理系统         ││\n");
    printf("│└───────────────┘│\n");
    printf("│┌───────────────┐│\n");
    printf("││     [1]----录入用户信息      ││\n");
    printf("││     [2]----浏览用户信息      ││\n");
    printf("││     [3]----查询用户信息      ││\n");
    printf("││     [4]----修改用户信息      ││\n");
    printf("││     [5]----删除用户信息      ││\n");
    printf("││     [6]----排序用户信息      ││\n");
    printf("││     [7]----导出用户信息      ││\n");
    printf("││     [8]----导入用户信息      ││\n");
    printf("││     [0]----返回主菜单        ││\n");
    printf("│└───────────────┘│\n");
    printf("└─────────────────┘\n");
    choose=Cursor(6,14,8,29,14,1);
    return choose;
}
