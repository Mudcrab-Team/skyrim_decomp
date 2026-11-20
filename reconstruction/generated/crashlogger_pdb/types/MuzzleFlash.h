// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: MuzzleFlash; size 0x40
#pragma once

#include "BSPointerHandle_RE__Actor_1a35f4b9.h"
#include "NiPointer_RE__NiAVObject_9e3aa701.h"
#include "NiPointer_RE__NiPointLight_bbb651a3.h"
struct BGSProjectile_dfe2d43e;
struct TESObjectWEAP_335e104b;
struct MuzzleFlash {
    bool enabled;
    bool mpsEnabled;
    bool updateLight;
    bool unk03;
    float enableTimer;
    float muzzleFlashDuration;
    unsigned int unk0C;
    NiPointer_RE__NiAVObject_9e3aa701 projectile3D;
    NiPointer_RE__NiAVObject_9e3aa701 projectileNode;
    NiPointer_RE__NiPointLight_bbb651a3 attachedLight;
    BGSProjectile_dfe2d43e* baseProjectile;
    TESObjectWEAP_335e104b* weaponSource;
    BSPointerHandle_RE__Actor_1a35f4b9 shooterHandle;
    unsigned int unk3C;
};
static_assert(sizeof(MuzzleFlash) == 64, "MuzzleFlash layout differs from the PDB");
