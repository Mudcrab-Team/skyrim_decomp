// Source exposure: mixed (pinned image listing and authorized sibling hints).
// Origin: SIBLING(fo4-private@1b765c70, author-permission)
// GetMinRange: Sibling source: fo4-private@1b765c70 src/Game/AI/Combat/CombatInventoryItem.cpp:383
// GetMaxRange: Sibling source: fo4-private@1b765c70 src/Game/AI/Combat/CombatInventoryItem.cpp:385
// CombatInventoryItemMagic, CombatInventoryItemMagic::GetMinRange, CombatInventoryItemMagic::GetMaxRange: SIBLING(fo4-private@1b765c70, author-permission)
// 0x82e920 CombatInventoryItemMagic::GetMinRange
// 0x82e930 CombatInventoryItemMagic::GetMaxRange
#include "CombatInventoryItemMagic.h"

float CombatInventoryItemMagic::GetMinRange() const { return minRange; }
float CombatInventoryItemMagic::GetMaxRange() const { return maxRange; }
