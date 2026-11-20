// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: ActorMagicCaster; size 0x100
// one of 2 different PDB types sharing this name
#pragma once

#include "BGSLoadGameSubBuffer.h"
#include "BSTEventSink_RE__BSAnimationGraphEvent_bc0d6f4d.h"
#include "CastingSource.h"
#include "MagicCaster.h"
#include "NiPointer_RE__BGSArtObjectCloneTask_14a8fab7.h"
#include "NiPointer_RE__BSLight_c51dfae1.h"
#include "RefAttachTechniqueInput_0f9ae65d.h"
#include "SimpleAnimationGraphManagerHolder.h"
struct Actor_b2630b95;
struct BGSArtObject_14762d66;
struct NiNode;
struct ReferenceEffectController;
struct ActorMagicCaster_e125139c {
    MagicCaster _base;
    SimpleAnimationGraphManagerHolder _base_SimpleAnimationGraphManagerHolder;
    BSTEventSink_RE__BSAnimationGraphEvent_bc0d6f4d _base_BSTEventSink_RE_BSAnimationGraphEvent_;
    RefAttachTechniqueInput_0f9ae65d castingArtData;
    NiPointer_RE__BGSArtObjectCloneTask_14a8fab7 cloneTask;
    Actor_b2630b95* actor;
    NiNode* magicNode;
    NiPointer_RE__BSLight_c51dfae1 light;
    unsigned char interruptHandler_raw[8];
    BGSLoadGameSubBuffer loadGameSubBuffer;
    BGSArtObject_14762d66* castingArt;
    ReferenceEffectController* weaponEnchantmentController;
    float costCharged;
    CastingSource castingSource;
    unsigned char flags_raw[8];
};
static_assert(sizeof(ActorMagicCaster_e125139c) == 256, "ActorMagicCaster_e125139c layout differs from the PDB");
