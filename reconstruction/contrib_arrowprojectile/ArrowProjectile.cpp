// ArrowProjectile functions for build sse-steam-1-7-104.
//
// Labels: v2
// Task: contrib-arrowprojectile
// Source exposure: mixed (names and declarations from community headers; the listing of the contributor's own pinned image).
// Code origin: the bodies are original reconstructions by v-macrev, assisted by claude-sonnet-5-5, from a local listing of the contributor's own copy. Nothing else is taken from a community or sibling body.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Evidence: findings/p92-unit-supply-selection.md
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2.json (compile this file alone).
// Drafted by v-macrev, assisted by claude-sonnet-5-5.
// Compared functions:
//   RVA 0x7de110, 3 bytes: ArrowProjectile::GetStopMainSoundAfterImpact
//   RVA 0x7de810, 3 bytes: ArrowProjectile::Unk_C2
// Adapted bodies: none
// A byte match shows that this source and recipe produce the checked code; it does not verify the
// community names or that the original source looked like this.
#include "ArrowProjectile.h"

bool ArrowProjectile::GetStopMainSoundAfterImpact()
{
    return true;
}

bool ArrowProjectile::Unk_C2()
{
    return true;
}
