// Source exposure: mixed (names and declarations from community headers; base classes, sizes and
// Code origin: Stamped as a twin of matched 0x7ddf80 (skyrim_shared/refs/ArrowProjectile): source copied, names replaced by placeholders.
// the compared functions from the pinned image).
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Declarations derived from powerof3/CommonLibSSE are GPL-3.0 (its licence).
// Owner6e5bd0: GUESS(low) STANDIN
// MissileProjectile, ResolveAttachedNodes, GetBaseGravity: GUESS(low) STANDIN
#pragma once
#include "ArrowProjectile.h"

class Owner6e5bd0 : public MissileProjectile
{
public:
    virtual std::uint8_t Slot195() const;
    virtual bool ShouldBeLimited();
    virtual float GetPowerSpeedMult() const;
    virtual void Update3D();
    virtual float GetWeaponSpeedMult() const;
    virtual float GetGravity();

    void ResolveAttachedNodes();  // tail callee of Update3D: 0x7faf50
    float GetBaseGravity();  // callee of GetGravity: 0x7fc640
};
