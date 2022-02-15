#pragma once

#include <stdint.h>

#include "DestroyableGroundObject.h"

class TankAdaptee {
public:

	TankAdaptee() : x(0.0), y(0.0), width(0) { }

	void Paint() const;
	bool isInRange(double x1, double x2) const;

	inline uint16_t GetScore() const { return score; }

	inline void SetPos(double nx, double ny) { x = nx; y = ny; }
	inline double GetY() const { return y; }
	inline double GetX() const { return x; }

	inline void SetWidth(uint16_t widthN) { width = widthN; }
	inline uint16_t GetWidth() const { return width; }

protected:

	double x, y;
	uint16_t width;
	const uint16_t score = 30;
};

class TankAdapter : public DestroyableGroundObject {
	TankAdaptee tank;

public:

	uint16_t GetScore() const { return tank.GetScore(); }
	void SetPos(double nx, double ny) { tank.SetPos(nx, ny); }
	double GetY() const { return tank.GetX(); }
	double GetX() const { return tank.GetY(); }
	void SetWidth(uint16_t widthN) { tank.SetWidth(widthN); }
	uint16_t GetWidth() const { return tank.GetWidth(); }

	void Draw() const { tank.Paint(); }
	bool isInside(double x1, double x2) const { return tank.isInRange(x1, x2); }

};