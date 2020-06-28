#ifndef WITCH_H
#define WITCH_H

#include "defcreatureparent.h"
//女巫类
class Witch : public DefCreatureParent
{
protected:

public:
    Witch(int x, int y, int FUpLeftX, int FUpLeftY, int Fwidth = 40, int Fheight = 100);
};

#endif // WITCH_H
