// Source exposure: mixed
// Origin: original reconstruction from independently decoded target and anonymous sibling.
// Actor::EndDeferredKill: SIBLING(fo4-private@1b765c70, author-permission); adapted to target call sequence.
// Sibling source: fo4-private@1b765c70 src/Game/AI/Actor_Combat.cpp:658
// names: GUESS(low); call identities and method names remain unverified.
// 0x6cc950 Actor::EndDeferredKill
#include "Actor_6cc950.h"
void Actor::EndDeferredKill(bool script) { if (currentProcess) currentProcess->EndDeferredKill(script, *this); }
