// Source exposure: mixed
// Origin: original reconstruction from independently decoded target and anonymous sibling.
// Actor::TryMoveToMiddleLow: SIBLING(fo4-private@1b765c70, author-permission); adapted to target call sequence.
// Sibling source: fo4-private@1b765c70 src/Game/AI/Actor.cpp:383
// names: GUESS(low); helper identities and names are unverified.
// 0x675bf0 Actor::TryMoveToMiddleLow
#include "Actor.h"
void Actor::TryMoveToMiddleLow() { if ((unsigned char)(formFlags >> 11) & 1) return; if (!currentProcess) return; if (currentProcess->processLevel != 3) return; processLists->AddActorToTempChangeList(this); }
