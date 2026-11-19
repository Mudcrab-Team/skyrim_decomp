// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: original; the listing and community declarations only.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// 0x7df6b0 BarrierProjectile::SaveGame
// 0x7df700 BarrierProjectile::LoadGame
// Adapted bodies: none
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
