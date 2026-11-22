// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: original; the listing and community declarations only
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// 0x7e0410 BeamProjectile::GetKillOnCollision
// Adapted bodies: none
// Source exposure: mixed (names and declarations from community headers; the listing of the pinned
// image).
// Declarations derived from powerof3/CommonLibSSE are GPL-3.0 (its licence).
// Adapted bodies: none
#include "BeamProjectile.h"

bool BeamProjectile::GetKillOnCollision()
{
    return false;
}

void BeamProjectile::Revert(BGSLoadFormBuffer* a_buf)
{
    Projectile::Revert(a_buf);
    unk240 = 0;
}

void BeamProjectile::SaveGame(BGSSaveFormBuffer* a_buf)
{
    Projectile::SaveGame(a_buf);
    a_buf->SaveDataEndian(&unk240, 1, 1, 0);
}

// Accepted leaf retained from the integrated version.
// Slot165: GUESS(low); method name inferred from vtable owner and slot
std::uint8_t BeamProjectile::Slot165() const
{
    return 0x1;
}
