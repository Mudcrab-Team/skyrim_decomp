// Source exposure: mixed (community headers and pinned-image analysis).
// Drafted by gpt-6.1-sol, Engineer p105 box3. Adapted bodies: none.
// Code origin: original; the listing and community declarations only
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// 0x260a30 BGSExplosion::InitializeData
// 0x261660 BGSExplosion::~BGSExplosion
// 0x261270 BGSExplosion::UnClone3D
#include "BGSExplosion.h"
BGSExplosion::BGSExplosion() {}
BGSExplosion::~BGSExplosion() {}
void BGSExplosion::UnClone3D(TESObjectREFR* a_ref)
{
    const std::uint32_t flags = *reinterpret_cast<const std::uint32_t*>(reinterpret_cast<const char*>(a_ref) + 0x144);
    if (!TestBit(flags, 5)) {
        TESObject::UnClone3D(a_ref);
    }
}
void BGSExplosion::InitializeData() { data.soundLevel=1; data.light=nullptr; data.sound1=nullptr; data.sound2=nullptr; data.impactDataSet=nullptr; data.impactPlacedObject=nullptr; data.force=0; data.damage=0; data.radius=0; data.imageSpaceRadius=0; data.verticalOffsetMult=0; data.flags=0; data.spawnProjectile=nullptr; }

