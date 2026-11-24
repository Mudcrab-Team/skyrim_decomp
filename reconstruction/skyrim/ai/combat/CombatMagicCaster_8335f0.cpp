// Source exposure: mixed (sibling source; the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: CC0-1.0
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2.json
// 0x8335f0 CombatMagicCaster::LoadGame
// Adapted bodies: CombatMagicCaster::LoadGame from the sibling source named in the header
#include "CombatMagicCaster_8335f0.h"

void CombatMagicCaster::LoadGame(BGSLoadFormBuffer* a_buffer)
{
    CombatObject::LoadGame(a_buffer);
    CombatInventoryItemMagic* loaded = static_cast<CombatInventoryItemMagic*>(CombatObject::Load(a_buffer));
    inventoryItem = loaded;
    magicItem = inventoryItem.m_pObject->GetMagic();
}
