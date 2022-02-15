#include <iostream>

#include "TankAdaptee.h"
#include "MyTools.h"

using namespace std;
using namespace MyTools;

void TankAdaptee::Paint () const
{
	MyTools::SetColor(CC_DarkGray);
	GotoXY(x, y - 3);
	cout << "    (####)";
	GotoXY(x - 2, y - 2);
	cout << "o=======   )";
	GotoXY(x, y - 1);
	cout << "    |=====|";
	GotoXY(x, y);
	cout << " (OOOOOOOOOOOOO)";
}

bool TankAdaptee::isInRange(double x1, double x2) const
{
	const double XBeg = x + 2;
	const double XEnd = x + width - 1;

	if (x1 < XBeg && x2 > XEnd)
	{
		return true;
	}

	if (x1 > XBeg && x1 < XEnd)
	{
		return true;
	}

	if (x2 > XBeg && x2 < XEnd)
	{
		return true;
	}

	return false;
}