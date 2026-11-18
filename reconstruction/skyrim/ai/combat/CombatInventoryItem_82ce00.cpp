// Source exposure: mixed (pinned image listing and authorized sibling hints).
// Origin: SIBLING(fo4-private@1b765c70, author-permission)
// GetMinRange: Sibling source: fo4-private@1b765c70 src/Game/AI/Combat/CombatInventoryItem.cpp:88
// GetMaxRange: Sibling source: fo4-private@1b765c70 src/Game/AI/Combat/CombatInventoryItem.cpp:90
// GetOptimalRange: Sibling source: fo4-private@1b765c70 src/Game/AI/Combat/CombatInventoryItem.cpp:92
// GetEquipRange: Sibling source: fo4-private@1b765c70 src/Game/AI/Combat/CombatInventoryItem.cpp:94
// CombatInventoryItem, CombatInventoryItem::GetMinRange, CombatInventoryItem::GetMaxRange, CombatInventoryItem::GetOptimalRange, CombatInventoryItem::GetEquipRange: SIBLING(fo4-private@1b765c70, author-permission)
// 0x82ce00 CombatInventoryItem::GetMinRange
// 0x82ce10 CombatInventoryItem::GetMaxRange
// 0x82ce20 CombatInventoryItem::GetOptimalRange
// 0x82ce30 CombatInventoryItem::GetEquipRange
#include "CombatInventoryItem_82ce00.h"

float CombatInventoryItem::GetMinRange() const { return 0.0f; }
float CombatInventoryItem::GetMaxRange() const { return 0.0f; }
float CombatInventoryItem::GetOptimalRange() const { return 0.0f; }
float CombatInventoryItem::GetEquipRange() const { return 3.402823466e+38F; }
