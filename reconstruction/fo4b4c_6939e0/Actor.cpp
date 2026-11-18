// Source exposure: mixed
// Origin: original reconstruction from independently decoded target and anonymous sibling.
// Actor::SetCriticalStage: SIBLING(fo4-private@1b765c70, author-permission); adapted to target call sequence.
// Sibling source: fo4-private@1b765c70 src/Game/AI/Actor.cpp:2253
// names: GUESS(low); helper identities and names are unverified.
// 0x6939e0 Actor::SetCriticalStage
#include "Actor.h"
void Actor::SetCriticalStage(unsigned stage) { criticalStage = stage; UpdateCriticalStage(); }
