// Source exposure: mixed
// Origin: original reconstruction from independently decoded target and anonymous sibling.
// CombatInventoryItemMagic::GetOptimalRange: SIBLING(fo4-private@1b765c70, author-permission); adapted to target arithmetic.
// Sibling source: fo4-private@1b765c70 src/Game/AI/Combat/CombatInventoryItem.cpp:387
// names: GUESS(low); method and setting names are unverified.
// 0x82e940 CombatInventoryItemMagic::GetOptimalRange
#include "CombatInventoryItemMagic_82e940.h"
float CombatInventoryItemMagic::GetOptimalRange() { return (maxRange - minRange) * optimalRangePercent + minRange; }
