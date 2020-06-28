#ifndef FIRESHOOTER_H
#define FIRESHOOTER_H

#include "defcreatureparent.h"

//火焰球发射器层类
class FireShooter : public DefCreatureParent
{
protected:

public:
    FireShooter(int x, int y, int FUpLeftX, int FUpLeftY, int Fwidth = 80, int Fheight = 80);
};

#endif // FIRESHOOTER_H
