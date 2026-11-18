// Source exposure: mixed (Skyrim binary analysis, community declarations, fo4-private reconstruction).
// Origin: adapted from the cited anonymous permitted sibling body; partial Skyrim class view.
// Licence: fo4-private reused with author permission conditional on anonymity (awarebayes, 2026-11-14).
// MagicCaster: SIBLING(fo4-private@1b765c70, author-permission)
// CheckCast: SIBLING(fo4-private@1b765c70, author-permission)
// Padding and incomplete declarations: STANDIN GUESS(low); no complete-layout or behaviour claim.
// Sibling source: fo4-private@1b765c70 src/Game/Magic/MagicCaster.cpp:316
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// 0x5cd0d0 MagicCaster::CheckCast
#include "MagicCaster.h"

bool __fastcall MagicCaster::CheckCast(MagicItem *apSpell, bool abCheck, float *afEffectStrength, MagicSystem::CannotCastReason *apReason, bool abCheck2)
{
    if (afEffectStrength)
        *afEffectStrength = 1.0f;
    if (apReason)
        *apReason = MagicSystem::NOCAST_OK;
    return true;

}
