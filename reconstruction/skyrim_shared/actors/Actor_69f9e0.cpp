// Source exposure: mixed
// Origin: original reconstruction from independently decoded target and anonymous sibling.
// Actor::ApplyPerksFromBase: SIBLING(fo4-private@1b765c70, author-permission); adapted to target call sequence.
// Sibling source: fo4-private@1b765c70 src/Game/AI/Actor.cpp:5927
// names: GUESS(low); call identities and method names remain unverified.
// 0x69f9e0 Actor::ApplyPerksFromBase
#include "Actor_69f9e0.h"
void Actor::ApplyPerksFromBase() { if (currentProcess) currentProcess->ApplyPerksFromBase(this); }
