#pragma once

#include <vector>
#include <memory>
#include <utility>
#include <algorithm>
#include <iostream>

#include "DynamicObject.h"
#include "Visitor.h"
#include "DestroyableGroundObject.h"

class Observer;

class Bomb : public DynamicObject
{
protected:
    std::vector<std::shared_ptr<Observer>> _st_obj;

    vector<DestroyableGroundObject*> CheckDestoyableObjects(
    vector<DestroyableGroundObject*> vec, int16_t* score) {
        vector<DestroyableGroundObject*> vecDestoyableObjects = vec;
        const double size = GetWidth();
        const double size_2 = size / 2;
        for (size_t i = 0; i < vecDestoyableObjects.size(); i++)
        {
            const double x1 = GetX() - size_2;
            const double x2 = x1 + size;
            if (vecDestoyableObjects[i]->isInside(x1, x2))
            {
                score += vecDestoyableObjects[i]->GetScore();
                return vecDestoyableObjects;
            }
        }
    }

    void notify() {
        for (auto it = _st_obj.begin(); it != _st_obj.end(); ++it) {
            auto& observer = *it;
            if (observer) {
                observer->update(this);
            }
        }
    }
public:

	static const uint16_t BombCost = 10;

	void Draw() const override;

	void Accept(Visitor& v);
	
    void AddObserver(std::shared_ptr<Observer> observer) {
        if (observer) {
            _st_obj.push_back(std::move(observer));
        }
    }

    void detach(const std::vector<DestroyableGroundObject*>& observer) {
        auto it = std::find(_st_obj.begin(), _st_obj.end(), observer);
        if (it != _st_obj.end()) {
            _st_obj.erase(it);
        }
    }

    virtual int getState() const = 0;
};

class Observer {
public:
    virtual ~Observer() = default;
    virtual void update(Bomb* bomb) = 0;
};

class ConcreteBomb : public Bomb {
public:

    void setState(int state, int16_t* score) {
        state_ = state;
        if (state > 0) {
            notify();
            CheckDestoyableObjects(vec, score);
        }
    }

    int getState() const override {
        return state_;
    }

private:
    int16_t* score;
    int state_{};
    vector<DestroyableGroundObject*> vec;
};

class ConcreteObserver : public Observer {
public:
    void update(Bomb* bomb) override {
        auto state = bomb->getState();
    }
};