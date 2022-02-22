#pragma once

#include "MyTools.h"
#include "DynamicObject.h"

using namespace MyTools;

class Visitor {
public:
    virtual void log(DynamicObject* dyn_obj) = 0;
};

class LogVisitor : public Visitor {
public:

    void log(DynamicObject* dyn_obj) {
        WriteToLog(std::string(__FUNCTION__) + " was invoked", dyn_obj->GetDirection().first);
        WriteToLog(std::string(__FUNCTION__) + " was invoked", dyn_obj->GetDirection().second);
        WriteToLog(std::string(__FUNCTION__) + " was invoked", dyn_obj->GetSpeed());
    }
};