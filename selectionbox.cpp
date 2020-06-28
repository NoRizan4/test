#include "selectionbox.h"

//构造
SelectionBox::SelectionBox(QString Path, int width, int height) :
    mwidth(width), mheight(height), SelecBoxImgPath(Path) {}

int SelectionBox::GetX() const
{
    return mx;
}
int SelectionBox::GetY() const
{
    return my;
}
int SelectionBox::Getwidth() const
{
    return mwidth;
}
int SelectionBox::Getheight() const
{
    return mheight;
}

QString SelectionBox::GetImgPath() const
{
    return SelecBoxImgPath;
}

//获取显示状态
bool SelectionBox::Getdisplay() const
{
    return display;
}

//设置显示状态
void SelectionBox::Setdisplay(const bool SetPlay)
{
    display = SetPlay;
}

//选中防御塔
void SelectionBox::CheckTow(int x, int y)
{
    //确定选择框的位置
    mx = x - 95, my = y - 95;

    //确定子按钮的位置
    SubBut[0].SubX = mx + 106, SubBut[0].SubY = my + 14;
    SubBut[0].SubImgPath = QString(":/image/Buysnowman.png");

    SubBut[1].SubX = mx + 14, SubBut[1].SubY = my + 106;
    SubBut[1].SubImgPath = QString(":/image/Buychicken.png");

    SubBut[2].SubX = mx + 202, SubBut[2].SubY = my + 106;
    SubBut[2].SubImgPath = QString(":/image/Buywitch.png");

    SubBut[3].SubX = mx + 106, SubBut[3].SubY = my + 190;
    SubBut[3].SubImgPath = QString(":/image/Buyshooter.png");

    display = true;
}

//获取子按钮结构数组
SubbutStr* SelectionBox::GetSelSubBut()
{
    return SubBut;
}
