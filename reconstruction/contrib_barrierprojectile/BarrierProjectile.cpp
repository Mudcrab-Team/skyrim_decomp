// Source exposure: mixed (names and declarations from community headers; the listing of the contributor's own pinned image).
// Code origin: the bodies are original reconstructions by v-macrev, assisted by claude-sonnet-5-5, from a local listing of the contributor's own copy. Nothing else is taken from a community or sibling body.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Adapted bodies: none
// 0x7df6b0 BarrierProjectile::SaveGame
// 0x7df700 BarrierProjectile::LoadGame
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
