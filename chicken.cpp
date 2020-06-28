#include "chicken.h"

//小鸡类函数实现
//构造
Chicken::Chicken(int x, int y, int FUpLeftX, int FUpLeftY, int Fwidth, int Fheight)
{
    //初始化成员变量
    mx = x, my = y;

    DefImgPath = QString(":/image/Chicken.png");
    width = Fwidth, height = Fheight;
    UpLeftX = FUpLeftX, UpLeftY = FUpLeftY;


    Range = 200;                            //射程
    BullPath = QString(":/image/egg.png");
    bwidth = 30, bheight = 30;              //子弹大小
    attack = 45;                            //攻击力
    ExplRangeWidth = 50;                    //爆炸效果宽高
    ExplRangeHeight = ExplRangeWidth;
}
