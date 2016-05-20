#ifndef _FUNC_H_
#define _FUNC_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <time.h>
#include <windows.h>

typedef struct date                 //放映
{
    int day;                        //日
    int month;                      //月
    int year;                       //年
    int openhour;                   //开场时
    int openmin;                    //开场分
    int closehour;                  //落幕时
    int closemin;                   //落幕分
    int hallnum;                    //影厅
    struct date *next;
}date;

typedef struct film                 //电影
{
    char filmname[22];              //片名
    double score;                   //评分
    double length;                  //片长
    double fare;                    //票价
    struct date *premiere;          //首映
    struct film *next;
}film;

typedef struct order
{
    int ordernum;                   //订单号
    int shit[2];                    //座位
    char filmname[22];              //片名
    double score;                   //评分
    double length;                  //片长
    double fare;                    //票价
    int day;                        //日
    int month;                      //月
    int year;                       //年
    int openhour;                   //开场时
    int openmin;                    //开场分
    int closehour;                  //落幕时
    int closemin;                   //落幕分
    int hallnum;                    //影厅
    struct order *next;
}order;

typedef struct user                 //用户
{
    char id[15];                    //账号
    char password[15];              //密码
    struct user *next;
    int power;                      //权限
}user;

#define FILMF "%s %lf %lf %lf\n"
#define TIMEF "%d %d %d %d %d %d %d %d\n"
#define ORDER "%d %d %d\n%s %lf %lf %lf\n%d %d %d %d %d %d %d\n"

int n=0,m=0,o=0;                    //电影用户订单数量
typedef  int (*ss)[14];             //座位文件操作参数
int s[6][14];                       //座位数组
char ch;
int line;
int choose;

#include "view/position.h"               //控制坐标
#include "view/cursor.h"
#include "user/newfile.h"
#include "film/filmsave.h"               //保存影片信息
#include "film/filmread.h"               //读取影片信息
#include "seat/seatsave.h"               //保存座位信息
#include "seat/seatread.h"               //读取座位信息
#include "user/usersave.h"               //保存用户信息
#include "user/userread.h"               //读取用户信息
#include "order/ordersave.h"             //保存订单信息
#include "order/orderread.h"             //读取订单信息
#include "hall/hallread.h"               //读取影厅信息
#include "user/login.h"                  //登录
#include "user/register.h"               //注册
#include "user/forget.h"                 //忘记密码
#include "user/setup.h"                  //登录系统
#include "view/mainmenu.h"               //主菜单
#include "view/filmmenu.h"               //影片管理菜单
#include "view/hallmenu.h"               //影厅管理菜单
#include "view/ordermenu.h"              //订单管理菜单
#include "view/usermenu.h"               //用户管理菜单
#include "view/hallview.h"
#include "film/filmenter.h"              //录入影片
#include "film/filmbrowse.h"             //浏览影片
#include "film/filmquery.h"              //查找影片
#include "film/filmmodify.h"             //修改影片
#include "film/filmdelete.h"             //删除影片
#include "film/filmsort.h"               //排序影片
#include "order/order.h"                 //售票
#include "order/orderquery.h"            //查询订单
#include "order/ordercount.h"            //统计订单
#include "order/orderdelete.h"            //删除订单
#include "user/userbrowse.h"             //浏览用户
#include "user/userquery.h"              //查询用户
#include "user/usermodify.h"             //修改用户
#include "user/userdelete.h"             //删除用户
#include "user/usersort.h"               //排序用户

#endif
