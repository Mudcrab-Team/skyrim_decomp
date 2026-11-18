// Source exposure: mixed
// Origin: original reconstruction from independently decoded target and anonymous sibling.
// Actor::TryUpdateActorLastSeenTime: SIBLING(fo4-private@1b765c70, author-permission); adapted to target call sequence.
// Sibling source: fo4-private@1b765c70 src/Game/AI/Actor.cpp:422
// names: GUESS(low); helper identities and names are unverified.
// 0x6761f0 Actor::TryUpdateActorLastSeenTime
#include "Actor_6761f0.h"
void Actor::TryUpdateActorLastSeenTime() { if (currentProcess && currentProcess->processLevel == 0) UpdateLastSeenTime(); }
