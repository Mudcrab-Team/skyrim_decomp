// Source exposure: mixed (community headers; the pinned image listing).
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Code origin: original; the listing and the community declarations only Stamped as a twin of matched 0x64b630 (skyrim/magic/ChainExplosion): source copied, names replaced by placeholders.
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2-root-includes.json
// 0x194b70 Owner194b70::Initialize
#include "Owner194b70.h"

extern void* ChainExplosionInitGlobal_194b70;

void ChainExplosionInitTarget_194b70(void* a_global, Owner194b70* a_explosion);

// guess: same compiled code as matched 0x64b630 apart from relocated fields; its role here is not established.
void Owner194b70::Initialize()
{
    ChainExplosionInitTarget_194b70(ChainExplosionInitGlobal_194b70, this);
}
