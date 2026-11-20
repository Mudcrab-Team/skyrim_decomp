// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: ActorKnowledge; size 0x48
// one of 2 different PDB types sharing this name; the fullest
#pragma once

#include "AITimeStamp.h"
#include "BSPointerHandle_RE__Actor_1a35f4b9.h"
#include "BSTArray_RE__NiPointer_RE__DetectionListener_42df8117_fe9f4dd2.h"
#include "FIGHT_REACTION.h"
#include "FLAGS.h"
#include "NiPointer_RE__DetectionState_8e6127d4.h"
#include "NiRefObject_f24a9221.h"
struct ActorKnowledge {
    NiRefObject_f24a9221 _base;
    BSPointerHandle_RE__Actor_1a35f4b9 owner;
    BSPointerHandle_RE__Actor_1a35f4b9 target;
    FIGHT_REACTION factionFightReaction;
    AITimeStamp shouldAttackTargetTimeStamp;
    NiPointer_RE__DetectionState_8e6127d4 detectionState;
    BSTArray_RE__NiPointer_RE__DetectionListener_42df8117_fe9f4dd2 listeners;
    FLAGS flags;
    AITimeStamp detectionQueuedTimeStamp;
};
static_assert(sizeof(ActorKnowledge) == 72, "ActorKnowledge layout differs from the PDB");
