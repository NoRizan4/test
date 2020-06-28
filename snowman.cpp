#include "snowman.h"

//雪人类函数实现
//构造
Snowman::Snowman(int x, int y, int FUpLeftX, int FUpLeftY, int Fwidth, int Fheight)
{
    //初始化成员变量
    mx = x, my = y;
    DefImgPath = QString(":/image/snowman.png");
    width = Fwidth, height = Fheight;
    UpLeftX = FUpLeftX, UpLeftY = FUpLeftY;


    Range = 180;                            //射程
    BullPath = QString(":/image/snowball.png");
    bwidth = 40, bheight = 40;              //子弹大小
    attack = 65;                            //攻击
    ExplRangeWidth = 60;                    //爆炸效果宽高
    ExplRangeHeight = ExplRangeWidth;
}
