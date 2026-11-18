// Source exposure: mixed
// Origin: original reconstruction from independently decoded target and anonymous sibling.
// Actor::HasBeenAttacked: SIBLING(fo4-private@1b765c70, author-permission); adapted to target call sequence.
// Sibling source: fo4-private@1b765c70 src/Game/AI/Actor_Combat.cpp:150
// names: GUESS(low); call identities and method names remain unverified.
// 0x6ca480 Actor::HasBeenAttacked
#include "Actor.h"
bool Actor::HasBeenAttacked() const { return currentProcess->HasBeenAttacked(); }
