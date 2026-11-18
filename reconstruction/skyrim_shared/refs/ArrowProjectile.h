// Source exposure: mixed (names and declarations from community headers; base classes, sizes and
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Declarations derived from powerof3/CommonLibSSE are GPL-3.0 (its licence).
// ArrowProjectile: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT) EXE_RTTI
// Projectile, MissileProjectile, TESAmmo: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); padded to the offsets the compared code uses
// ArrowProjectile::ShouldBeLimited, ArrowProjectile::GetPowerSpeedMult, ArrowProjectile::Update3D, ArrowProjectile::GetWeaponSpeedMult, ArrowProjectile::GetGravity: COMMUNITY(powerof3/CommonLibSSE@654e55f, GPL-3.0)
// Projectile::ammoSource: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT) OBSERVED; NG declares it at 0x1B8, the same offset here
// Projectile::range: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT) OBSERVED; NG declares it at 0x190, the same offset here
// Projectile::flags: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT) OBSERVED; NG declares flags at 0x1CC, this build uses 0x1D4
// PrepareSpeedQuery, ComputeSpeedMult, ResolveAttachedNodes, GetBaseGravity, ScaleAmmoSpeed: GUESS(low)
// g_gravityOne: GUESS(low); a mutable global the compared GetGravity reads at 0x20a7478
// TESAmmo::unk170: GUESS(low)
#pragma once

#include <cstdint>
#include <cstddef>
#include "TESObjectREFR.h"

class TESAmmo
{
public:
    std::uint8_t unk00[0x170];  // 00
    float        unk170;        // 170
};

class Projectile : public TESObjectREFR
{
public:
    std::uint8_t unkBase[0x190 - sizeof(TESObjectREFR)];  // pads to range
    float        range;                                   // 190
    std::uint8_t unk194[0x1B8 - 0x194];                   // 194
    TESAmmo*     ammoSource;                              // 1B8
    std::uint8_t unk1C0[0x1D4 - 0x1C0];                   // 1C0
    std::uint32_t flags;                                  // 1D4
};

class MissileProjectile : public Projectile
{
public:
};

// Helpers the compared code calls; declared only, bound by RVA. The two speed helpers take no this
// pointer: the compared GetPowerSpeedMult does not keep this across its first call.
void  PrepareSpeedQuery();  // callee of GetPowerSpeedMult: 0x7fc000
float ComputeSpeedMult();  // tail callee of GetPowerSpeedMult: 0x41fb60
float ScaleAmmoSpeed(float a_speed);  // compared callee: 0x41fba0
extern float g_gravityOne;  // mutable constant read by GetGravity, bound by RVA

class ArrowProjectile : public MissileProjectile
{
public:
    virtual std::uint8_t Slot195() const;
    virtual bool ShouldBeLimited();  // compared: 0x7ddfe0
    virtual float GetPowerSpeedMult() const;  // compared: 0x7ddf80
    virtual void Update3D();  // compared: 0x7de0f0
    virtual float GetWeaponSpeedMult() const;  // compared: 0x7ddfa0
    virtual float GetGravity();  // compared: 0x7ddf40

    void ResolveAttachedNodes();  // tail callee of Update3D: 0x7faf50
    float GetBaseGravity();  // callee of GetGravity: 0x7fc640
};
