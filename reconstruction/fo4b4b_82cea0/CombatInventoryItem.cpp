// Source exposure: mixed
// Origin: independently decoded target and anonymous sibling hint.
// CombatInventoryItem::CheckShouldEquip: SIBLING(fo4-private@1b765c70, author-permission); adapted to target observations.
// Sibling source: fo4-private@1b765c70 src/Game/AI/Combat/CombatInventoryItem.cpp:103
// names: GUESS(low); names and original signatures are tentative.
// 0x82cea0 CombatInventoryItem::CheckShouldEquip
#include "CombatInventoryItem.h"
bool CombatInventoryItem::CheckShouldEquip(CombatController* controller) const { return !controller->IsFleeing(); }
