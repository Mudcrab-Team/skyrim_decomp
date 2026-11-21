// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: ActiveEffect; size 0x90
// one of 2 different PDB types sharing this name
#pragma once

#include "ActiveEffectReferenceEffectController.h"
#include "BSPointerHandle_RE__Actor_1a35f4b9.h"
#include "BSSoundHandle.h"
#include "CastingSource.h"
#include "ConditionStatus.h"
#include "Flag_d5bcd2af.h"
#include "NiPointer_RE__NiNode_28171d5b.h"
struct ActiveEffect_vtbl_d36453dd;
struct Effect_7a93a98d;
struct MagicItem;
struct MagicTarget_764e0294;
struct RE__BSSimpleList_RE__ReferenceEffect_8138e9d1;
struct TESBoundObject;
struct ActiveEffect_7b2473e9 {
    ActiveEffect_vtbl_d36453dd* __vftable;
    ActiveEffectReferenceEffectController hitEffectController;
    BSSoundHandle persistentSound;
    BSPointerHandle_RE__Actor_1a35f4b9 caster;
    NiPointer_RE__NiNode_28171d5b sourceNode;
    MagicItem* spell;
    Effect_7a93a98d* effect;
    MagicTarget_764e0294* target;
    TESBoundObject* source;
    RE__BSSimpleList_RE__ReferenceEffect_8138e9d1* hitEffects;
    MagicItem* displacementSpell;
    float elapsedSeconds;
    float duration;
    float magnitude;
    Flag_d5bcd2af flags;
    ConditionStatus conditionStatus;
    unsigned short usUniqueID;
    unsigned short pad86;
    CastingSource castingSource;
    unsigned int pad8C;
};
static_assert(sizeof(ActiveEffect_7b2473e9) == 144, "ActiveEffect_7b2473e9 layout differs from the PDB");
