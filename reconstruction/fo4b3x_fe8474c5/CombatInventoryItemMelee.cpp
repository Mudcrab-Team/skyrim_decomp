// Source exposure: mixed
// Origin: original reconstruction from independently decoded target and anonymous sibling.
// CombatInventoryItemMelee::GetMaxRange: SIBLING(fo4-private@1b765c70, author-permission); adaptation
// Sibling source: fo4-private@1b765c70 src/Game/AI/Combat/CombatInventoryItem.cpp:184
// CombatInventoryItemMelee::GetOptimalRange: SIBLING(fo4-private@1b765c70, author-permission); adaptation
// Sibling source: fo4-private@1b765c70 src/Game/AI/Combat/CombatInventoryItem.cpp:186
// CombatInventoryItemMelee::GetEquipRange: SIBLING(fo4-private@1b765c70, author-permission); adaptation
// Sibling source: fo4-private@1b765c70 src/Game/AI/Combat/CombatInventoryItem.cpp:188
// 0x82d1f0 CombatInventoryItemMelee::GetMaxRange
// 0x82d200 CombatInventoryItemMelee::GetOptimalRange
// 0x82d220 CombatInventoryItemMelee::GetEquipRange
#include "CombatInventoryItemMelee.h"
float CombatInventoryItemMelee::GetMaxRange() { return maxRange; }
float CombatInventoryItemMelee::GetOptimalRange() { return optimalRangeScale * maxRange; }
float CombatInventoryItemMelee::GetEquipRange() { return equipRange + maxRange; }
