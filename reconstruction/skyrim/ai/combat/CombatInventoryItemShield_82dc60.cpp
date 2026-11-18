// Source exposure: mixed
// Origin: original reconstruction from independently decoded target and anonymous sibling.
// CombatInventoryItemShield::GetMaxRange: SIBLING(fo4-private@1b765c70, author-permission); adaptation
// Sibling source: fo4-private@1b765c70 src/Game/AI/Combat/CombatInventoryItem.cpp:323
// CombatInventoryItemShield::GetOptimalRange: SIBLING(fo4-private@1b765c70, author-permission); adaptation
// Sibling source: fo4-private@1b765c70 src/Game/AI/Combat/CombatInventoryItem.cpp:325
// CombatInventoryItemShield::GetEquipRange: SIBLING(fo4-private@1b765c70, author-permission); adaptation
// Sibling source: fo4-private@1b765c70 src/Game/AI/Combat/CombatInventoryItem.cpp:327
// 0x82dc60 CombatInventoryItemShield::GetMaxRange
// 0x82dc70 CombatInventoryItemShield::GetOptimalRange
// 0x82dc90 CombatInventoryItemShield::GetEquipRange
#include "CombatInventoryItemShield_82dc60.h"
float CombatInventoryItemShield::GetMaxRange() { return maxRange; }
float CombatInventoryItemShield::GetOptimalRange() { return optimalRangeScale * maxRange; }
float CombatInventoryItemShield::GetEquipRange() { return equipRange + maxRange; }
