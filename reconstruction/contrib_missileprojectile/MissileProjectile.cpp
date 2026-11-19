// MissileProjectile functions for build sse-steam-1-7-104.
//
// Labels: v2
// Task: contrib-missileprojectile
// Source exposure: mixed (names and declarations from community headers; the listing of the contributor's own pinned image).
// Code origin: the bodies of Revert, Unk_C2 and Unk_C3 are original reconstructions by v-macrev, assisted by claude-sonnet-5-5, from a local listing of the contributor's own copy. Unk_C2 and Unk_C3 return zero, which the powerof3/CommonLibSSE@654e55f declaration comments also state; nothing else is taken from a community or sibling body.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Declarations derived from powerof3/CommonLibSSE are GPL-3.0-or-later.
// This file is free software: you can redistribute it and/or modify it under the terms
// of the GNU General Public License as published by the Free Software Foundation,
// either version 3 of the License, or (at your option) any later version.
// This file is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY;
// without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
// See the GNU General Public License for more details. A copy is provided in
// licenses/CommonLibSSE-GPL-3.0.txt; see also https://www.gnu.org/licenses/.
// Evidence: findings/p92-unit-supply-selection.md
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2.json (compile this file alone).
// Drafted by v-macrev, assisted by claude-sonnet-5-5.
// Compared functions:
//   RVA 0x7f4d60, 3 bytes: MissileProjectile::Unk_C3
//   RVA 0x7f4e50, 30 bytes: MissileProjectile::Revert
//   RVA 0x7f5660, 3 bytes: MissileProjectile::Unk_C2
// Adapted bodies: none
// A byte match shows that this source and recipe produce the checked code; it does not verify the
// community names or that the original source looked like this.
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
