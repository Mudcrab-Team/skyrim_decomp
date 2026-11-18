// Source exposure: mixed
// Origin: original reconstruction from independently decoded target and anonymous sibling.
// DisguiseEffect::FinishLoadGame: SIBLING(fo4-private@1b765c70, author-permission); adapted to target state and calls.
// Sibling source: fo4-private@1b765c70 src/Game/Magic/DisguiseEffect.cpp:83
// names: GUESS(low); qualified name and helper identities are unverified.
// 0x5c5d40 DisguiseEffect::FinishLoadGame
#include "DisguiseEffect.h"
void DisguiseEffect::FinishLoadGame(BGSLoadFormBuffer* buffer) { ActiveEffect::FinishLoadGame(buffer); if (state <= 1) InitiateDetectionCheck(); }
