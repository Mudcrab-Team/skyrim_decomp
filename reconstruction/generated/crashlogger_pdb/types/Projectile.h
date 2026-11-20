// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: Projectile; size 0x1e0
#pragma once

#include "BSPointerHandle_RE__TESObjectREFR_017ae4a4.h"
#include "BSSimpleList_RE__Projectile__ImpactData_639fdce6.h"
#include "BSSoundHandle.h"
#include "BSSpinLock.h"
#include "NiPoint3.h"
#include "NiPointer_RE__ActorCause_e9deb8d0.h"
#include "NiPointer_RE__BSLight_c51dfae1.h"
#include "NiPointer_RE__QueuedFile_61648701.h"
#include "NiTransform.h"
#include "TESObjectREFR_b225f218.h"
struct BGSExplosion_c355258c;
struct EffectSetting_86f4824b;
struct InventoryEntryData_beab07a8;
struct MagicItem_34516af4;
struct TESAmmo;
struct TESObjectWEAP_335e104b;
struct bhkSimpleShapePhantom_6b53268d;
struct Projectile {
    TESObjectREFR_b225f218 _base;
    BSSimpleList_RE__Projectile__ImpactData_639fdce6 impacts;
    NiTransform unk0A8;
    float unk0DC;
    bhkSimpleShapePhantom_6b53268d* unk0E0;
    BSSpinLock unk0E8;
    NiPoint3 velocity;
    NiPoint3 linearVelocity;
    NiPointer_RE__BSLight_c51dfae1 light;
    void* unk110;
    NiPointer_RE__ActorCause_e9deb8d0 actorCause;
    BSPointerHandle_RE__TESObjectREFR_017ae4a4 shooter;
    BSPointerHandle_RE__TESObjectREFR_017ae4a4 desiredTarget;
    BSSoundHandle sndHandle;
    BSSoundHandle sndCountdown;
    unsigned int* unk140;
    InventoryEntryData_beab07a8* unk148;
    BGSExplosion_c355258c* explosion;
    MagicItem_34516af4* spell;
    unsigned int castingSource;
    unsigned int pad164;
    EffectSetting_86f4824b* avEffect;
    NiPointer_RE__QueuedFile_61648701 projectileDBFiles;
    unsigned char muzzleFlashDBHandle[8];
    unsigned long long unk180;
    float power;
    float speedMult;
    float range;
    float livingTime;
    float weaponDamage;
    float transparency;
    float explosionTimer;
    unsigned int unk1A4;
    float unk1A8;
    float unk1AC;
    TESObjectWEAP_335e104b* weaponSource;
    TESAmmo* ammoSource;
    float distanceMoved;
    float decidedDecalWidth;
    float scale;
    unsigned int flags;
    bool unk1D0;
    bool unk1D1;
    unsigned char unk1D2[6];
};
static_assert(sizeof(Projectile) == 480, "Projectile layout differs from the PDB");
