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

private:

    void CheckPlaneAndLevelGUI();
    void CheckBombsAndGround();
    void __fastcall CheckDestoyableObjects(Bomb* pBomb);

    void __fastcall DeleteDynamicObj(DynamicObject * pBomb);
    void __fastcall DeleteStaticObj(GameObject* pObj);

    Ground * FindGround() const;
    Plane * FindPlane() const;
    LevelGUI * FindLevelGUI() const;
    std::vector<DestroyableGroundObject*> FindDestoyableGroundObjects() const;
    std::vector<Bomb*> FindAllBombs() const;

    void DropBomb();

    std::vector<DynamicObject*> vecDynamicObj;
    std::vector<GameObject*> vecStaticObj;
    
    bool exitFlag;

    uint64_t startTime, finishTime, passedTime;
    uint16_t bombsNumber, deltaTime, fps;
    int16_t score;
};

class BombArr {
    std::vector<Bomb*> arr;

public:

    void push_back(Bomb* bomb) { arr.push_back(bomb); }
    void clear() { arr.clear(); }
    std::vector<Bomb*> operator*() { return arr; }

    class BombIterator {
        std::vector<Bomb*> bombArr;
        int curIndex;
        int* ptr;

    public:
        BombIterator(std::vector<Bomb*>& refBomb) : bombArr(refBomb), curIndex(-1), ptr(nullptr) { ++(*this); };

        void reset() { curIndex = -1; ptr = nullptr; }


        BombIterator& operator++ () {
            curIndex++;

            if (curIndex == -1)
                curIndex = 0;

            if (curIndex == bombArr.size()) {
                curIndex = -1;
                ptr = nullptr;
            }

            return *this;
        }

        BombIterator& operator-- () {
            if (curIndex == -1)
                curIndex = bombArr.size() - 1;

            if (curIndex == -1)
                ptr = nullptr;

            return *this;
        }

        Bomb* operator*() {
            return bombArr.at(curIndex);
        }

        bool operator==(BombIterator it)
        {
            if (curIndex == it.curIndex &&
                ptr == it.ptr &&
                bombArr == it.bombArr) {
                return true;
            }
            return false;
        }

        bool operator!=(BombIterator it) {
            return !(*this == it);
        }

    };

    BombIterator begin() { BombIterator it(arr); return it; }
    BombIterator end() { BombIterator it(arr); it.reset(); return it; }

    std::vector<Bomb*> FindBombs(std::vector<DynamicObject*> vecDynObj) {
        BombArr vecBombs;
        for (int i = 0; i < vecDynObj.size(); i++) {
            Bomb* pBomb = dynamic_cast<Bomb*>(vecDynObj[i]);
            if (pBomb != nullptr) {
                vecBombs.push_back(pBomb);
            }
        }
    }
};

