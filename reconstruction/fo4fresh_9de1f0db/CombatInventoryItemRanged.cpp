// Source exposure: mixed (pinned image listing and authorized sibling hints).
// Origin: SIBLING(fo4-private@1b765c70, author-permission)
// GetMinRange: Sibling source: fo4-private@1b765c70 src/Game/AI/Combat/CombatInventoryItem.cpp:242
// GetMaxRange: Sibling source: fo4-private@1b765c70 src/Game/AI/Combat/CombatInventoryItem.cpp:244
// GetEquipRange: Sibling source: fo4-private@1b765c70 src/Game/AI/Combat/CombatInventoryItem.cpp:248
// CombatInventoryItemRanged, CombatInventoryItemRanged::GetMinRange, CombatInventoryItemRanged::GetMaxRange, CombatInventoryItemRanged::GetEquipRange: SIBLING(fo4-private@1b765c70, author-permission)
// 0x82d6f0 CombatInventoryItemRanged::GetMinRange
// 0x82d700 CombatInventoryItemRanged::GetMaxRange
// 0x82d730 CombatInventoryItemRanged::GetEquipRange
#include "CombatInventoryItemRanged.h"

float CombatInventoryItemRanged::GetMinRange() const { return minRange; }
float CombatInventoryItemRanged::GetMaxRange() const { return maxRange; }
float CombatInventoryItemRanged::GetEquipRange() const { return maxRange; }
