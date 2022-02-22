#pragma once

#include <stdint.h>

#include "MyTools.h"
#include "GameObject.h"
#include "Plane.h"
#include "Bomb.h"

using namespace MyTools;

class Visitor {
public:
    virtual void log(Plane* plane) = 0;
    virtual void log(Bomb* bomb) = 0;
};

class LogVisitor : public Visitor {
public:

    void log(Plane* plane) {
        WriteToLog(string(__FUNCTION__) + " was invoked");
        plane->GetDirection();
        plane->GetSpeed();
    }

    void log(Bomb* bomb) {
        WriteToLog(string(__FUNCTION__) + " was invoked");
        bomb->GetDirection();
        bomb->GetSpeed();
    }
};


