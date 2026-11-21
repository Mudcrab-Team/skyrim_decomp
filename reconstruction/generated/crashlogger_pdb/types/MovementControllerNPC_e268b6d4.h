// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: MovementControllerNPC; size 0x1d0
// one of 2 different PDB types sharing this name
#pragma once

#include "BSSpinLock.h"
#include "BSTArray_RE__MovementMessage_ac0b5741_d03864fa.h"
#include "BSTArray_void_9eb8914c_e1846db0.h"
#include "IAnimationSetCallbackFunctor.h"
#include "IMovementDirectControl_98f9af9d.h"
#include "IMovementMessageInterface_7e33d72e.h"
#include "IMovementMotionDrivenControl_e6312deb.h"
#include "IMovementPlannerDirectControl.h"
#include "IMovementSelectIdle_7e59d0ee.h"
#include "MovementControllerAI.h"
struct Actor;
struct MovementControllerNPC_e268b6d4 {
    MovementControllerAI _base;
    IMovementMessageInterface_7e33d72e _base_IMovementMessageInterface;
    IMovementMotionDrivenControl_e6312deb _base_IMovementMotionDrivenControl;
    IMovementSelectIdle_7e59d0ee _base_IMovementSelectIdle;
    IMovementDirectControl_98f9af9d _base_IMovementDirectControl;
    IMovementPlannerDirectControl _base_IMovementPlannerDirectControl;
    IAnimationSetCallbackFunctor _base_IAnimationSetCallbackFunctor;
    BSSpinLock unk150;
    BSTArray_RE__MovementMessage_ac0b5741_d03864fa movementMessages;
    BSTArray_void_9eb8914c_e1846db0 unk170;
    BSTArray_void_9eb8914c_e1846db0 unk188;
    BSSpinLock unk1A0;
    unsigned long long unk1A8;
    unsigned long long unk1B0;
    Actor* actor;
    unsigned int unk1C0;
    bool unk1C4;
    bool controlsDriven;
    bool unk1C6;
    bool unk1C7;
    bool unk1C8;
    bool unk1C9;
    bool unk1CA;
    bool unk1CB;
    unsigned int unk1CC;
};
static_assert(sizeof(MovementControllerNPC_e268b6d4) == 464, "MovementControllerNPC_e268b6d4 layout differs from the PDB");
