//============================================================================
// Name        : filmmenu.h
// Author      : lancer
// Version     : 2.1
// Copyright   : made by lancer
// Description : Cinema Management System in C, Ansi-style
//============================================================================

int FilmMenu();

int FilmMenu()
{
    int choose;
    system("cls");
    printf("┌─────────────────┐\n");
    printf("│┌───────────────┐│\n");
    printf("││         影片管理系统         ││\n");
    printf("│└───────────────┘│\n");
    printf("│┌───────────────┐│\n");
    printf("││     [1]----录入影片信息      ││\n");
    printf("││     [2]----浏览影片信息      ││\n");
    printf("││     [3]----查询影片信息      ││\n");
    printf("││     [4]----修改影片信息      ││\n");
    printf("││     [5]----删除影片信息      ││\n");
    printf("││     [6]----排序影片信息      ││\n");
    printf("││     [7]----导出影片信息      ││\n");
    printf("││     [8]----导入影片信息      ││\n");
    printf("││     [0]----返回主菜单        ││\n");
    printf("│└───────────────┘│\n");
    printf("└─────────────────┘\n");
    choose=Cursor(6,14,8,29,14,1);
    return choose;
}
