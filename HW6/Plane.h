#pragma once

#include "DynamicObject.h"

class Plane : public DynamicObject {
public:

    void Draw() override;

    virtual void DrawBody() = 0;
    virtual void DrawWings() = 0;
    virtual void DrawTrail() = 0;

    inline void ChangePlaneY(double dy) { yDirection += dy; }

private:

};

class ColorPlane : public Plane {
public:
    
    void DrawBody() override;
    void DrawWings() override;
    void DrawTrail() override;
    void Draw() override;
};

class BigPlane : public Plane {
public:
    void DrawBody() override;
    void DrawWings() override;
    void DrawTrail() override;
    void Draw() override;
};