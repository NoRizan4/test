#ifndef SNOWMAN_H
#define SNOWMAN_H

#include "defcreatureparent.h"

//雪人类，继承防御塔父类
class Snowman : public DefCreatureParent
{
protected:
public:
    Snowman(int x, int y, int FUpLeftX, int FUpLeftY, int Fwidth = 45, int Fheight = 90);
};

#endif // SNOWMAN_H
