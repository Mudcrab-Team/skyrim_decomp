// Source exposure: mixed
// Origin: original reconstruction from independently decoded target and anonymous sibling.
// CombatMagicCaster::SaveGame: SIBLING(fo4-private@1b765c70, author-permission); adapted to target fields and call sequence.
// Sibling source: fo4-private@1b765c70 src/Game/AI/Combat/CombatMagicCaster.cpp:139
// names: GUESS(low); save helper identity is unverified.
// 0x8335b0 CombatMagicCaster::SaveGame
#include "CombatMagicCaster.h"
void CombatMagicCaster::SaveGame(BGSSaveGameBuffer* buffer) const { CombatObject::SaveGame(buffer); SaveCombatObject(buffer, inventoryItem); }
