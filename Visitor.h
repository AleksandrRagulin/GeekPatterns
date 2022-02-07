#pragma once
#include "MyTools.h"
//---------
class Bomb;
class Plane;
class Visitor {
public:
    virtual void log(Bomb* pBomb) = 0;
    virtual void log(Plane* pPlane) = 0;
};


//--------------------
