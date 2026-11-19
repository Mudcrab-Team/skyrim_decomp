// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: original; the listing and community declarations only. Unk_C2 and Unk_C3 return zero, as the powerof3/CommonLibSSE@654e55f declaration comments also state.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Declarations derived from powerof3/CommonLibSSE are GPL-3.0 (its licence).
// 0x7f4d60 MissileProjectile::Unk_C3
// 0x7f4e50 MissileProjectile::Revert
// 0x7f5660 MissileProjectile::Unk_C2
// Adapted bodies: none
#include "MissileProjectile.h"

void MissileProjectile::Revert(BGSLoadFormBuffer* a_buf)
{
    Projectile::Revert(a_buf);
    impactResult = ImpactResult::kNone;
}

bool MissileProjectile::Unk_C2()
{
    return false;
}

bool MissileProjectile::Unk_C3()
{
    return false;
}
