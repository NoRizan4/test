#ifndef MONSTER_H
#define MONSTER_H

#include <QVector>
#include <QString>
#include "globalstruct.h"   //坐标结构

//怪物类
class Monster
{
private:
    QVector<CoorStr*> Waypoint;  //存储怪物路径点数组
    int mx,my;                   //小怪坐标
    int mwidth,mheight;          //小怪宽高
    QString ImgPath;             //小怪图片路径
    int id;                      //小怪编号
    int health;                  //小怪生命值
    const int mspeed = 10;       //小怪每次刷新页面移动的像素距离

public:
    //参数：小怪初始坐标、小怪宽度、小怪图片路径、路径点数组、路径点的个数
    Monster(CoorStr **pointarr, int arrlength, int x, int y, int fid);
    bool mMove();            //小怪移动函数
    int GetX() const;       //获取横坐标
    int GetY() const;       //获取横坐标
    int Getwidth() const;   //获取宽
    int Getheight() const;  //获取高
    QString GetImgPath() const; //获取图片路径
    int Getid() const;      //获取编号
    int Gethealth() const;  //获取生命值
    void Sethealth(int);    //设置生命值
};

#endif // MONSTER_H
