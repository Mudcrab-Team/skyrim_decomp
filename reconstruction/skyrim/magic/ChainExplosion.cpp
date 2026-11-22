// Source exposure: mixed (community headers; the pinned image listing).
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Code origin: original; the listing and the community declarations only
// 0x64b630 ChainExplosion::Initialize
// Adapted bodies: none
// ChainExplosion::Initialize: COMMUNITY(powerof3/CommonLibSSE@654e55f7979c1733033d5dbef176e43827bac944, GPL-3.0)
// ChainExplosionInitGlobal, ChainExplosionInitTarget: GUESS(low); the global and callee the tail jump uses
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2-root-includes.json
#include "ChainExplosion.h"

extern void* ChainExplosionInitGlobal;
void ChainExplosionInitTarget(void* a_global, ChainExplosion* a_explosion);

void ChainExplosion::Initialize()
{
    ChainExplosionInitTarget(ChainExplosionInitGlobal, this);
}
