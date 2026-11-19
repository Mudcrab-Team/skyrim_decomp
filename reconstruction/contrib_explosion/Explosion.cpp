// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: original; the listing and community declarations only.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// 0x7e5170 Explosion::AsExplosion
// 0x7e9010 Explosion::OnAddCellPerformQueueReference
// Adapted bodies: none
#include "Explosion.h"

Explosion* Explosion::AsExplosion()
{
    return this;
}

bool Explosion::OnAddCellPerformQueueReference(TESObjectCELL& a_cell) const
{
    return false;
}
