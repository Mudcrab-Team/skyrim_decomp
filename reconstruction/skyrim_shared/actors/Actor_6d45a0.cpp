// Source exposure: mixed
// Origin: original reconstruction from independently decoded target and anonymous sibling.
// Actor::GetAlpha: SIBLING(fo4-private@1b765c70, author-permission); adapted to target call sequence.
// Sibling source: fo4-private@1b765c70 src/Game/AI/Actor_Magic.cpp:333
// names: GUESS(low); call identities and method names remain unverified.
// 0x6d45a0 Actor::GetAlpha
#include "Actor_6d45a0.h"
float Actor::GetAlpha() { if (!GetProcessLevel()) return currentProcess->QMaxAlpha(); return 1.0f; }
