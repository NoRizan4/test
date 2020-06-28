#include "witch.h"

//女巫函数实现
Witch::Witch(int x, int y, int FUpLeftX, int FUpLeftY, int Fwidth, int Fheight)
{
    //初始化成员变量
    mx = x, my = y;
    DefImgPath = QString(":/image/witch.png");
    width = Fwidth, height = Fheight;
    UpLeftX = FUpLeftX, UpLeftY = FUpLeftY;

    Range = 150;                                //射程
    BullPath = QString(":/image/bottle.png");
    bwidth = 40, bheight = 40;                  //子弹大小
    attack = 80;                                //攻击
    ExplRangeWidth = 100;                        //爆炸效果宽高
    ExplRangeHeight = ExplRangeWidth;
}
