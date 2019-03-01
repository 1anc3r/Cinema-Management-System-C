//============================================================================
// Name        : hallmenu.h
// Author      : lancer
// Version     : 2.1
// Copyright   : made by lancer
// Description : Cinema Management System in C, Ansi-style
//============================================================================

int HallMenu();

int HallMenu()
{
    int choose;
    system("cls");
    printf("┌────────────────────────────────┐\n");
    printf("│┌──────────────────────────────┐│\n");
    printf("││         影厅管理系统         ││\n");
    printf("│└──────────────────────────────┘│\n");
    printf("│┌──────────────────────────────┐│\n");
    printf("││     [1]----浏览影厅信息      ││\n");
    printf("││     [2]----导出影厅信息      ││\n");
    printf("││     [3]----导入影厅信息      ││\n");
    printf("││     [0]----返回主菜单        ││\n");
    printf("││                              ││\n");
    printf("││                              ││\n");
    printf("││                              ││\n");
    printf("││                              ││\n");
    printf("││                              ││\n");
    printf("│└──────────────────────────────┘│\n");
    printf("└────────────────────────────────┘\n");
    choose=Cursor(6,9,6,27,9,1);
    return choose;
}
