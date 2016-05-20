//============================================================================
// Name        : ordermenu.h
// Author      : lancer
// Version     : 2.1
// Copyright   : made by lancer
// Description : Cinema Management System in C, Ansi-style
//============================================================================

int OrderMenu();

int OrderMenu()
{
    int choose;
    system("cls");
    printf("┌─────────────────┐\n");
    printf("│┌───────────────┐│\n");
    printf("││         票务管理系统         ││\n");
    printf("│└───────────────┘│\n");
    printf("│┌───────────────┐│\n");
    printf("││     [1]----售票服务窗口      ││\n");
    printf("││     [2]----退票服务窗口      ││\n");
    printf("││     [3]----查询票务信息      ││\n");
    printf("││     [4]----统计票务信息      ││\n");
    printf("││     [5]----导出票务信息      ││\n");
    printf("││     [6]----导入票务信息      ││\n");
    printf("││     [0]----返回主菜单        ││\n");
    printf("││                              ││\n");
    printf("││                              ││\n");
    printf("│└───────────────┘│\n");
    printf("└─────────────────┘\n");
    choose=Cursor(6,12,8,29,12,1);
    return choose;
}
