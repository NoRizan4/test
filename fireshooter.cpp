#include "fireshooter.h"

//火焰弹发射器类函数实现
//构造
FireShooter::FireShooter(int x, int y, int FUpLeftX, int FUpLeftY, int Fwidth, int Fheight)
{
    //初始化成员变量
    mx = x, my = y;
    DefImgPath = QString(":/image/fireshooter.png");
    width = Fwidth, height = Fheight;
    UpLeftX = FUpLeftX, UpLeftY = FUpLeftY;

    Range = 230;                                //射程
    BullPath = QString(":/image/fireball.png");
    bwidth = 40, bheight = 40;                  //子弹大小
    attack = 120;                               //攻击力
    ExplRangeWidth = 90;                        //爆炸效果宽高
    ExplRangeHeight = ExplRangeWidth;
}
