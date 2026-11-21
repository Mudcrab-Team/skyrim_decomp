// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: ActorMagicCaster; size 0x100
// one of 2 different PDB types sharing this name; the fullest
#pragma once

#include "BGSLoadGameSubBuffer.h"
#include "BSTEventSink_RE__BSAnimationGraphEvent_bc0d6f4d.h"
#include "CastingSource.h"
#include "MagicCaster_274caf29.h"
#include "NiPointer_RE__BGSArtObjectCloneTask_14a8fab7.h"
#include "NiPointer_RE__BSLight_c51dfae1.h"
#include "RefAttachTechniqueInput.h"
#include "SimpleAnimationGraphManagerHolder_cecaacf4.h"
struct Actor;
struct BGSArtObject;
struct NiNode_9cd97e9e;
struct ReferenceEffectController_aa59977e;
struct ActorMagicCaster {
    MagicCaster_274caf29 _base;
    SimpleAnimationGraphManagerHolder_cecaacf4 _base_SimpleAnimationGraphManagerHolder;
    BSTEventSink_RE__BSAnimationGraphEvent_bc0d6f4d _base_BSTEventSink_RE_BSAnimationGraphEvent_;
    RefAttachTechniqueInput castingArtData;
    NiPointer_RE__BGSArtObjectCloneTask_14a8fab7 cloneTask;
    Actor* actor;
    NiNode_9cd97e9e* magicNode;
    NiPointer_RE__BSLight_c51dfae1 light;
    unsigned char interruptHandler_raw[8];
    BGSLoadGameSubBuffer loadGameSubBuffer;
    BGSArtObject* castingArt;
    ReferenceEffectController_aa59977e* weaponEnchantmentController;
    float costCharged;
    CastingSource castingSource;
    unsigned char flags_raw[8];
};
static_assert(sizeof(ActorMagicCaster) == 256, "ActorMagicCaster layout differs from the PDB");
