// BarrierProjectile functions for build sse-steam-1-7-104.
//
// Labels: v2
// Task: contrib-barrierprojectile
// Source exposure: mixed (names and declarations from community headers; the listing of the contributor's own pinned image).
// Code origin: the bodies are original reconstructions by v-macrev, assisted by claude-sonnet-5-5, from a local listing of the contributor's own copy. Nothing else is taken from a community or sibling body.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Evidence: findings/p92-unit-supply-selection.md
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2.json (compile this file alone).
// Drafted by v-macrev, assisted by claude-sonnet-5-5.
// Compared functions:
//   RVA 0x7df6b0, 64 bytes: BarrierProjectile::SaveGame
//   RVA 0x7df700, 55 bytes: BarrierProjectile::LoadGame
// Adapted bodies: none
// A byte match shows that this source and recipe produce the checked code; it does not verify the
// community names or that the original source looked like this.
#include "BarrierProjectile.h"

void BarrierProjectile::SaveGame(BGSSaveFormBuffer* a_buf)
{
    Projectile::SaveGame(a_buf);
    a_buf->SaveDataEndian(&unk1E0, 4, 4, 0);
}

void BarrierProjectile::LoadGame(BGSLoadFormBuffer* a_buf)
{
    Projectile::LoadGame(a_buf);
    a_buf->LoadDataEndian(&unk1E0, 4, 4);
}
