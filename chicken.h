#ifndef CHICKEN_H
#define CHICKEN_H

#include "defcreatureparent.h"

//小鸡类，继承防御塔父类
class Chicken : public DefCreatureParent
{
protected:

public:
    Chicken(int x, int y, int FUpLeftX, int FUpLeftY, int Fwidth = 80, int Fheight = 80);
};

#endif // CHICKEN_H
