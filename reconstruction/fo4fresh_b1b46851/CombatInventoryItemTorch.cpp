// Source exposure: mixed (pinned image listing and authorized sibling hints).
// Origin: SIBLING(fo4-private@1b765c70, author-permission)
// GetMaxRange: Sibling source: fo4-private@1b765c70 src/Game/AI/Combat/CombatInventoryItem.cpp:370
// CombatInventoryItemTorch, CombatInventoryItemTorch::GetMaxRange: SIBLING(fo4-private@1b765c70, author-permission)
// 0x82e2e0 CombatInventoryItemTorch::GetMaxRange
#include "CombatInventoryItemTorch.h"

float CombatInventoryItemTorch::GetMaxRange() const { return maxRange; }
