// Source exposure: mixed
// Origin: original reconstruction from independently decoded target and anonymous sibling.
// ReanimateEffect::LoadGame: SIBLING(fo4-private@1b765c70, author-permission); adapted to target fields and call order.
// Sibling source: fo4-private@1b765c70 src/Game/Magic/ReanimateEffect.cpp:56
// names: GUESS(low); boolean meaning and helper identities are unverified.
// 0x5da6c0 ReanimateEffect::LoadGame
#include "ReanimateEffect.h"
void ReanimateEffect::LoadGame(BGSLoadFormBuffer* buffer) { buffer->LoadDataEndian(&gettingUp, 1, 1); CommandEffect::LoadGame(buffer); }
