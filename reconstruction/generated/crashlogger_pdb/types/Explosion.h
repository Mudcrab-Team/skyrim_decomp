// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: Explosion; size 0x148
#pragma once

#include "BSPointerHandle_RE__Actor_1a35f4b9.h"
#include "BSSoundHandle.h"
#include "Flags_fa7f7281.h"
#include "NiPoint3.h"
#include "NiPointer_RE__ActorCause_e9deb8d0.h"
#include "NiPointer_RE__NiPointLight_bbb651a3.h"
#include "RHandleType_RE__BSResource__Entry_RE__NiPointer_RE__NiNode_RE__BSResource__EntryDBTrait_03dfb265.h"
#include "TESObjectREFR_b225f218.h"
struct NonActorMagicCaster;
struct TESObjectWEAP_335e104b;
struct bhkSimpleShapePhantom_6b53268d;
struct Explosion {
    TESObjectREFR_b225f218 _base;
    RHandleType_RE__BSResource__Entry_RE__NiPointer_RE__NiNode_RE__BSResource__EntryDBTrait_03dfb265 explosionDBHandle;
    float age;
    float lifetime;
    float hitTime;
    float radius;
    float imodRadius;
    float unkB4;
    bhkSimpleShapePhantom_6b53268d* unkB8;
    unsigned long long unkC0;
    unsigned long long unkC8;
    BSSoundHandle sound01;
    BSSoundHandle sound02;
    NiPointer_RE__NiPointLight_bbb651a3 light;
    BSPointerHandle_RE__Actor_1a35f4b9 actorOwner;
    BSPointerHandle_RE__Actor_1a35f4b9 unkF4;
    unsigned int unkF8;
    unsigned int padFC;
    NiPointer_RE__ActorCause_e9deb8d0 actorCause;
    NonActorMagicCaster* magicCaster;
    TESObjectWEAP_335e104b* weaponSource;
    unsigned int frameCount;
    NiPoint3 unk11C;
    NiPoint3 negativeVelocity;
    float damage;
    float unk138;
    Flags_fa7f7281 flags;
};
static_assert(sizeof(Explosion) == 328, "Explosion layout differs from the PDB");
