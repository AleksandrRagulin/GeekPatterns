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

    //------------
    Plane* FindPlane() const;
    int16_t score;
private:

    void CheckPlaneAndLevelGUI();
    void CheckBombsAndGround();
    void __fastcall CheckDestoyableObjects(Bomb* pBomb);

    //void __fastcall DeleteDynamicObj(DynamicObject * pBomb);
    //void __fastcall DeleteStaticObj(GameObject* pObj);

    Ground * FindGround() const;
    //Plane * FindPlane() const;
    LevelGUI * FindLevelGUI() const;
    std::vector<DestroyableGroundObject*> FindDestoyableGroundObjects() const;
    std::vector<Bomb*> FindAllBombs() const;

    //void DropBomb();

    std::vector<DynamicObject*> vecDynamicObj;
    std::vector<GameObject*> vecStaticObj;
    
    bool exitFlag;

    uint64_t startTime, finishTime, passedTime;
    uint16_t bombsNumber, deltaTime, fps;
    //int16_t score;
};


class Command {
public:
    virtual ~Command() = default;
    virtual void execute() = 0;
    /*void __fastcall DeleteDynamicObj(DynamicObject* pBomb);
    void __fastcall DeleteStaticObj(GameObject* pObj);

    void DropBomb();

    std::vector<DynamicObject*> vecDynamicObj;
    std::vector<GameObject*> vecStaticObj;*/
};

class DeleteDynamicObjCommand: public Command {
public:
        DynamicObject* pObj;
        std::vector<DynamicObject*> vecDynamicObj;
        DeleteDynamicObjCommand(DynamicObject* _pObj, std::vector<DynamicObject*> _vecDynamicObj)
        :pObj(_pObj), vecDynamicObj(_vecDynamicObj) {}
    void execute();
};

class DeleteStaticObjCommand : public Command {
public:
        GameObject* pObj;
        std::vector<GameObject*> vecStaticObj;
    DeleteStaticObjCommand(GameObject* _pObj, std::vector<GameObject*> _vecStaticObj)
        :pObj(_pObj), vecStaticObj(_vecStaticObj){}
    void execute();
};

class DropBombCommand {
public:
        std::vector<DynamicObject*> vecDynamicObj;
        const Plane* pPlane;
        uint16_t bombsNumber;
    DropBombCommand(std::vector<DynamicObject*> _vecDynamicObj,
        const Plane* _pPlane, const uint16_t& _bombsNumber)
        :vecDynamicObj(_vecDynamicObj), pPlane(_pPlane),bombsNumber(_bombsNumber){}

    void execute();
};