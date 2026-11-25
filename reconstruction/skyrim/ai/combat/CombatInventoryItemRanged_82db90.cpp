// Source exposure: mixed (community headers; the pinned image listing; a permitted sibling body).
// Code origin: body shape adapted from a permitted sibling body, call arguments and offsets checked against the pinned image listing
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// 0x82db90 CombatInventoryItemRanged::LoadGame
// CombatInventoryItemRanged::LoadGame, CombatInventoryItemComposite::LoadGame: GUESS(low); the override and the composite call; the composite body is labelled in the header
// Adapted bodies: CombatInventoryItemComposite::LoadGame (inline in the header, shape only)
// Sibling source: fo4-private@1b765c70 src/Game/AI/Combat/CombatInventoryItem.cpp:161
#include "CombatInventoryItemRanged_82db90.h"

// Loads the composite state, then the two range limits.
void CombatInventoryItemRanged::LoadGame(BGSLoadGameBuffer* a_buf)
{
    CombatInventoryItemComposite::LoadGame(a_buf);
    a_buf->LoadDataEndian(&minRange, 4, 4);
    a_buf->LoadDataEndian(&maxRange, 4, 4);
}
