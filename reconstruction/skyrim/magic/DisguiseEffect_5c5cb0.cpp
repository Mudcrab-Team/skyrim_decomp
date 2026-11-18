// Source exposure: mixed
// Origin: original reconstruction from independently decoded target and anonymous sibling.
// DisguiseEffect::SaveGame: SIBLING(fo4-private@1b765c70, author-permission); adapted to the target calls.
// Sibling source: fo4-private@1b765c70 src/Game/Magic/DisguiseEffect.cpp:69
// names: GUESS(low); signatures and helper identities need independent review.
// 0x5c5cb0 DisguiseEffect::SaveGame
#include "DisguiseEffect_5c5cb0.h"
void DisguiseEffect::SaveGame(BGSSaveFormBuffer* buffer) const { ActiveEffect::SaveGame(buffer); buffer->SaveDataEndian(&state, 4, 4, 0); }
