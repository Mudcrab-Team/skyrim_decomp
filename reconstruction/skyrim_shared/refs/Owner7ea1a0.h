// Source exposure: mixed (community headers and pinned-image analysis).
// Code origin: Stamped as a twin of matched 0x7ea200 (skyrim_shared/refs/FlameProjectile): source copied, names replaced by placeholders.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Owner7ea1a0: GUESS(low) STANDIN
#pragma once
#include "FlameProjectile.h"

class Owner7ea1a0 : public Projectile {
public:
 Owner7ea1a0(); virtual ~Owner7ea1a0(); virtual std::uint8_t Slot164() const;
 void LoadGame(BGSLoadFormBuffer*); void SaveGame(BGSSaveFormBuffer*);
 union { void* runtimeTimers; struct { std::uint32_t expirationTimer,coneAngle; } timers; };
};
static_assert(sizeof(Owner7ea1a0)==0x1E8,"AE flame projectile size");
