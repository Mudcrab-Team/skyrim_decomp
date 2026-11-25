// Source exposure: mixed
// Code origin: Stamped as a twin of matched 0x82cea0 (skyrim/ai/combat/CombatInventoryItem_82cea0): source copied, names replaced by placeholders.
// Origin: independently decoded target and anonymous sibling hint.
// Sibling source: fo4-private@1b765c70 src/Game/AI/Combat/CombatInventoryItem.cpp:103
// 0x22b740 Owner22b740::Function22b740
#include "Owner22b740.h"

// guess: same compiled code as matched 0x82cea0 apart from relocated fields; its role here is not established.
bool Owner22b740::Function22b740(CombatController* controller) const { return !controller->IsFleeing(); }
