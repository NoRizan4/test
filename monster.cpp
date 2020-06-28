#include "monster.h"
#include <QDebug>
//小怪类函数实现

Monster::Monster(CoorStr **pointarr, int arrlength, int x, int y, int fid): mx(x), my(y), id(fid)
{
    for( int i = 0; i < arrlength; i++ )      //将传进来的数组插入到Waypoint动态数组
        Waypoint.push_back(pointarr[i]);


    //不同小怪的相关信息
    switch (id)
    {
    case 1: //僵尸
        health = 100;   //生命值
        mwidth = 64, mheight = 64;  //大小
        ImgPath = ":/image/Zombie.png";
        break;
    case 2: //凋灵骷髅
        health = 120;
        mwidth = 64, mheight = 64;
        ImgPath = ":/image/WitheSkeleton.png";
        break;
    case 3: //岩浆史莱姆
        health = 600;
        mwidth = 64, mheight = 64;
        ImgPath = ":/image/YJG.png";
        break;
    case 4: //末影人
        health = 300;
        mwidth = 64, mheight = 64;
        ImgPath = ":/image/Endman.png";
        break;
    case 5: //古力怕
        health = 240;
        mwidth = 64, mheight = 64;
        ImgPath = ":/image/creeper.png";
        break;
    default:
        break;
    }
}

//小怪按设定路径点移动
bool Monster::mMove()
{
    if(Waypoint.empty()) return true;

    //如果第一个路径点的y小于小怪原本的路径点，则向下走
    if (Waypoint.at(0)->y<my) //上
    {
        my -= mspeed;
        return false;
    }

    if (Waypoint.at(0)->y>my) //下
    {
        my += mspeed;
        return false;
    }

    if (Waypoint.at(0)->x<mx) //左
    {
        mx -= mspeed;
        return false;
    }

    if (Waypoint.at(0)->x>mx) //右
    {
        mx += mspeed;
        return false;
    }



    //若小怪的坐标和路径点坐标几乎重合，那么删除这个路径点
    if (Waypoint.at(0)->y == my && Waypoint.at(0)->x == mx)
    {             
        Waypoint.erase(Waypoint.begin());       //从数组中删除
    }

    return false;
}


int Monster::GetX() const
{
    return mx;
}

int Monster::GetY() const
{
    return my;
}

int Monster::Getwidth() const
{
    return mwidth;
}

int Monster::Getheight() const
{
    return mheight;
}

QString Monster::GetImgPath() const
{
    return ImgPath;
}

int Monster::Getid() const
{
    return id;
}

int Monster::Gethealth() const
{
    return health;
}

void Monster::Sethealth(int thealth)
{
    health = thealth;
}

