// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: ActiveEffect; size 0x90
// one of 2 different PDB types sharing this name; the fullest
#pragma once

#include "ActiveEffectReferenceEffectController_d7a8df37.h"
#include "BSPointerHandle_RE__Actor_1a35f4b9.h"
#include "BSSoundHandle.h"
#include "CastingSource.h"
#include "ConditionStatus.h"
#include "Flag_a4a94b8a.h"
#include "NiPointer_RE__NiNode_28171d5b.h"
struct ActiveEffect_vtbl;
struct Effect;
struct MagicItem_34516af4;
struct MagicTarget;
struct RE__BSSimpleList_RE__ReferenceEffect_8138e9d1;
struct TESBoundObject_fc790793;
struct ActiveEffect {
    ActiveEffect_vtbl* __vftable;
    ActiveEffectReferenceEffectController_d7a8df37 hitEffectController;
    BSSoundHandle persistentSound;
    BSPointerHandle_RE__Actor_1a35f4b9 caster;
    NiPointer_RE__NiNode_28171d5b sourceNode;
    MagicItem_34516af4* spell;
    Effect* effect;
    MagicTarget* target;
    TESBoundObject_fc790793* source;
    RE__BSSimpleList_RE__ReferenceEffect_8138e9d1* hitEffects;
    MagicItem_34516af4* displacementSpell;
    float elapsedSeconds;
    float duration;
    float magnitude;
    Flag_a4a94b8a flags;
    ConditionStatus conditionStatus;
    unsigned short usUniqueID;
    unsigned short pad86;
    CastingSource castingSource;
    unsigned int pad8C;
};
static_assert(sizeof(ActiveEffect) == 144, "ActiveEffect layout differs from the PDB");
