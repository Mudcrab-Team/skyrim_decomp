// CombatInventoryItem::GetEquipType: SIBLING(fo4-private@1b765c70, author-permission); adaptation of src/Game/AI/Combat/CombatInventoryItem.cpp:147; target behavior differs where applicable.
// Semantic names and types: GUESS(low)
// Source exposure: mixed.
// Origin: original reconstruction from independently decoded target and anonymous sibling.
// 0x82ce50 CombatInventoryItem::GetEquipType
#include "CombatInventoryItem.h"
CombatInventoryItem::TYPE CombatInventoryItem::GetEquipType(unsigned int) { return GetType(); }
