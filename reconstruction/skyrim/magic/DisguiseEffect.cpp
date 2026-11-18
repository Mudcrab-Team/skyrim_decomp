// Source exposure: mixed
// Origin: original reconstruction from independently decoded target and anonymous sibling.
// DisguiseEffect::LoadGame: SIBLING(fo4-private@1b765c70, author-permission); adapted to target state and calls.
// Sibling source: fo4-private@1b765c70 src/Game/Magic/DisguiseEffect.cpp:76
// names: GUESS(low); qualified name and helper identities are unverified.
// 0x5c5d00 DisguiseEffect::LoadGame
#include "DisguiseEffect.h"
void DisguiseEffect::LoadGame(BGSLoadFormBuffer* buffer) { ActiveEffect::LoadGame(buffer); buffer->LoadDataEndian(&state, 4, 4); }
