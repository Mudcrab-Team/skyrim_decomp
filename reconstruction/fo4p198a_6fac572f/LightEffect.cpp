// Source exposure: mixed
// Origin: original reconstruction from independently decoded target and anonymous sibling.
// LightEffect::FinishLoadGame: SIBLING(fo4-private@1b765c70, author-permission); adapted to target call sequence.
// Sibling source: fo4-private@1b765c70 src/Game/Magic/LightEffect.cpp:223
// names: GUESS(low); call identities and method names remain unverified.
// 0x5c9940 LightEffect::FinishLoadGame
#include "LightEffect.h"
void LightEffect::FinishLoadGame(BGSLoadFormBuffer* buffer) { ActiveEffect::FinishLoadGame(buffer); Start(); }
