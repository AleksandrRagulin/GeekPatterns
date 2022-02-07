#pragma once

#include <vector>

#include "LevelGUI.h"
#include "Plane.h"
#include "Bomb.h"
#include "Ground.h"
#include "Tank.h"
class LogVisitor :public Visitor {
public:
    virtual void log(Bomb* pBomb) {
        MyTools::WriteToLog("BombSpeed", pBomb->GetSpeed());
        MyTools::WriteToLog("BombX", pBomb->GetX());
        MyTools::WriteToLog("BombY", pBomb->GetY());
        MyTools::WriteToLog("BombDirX", pBomb->GetDirectionX());
        MyTools::WriteToLog("BombDirY", pBomb->GetDirectionY());

    };
    virtual void log(Plane* pPlane) {
        MyTools::WriteToLog("BombSpeed", pPlane->GetSpeed());
        MyTools::WriteToLog("BombX", pPlane->GetX());
        MyTools::WriteToLog("BombY", pPlane->GetY());
        MyTools::WriteToLog("BombDirX", pPlane->GetDirectionX());
        MyTools::WriteToLog("BombDirY", pPlane->GetDirectionY());
    };
};

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
    //-----
    LogVisitor logVis;
    //-----
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