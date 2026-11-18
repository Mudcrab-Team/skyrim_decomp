// Source exposure: mixed
// Origin: original reconstruction from independently decoded target and anonymous sibling.
// CombatInventoryItemMagic::GetEquipRange: SIBLING(fo4-private@1b765c70, author-permission); adapted to target arithmetic.
// Sibling source: fo4-private@1b765c70 src/Game/AI/Combat/CombatInventoryItem.cpp:390
// names: GUESS(low); method and setting names are unverified.
// 0x82e960 CombatInventoryItemMagic::GetEquipRange
#include "CombatInventoryItemMagic_82e960.h"
float CombatInventoryItemMagic::GetEquipRange() { return maxRange > 0.0f ? maxRange : 3.402823466e+38F; }
