// Source exposure: mixed (community headers and pinned-image analysis).
// Code origin: original; the listing and community declarations only
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Adapted bodies: none
// 0x260a30 BGSExplosion::InitializeData
// 0x261660 BGSExplosion::~BGSExplosion
// 0x261270 BGSExplosion::UnClone3D
// 0x261290 BGSExplosion::GetRadius
// 0x2612d0 BGSExplosion::GetImageSpaceRadius
// BGSExplosion::GetRadius, BGSExplosion::GetImageSpaceRadius, g_explosionRadiusScale: GUESS(low); the radius scaled by a global unless data flag bit 0 is set
#include "BGSExplosion.h"

extern float g_explosionRadiusScale;

BGSExplosion::BGSExplosion() {}
BGSExplosion::~BGSExplosion() {}
void BGSExplosion::UnClone3D(TESObjectREFR* a_ref)
{
    const auto* explosion = static_cast<const Explosion*>(a_ref);
    // Explosion::Flags::kInWater is bit 5 of the flag word; the test takes the bit index.
    if (!TestBit(static_cast<std::uint32_t>(explosion->flags), 5)) {
        TESObject::UnClone3D(a_ref);
    }
}
void BGSExplosion::InitializeData() { data.soundLevel=1; data.light=nullptr; data.sound1=nullptr; data.sound2=nullptr; data.impactDataSet=nullptr; data.impactPlacedObject=nullptr; data.force=0; data.damage=0; data.radius=0; data.imageSpaceRadius=0; data.verticalOffsetMult=0; data.flags=0; data.spawnProjectile=nullptr; }

float BGSExplosion::GetRadius() const
{
    float radius = data.radius;
    if (!TestBit(data.flags, 0)) {
        radius *= g_explosionRadiusScale;
    }
    return radius;
}

float BGSExplosion::GetImageSpaceRadius() const
{
    float radius = data.imageSpaceRadius;
    if (!TestBit(data.flags, 0)) {
        radius *= g_explosionRadiusScale;
    }
    return radius;
}
