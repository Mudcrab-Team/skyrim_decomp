// Source exposure: mixed
// Origin: original reconstruction from independently decoded target and anonymous sibling.
// Actor::SetActionComplete: SIBLING(fo4-private@1b765c70, author-permission); adapted to target call sequence.
// Sibling source: fo4-private@1b765c70 src/Game/AI/Actor.cpp:628
// names: GUESS(low); call identities and method names remain unverified.
// 0x687c90 Actor::SetActionComplete
#include "Actor_687c90.h"
void Actor::SetActionComplete(bool value) { if (currentProcess) { currentProcess->SetCurrentActionComplete(value); currentProcess->ClearMovementStopped(); } }
