#include "defcreatureparent.h"

int DefCreatureParent::GetX() const
{
    return mx;
}

int DefCreatureParent::GetY() const
{
    return my;
}

int DefCreatureParent::Getwidth() const
{
    return width;
}

int DefCreatureParent::Getheight() const
{
    return height;
}

int DefCreatureParent::GetRotatAngle() const
{
    return RotatAngle;
}

QString DefCreatureParent::GetDefImgPath() const
{
    return DefImgPath;
}

int DefCreatureParent::GetUpLeftX() const
{
    return UpLeftX;
}

int DefCreatureParent::GetUpLeftY() const
{
    return UpLeftY;
}

void DefCreatureParent::SetRotatAngle(int rot)
{
    RotatAngle = rot;
}

int DefCreatureParent::Getrange() const
{
    return Range;
}

Monster* DefCreatureParent::GetAimsMonster() const
{
    return aimsmon;
}

void DefCreatureParent::SetAimsMonster(Monster* mon)
{
    aimsmon = mon;
}

QString DefCreatureParent::GetBulletPath() const
{
    return BullPath;
}

QVector<BulletStr*>& DefCreatureParent::GetBulletVec()
{
    return BulletVec;
}

void DefCreatureParent::InterBullet()     //新建子弹函数
{
    counter++;

    if(counter < 7 || !aimsmon)      //计数器到达一定数值且目标怪物不为空时
        return;

    //向子弹数组中插入子弹
    BulletStr *bull = new BulletStr(CoorStr(UpLeftX + 40, UpLeftY + 40));

    bull->coor.x = UpLeftX + 40, bull->coor.y = UpLeftY + 40;

    //计算每一个子弹的路径
    if((!(aimsmon->GetX() - bull->coor.x)))
    {
        delete bull;
        bull = NULL;
        goto L1;
    }

    bull->k = (aimsmon->GetY() - bull->coor.y) / (aimsmon->GetX() - bull->coor.x);
    bull->b = aimsmon->GetY() - aimsmon->GetX() * bull->k;

    bull->coor.x = UpLeftX + 40, bull->coor.y = UpLeftY + 40;

    BulletVec.push_back(bull);              //将子弹插入到子弹数组当中

    if(aimsmon->GetX() <= UpLeftX + 40)     //确定子弹的移动方向
        bull->dirflag = true;
    L1:

    counter = 0;    //计数器重置为0

}

void DefCreatureParent::BulletMove()         //子弹移动函数
{
    for(auto bulli : BulletVec)
    {
        const int speed = 25;     //子弹移动速度，每一次刷新画面移动的像素距离

        //子弹的移动方向
        bulli->dirflag ? bulli->coor.x -= speed : bulli->coor.x += speed;
        bulli->coor.y = bulli->k * bulli->coor.x + bulli->b;
    }

    for(auto bullit = BulletVec.begin(); bullit != BulletVec.end(); bullit++)         //遍历删除越界子弹
        if((*bullit)->coor.x > 1040 || (*bullit)->coor.x < 0 || (*bullit)->coor.y > 640 || (*bullit)->coor.y < 0)
        {
            delete bullit;
            BulletVec.erase(bullit);
            break;
        }
}

int DefCreatureParent::GetBulletWidth() const
{
    return bwidth;
}

int DefCreatureParent::GetBulletHeight() const
{
    return bheight;
}

int DefCreatureParent::Getattack() const
{
    return attack;
}

void DefCreatureParent::Setattack(int attack)
{
    this->attack = attack;
}

void DefCreatureParent::Setwidthheight(int width, int height)
{
    this->width = width, this->height = height;
}

void DefCreatureParent::SetXY(int x, int y)
{
    this->mx = x, this->my = y;
}

int& DefCreatureParent::Setrange()
{
    return Range;
}

int DefCreatureParent::GetExplRangeWidth() const
{
    return ExplRangeWidth;
}

int DefCreatureParent::GetExplRangeHeight() const
{
    return ExplRangeHeight;
}

void DefCreatureParent::SetExplRangeWidthHeight(int width, int height)
{
    ExplRangeWidth = width, ExplRangeHeight = height;
}

void DefCreatureParent::SetBulletWidthHeight(int width, int height)
{
    bwidth = width, bheight = height;
}
