#pragma once
#include <iostream>
#include <stdint.h>

#include "DestroyableGroundObject.h"
#include <vector>

class HouseBuilderA;

class House : public DestroyableGroundObject
{
public:

	bool __fastcall isInside(double x1, double x2) const override;

	inline uint16_t GetScore() const override { return score; }

	void Draw() const override;

	friend HouseBuilderA;

private:

	const uint16_t score = 40;

	char look[7][14];
};

class HouseBuilderA : public House {
public:
	void Draw() const override;
};

class HouseBuilderB : public House {
public:
	void Draw() const override;
};

class HouseBuilder {
protected:
	std::vector<GameObject*> vecStaticObj;
	House* house;
	HouseBuilderA* HouseA;
	HouseBuilderB* HouseB;
public:
	HouseBuilder(std::vector<GameObject*> _vecStaticObj, House* _house, 
		HouseBuilderA* _houseA, HouseBuilderB* _houseB) : vecStaticObj(_vecStaticObj), 
		house(_house), HouseA(_houseA), HouseB(_houseB){}

	virtual void buildYellowHouse() { house->Draw(); }
	virtual void buildBlueHouse() { HouseA->Draw(); }
	virtual void buildGreenHouse() { HouseB->Draw(); }
	virtual std::vector<GameObject*> getHouse() {return vecStaticObj;}
};

class Director {
	int color;
public:
	std::vector<GameObject*> createHouse(HouseBuilder& builder) {
		std::cout << "What color of house do you want? 1 - Blue. 2 - Green. 3 - Yellow." << std::endl;
		std::cin >> color;

		switch (color) {
		case 1:
			builder.buildBlueHouse();
			break;
		case 2:
			builder.buildGreenHouse();
			break;
		case 3:
			builder.buildYellowHouse();
			break;
		default:
			return (builder.getHouse());
			break;
		}
	}
};