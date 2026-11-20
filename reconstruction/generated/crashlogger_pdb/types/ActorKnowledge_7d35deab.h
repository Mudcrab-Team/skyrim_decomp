// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: ActorKnowledge; size 0x48
// one of 2 different PDB types sharing this name
#pragma once

#include "AITimeStamp.h"
#include "BSPointerHandle_RE__Actor_1a35f4b9.h"
#include "BSTArray_RE__NiPointer_RE__DetectionListener_42df8117.h"
#include "FIGHT_REACTION_b28408d6.h"
#include "FLAGS_d4eab9c4.h"
#include "NiPointer_RE__DetectionState_8e6127d4.h"
#include "NiRefObject.h"
struct ActorKnowledge_7d35deab {
    NiRefObject _base;
    BSPointerHandle_RE__Actor_1a35f4b9 owner;
    BSPointerHandle_RE__Actor_1a35f4b9 target;
    FIGHT_REACTION_b28408d6 factionFightReaction;
    AITimeStamp shouldAttackTargetTimeStamp;
    NiPointer_RE__DetectionState_8e6127d4 detectionState;
    BSTArray_RE__NiPointer_RE__DetectionListener_42df8117 listeners;
    FLAGS_d4eab9c4 flags;
    AITimeStamp detectionQueuedTimeStamp;
};
static_assert(sizeof(ActorKnowledge_7d35deab) == 72, "ActorKnowledge_7d35deab layout differs from the PDB");
