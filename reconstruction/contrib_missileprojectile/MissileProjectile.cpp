// Source exposure: mixed (names and declarations from community headers; the listing of the contributor's own pinned image).
// Code origin: the bodies of Revert, Unk_C2 and Unk_C3 are original reconstructions by v-macrev, assisted by claude-sonnet-5-5, from a local listing of the contributor's own copy. Unk_C2 and Unk_C3 return zero, which the powerof3/CommonLibSSE@654e55f declaration comments also state; nothing else is taken from a community or sibling body.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Declarations derived from powerof3/CommonLibSSE are GPL-3.0-or-later.
// Adapted bodies: none
// 0x7f4d60 MissileProjectile::Unk_C3
// 0x7f4e50 MissileProjectile::Revert
// 0x7f5660 MissileProjectile::Unk_C2
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
