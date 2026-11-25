// Source exposure: mixed (community headers; the pinned image listing).
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Code origin: original; the listing and the community declarations only Stamped as a twin of matched 0x64b630 (skyrim/magic/ChainExplosion): source copied, names replaced by placeholders.
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2-root-includes.json
// 0x194bf0 Owner194bf0::Initialize
#include "Owner194bf0.h"

extern void* ChainExplosionInitGlobal_194bf0;

void ChainExplosionInitTarget_194bf0(void* a_global, Owner194bf0* a_explosion);

// guess: same compiled code as matched 0x64b630 apart from relocated fields; its role here is not established.
void Owner194bf0::Initialize()
{
    ChainExplosionInitTarget_194bf0(ChainExplosionInitGlobal_194bf0, this);
}
