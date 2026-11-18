// Source exposure: mixed (authorized target analysis and anonymous permitted sibling source).
// Origin: adapted from the cited game-code body under anonymous author permission.
// Licence: fo4-private reused with author permission conditional on anonymity.
// BSFixedString: STANDIN GUESS(low)
// data: GUESS(low)
// Sibling source: fo4-private@1b765c70 src/Game/AI/Combat/CombatInventoryItem.cpp:220
// CombatInventoryItemMelee, GetClassType: SIBLING(fo4-private@1b765c70, author-permission)
#pragma once
class CombatObjectBase { public: static unsigned int GenerateClassType(const char*); };
class CombatInventoryItemMelee { public: static unsigned int GetClassType(); };
