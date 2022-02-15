#pragma once

#include <vector>

#include "LevelGUI.h"
#include "Plane.h"
#include "Bomb.h"
#include "Ground.h"
#include "Tank.h"

class SBomber
{
public:

    SBomber();
    ~SBomber();
    
    inline bool GetExitFlag() const { return exitFlag; }

    void ProcessKBHit();
    void TimeStart();
    void TimeFinish();

    void DrawFrame();
    void MoveObjects();
    void CheckObjects();

    Plane* FindPlane() const;
    LevelGUI* FindLevelGUI() const;
    bool exitFlag;
    int16_t score;
    std::vector<Bomb*> FindAllBombs() const;
    Ground* FindGround() const;
    void __fastcall DeleteDynamicObj(DynamicObject* pBomb);
    std::vector<DestroyableGroundObject*> FindDestoyableGroundObjects() const;
    void __fastcall DeleteStaticObj(GameObject* pObj);

    /*virtual void CheckPlaneAndLevelGUI();
    virtual void CheckBombsAndGround();
    virtual void CheckDestoyableObjects(Bomb* pBomb);*/

private:
    void DropBomb();

    std::vector<DynamicObject*> vecDynamicObj;
    std::vector<GameObject*> vecStaticObj;

    uint64_t startTime, finishTime, passedTime;
    uint16_t bombsNumber, deltaTime, fps;
};

class CollisionDetector {
    SBomber bomber;
public:

    void CheckPlaneAndLevelGUI();
    void CheckBombsAndGround();
    void CheckDestoyableObjects(Bomb* pBomb);
};