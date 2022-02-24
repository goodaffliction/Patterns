
#include <iostream>

#include "Plane.h"
#include "MyTools.h"

using namespace std;
using namespace MyTools;

void Plane::Draw()
{
    /*MyTools::SetColor(CC_LightBlue);
    GotoXY(x, y);
    cout << "=========>";
    GotoXY(x - 2, y - 1);
    cout << "===";
    GotoXY(x + 3, y - 1);
    cout << "\\\\\\\\";
    GotoXY(x + 3, y + 1);
    cout << "////";*/
}

//ColorPLane==========================================

void ColorPlane::DrawBody()
{
    MyTools::SetColor(CC_Red);
    GotoXY(x, y);
    cout << "=========>";
}

void ColorPlane::DrawWings()
{
    GotoXY(x + 3, y - 1);
    cout << "\\\\\\\\";
    GotoXY(x + 3, y + 1);
    cout << "////";
}

void ColorPlane::DrawTrail()
{
    GotoXY(x - 2, y - 1);
    cout << "===";
}

void ColorPlane::Draw()
{
    DrawBody();
    DrawWings();
    DrawTrail();
}

//BigPLane==========================================
void BigPlane::DrawBody()
{
    MyTools::SetColor(CC_Red);
    GotoXY(x, y);
    cout << "XXXXXXXXXXXXXXXXXXX===>";
}

void BigPlane::DrawWings()
{
    GotoXY(x + 3, y - 1);
    cout << "\\\\\\\\\\\\";
    GotoXY(x + 3, y + 1);
    cout << "/////////////";
}

void BigPlane::DrawTrail()
{
    GotoXY(x - 7, y - 1);
    cout << ("\DDDDDD|");
}

void BigPlane::Draw()
{
    DrawBody();
    DrawWings();
    DrawTrail();
}
