// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: MovementControllerNPC; size 0x1d0
// one of 2 different PDB types sharing this name; the fullest
#pragma once

#include "BSSpinLock.h"
#include "BSTArray_RE__MovementMessage_ac0b5741.h"
#include "BSTArray_void_9eb8914c.h"
#include "IAnimationSetCallbackFunctor_d2f121fa.h"
#include "IMovementDirectControl.h"
#include "IMovementMessageInterface.h"
#include "IMovementMotionDrivenControl.h"
#include "IMovementPlannerDirectControl_dbc51d86.h"
#include "IMovementSelectIdle.h"
#include "MovementControllerAI_a0cb26ea.h"
struct Actor_b2630b95;
struct MovementControllerNPC {
    MovementControllerAI_a0cb26ea _base;
    IMovementMessageInterface _base_IMovementMessageInterface;
    IMovementMotionDrivenControl _base_IMovementMotionDrivenControl;
    IMovementSelectIdle _base_IMovementSelectIdle;
    IMovementDirectControl _base_IMovementDirectControl;
    IMovementPlannerDirectControl_dbc51d86 _base_IMovementPlannerDirectControl;
    IAnimationSetCallbackFunctor_d2f121fa _base_IAnimationSetCallbackFunctor;
    BSSpinLock unk150;
    BSTArray_RE__MovementMessage_ac0b5741 movementMessages;
    BSTArray_void_9eb8914c unk170;
    BSTArray_void_9eb8914c unk188;
    BSSpinLock unk1A0;
    unsigned long long unk1A8;
    unsigned long long unk1B0;
    Actor_b2630b95* actor;
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
static_assert(sizeof(MovementControllerNPC) == 464, "MovementControllerNPC layout differs from the PDB");
