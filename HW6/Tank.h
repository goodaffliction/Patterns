#pragma once

#include <stdint.h>
#include <vector>
#include <iostream>
#include "DestroyableGroundObject.h"
#include "LevelGUI.h"
#include "MyTools.h"

using namespace MyTools;

class Mediator;

class Tank1 : public DestroyableGroundObject {
	virtual void sayMessage() = 0;
	static Mediator* pMediator;
};

class Mediator {
public:

	void Message(Tank1* pTank, LevelGUI* pGUI) {
		GotoXY(pTank->GetX(), pTank->GetY() + 10);
		std::cout << pGUI->Messages.front();
		pGUI->Messages.pop();
	};
};

class Tank : public Tank1
{
private:
	const uint16_t score = 30;
	Mediator* pMediator;
	LevelGUI* pGUI;
public:
	Tank(Mediator* pMed, LevelGUI* pG) : pMediator(pMed), pGUI(pG){ }

	bool __fastcall isInside(double x1, double x2) const override;

	inline uint16_t GetScore() const override { return score; }

	void Draw() override;
	
	void sayMessage() override {
		pMediator->Message(this, pGUI);
	};
};



