// Source exposure: mixed
// Origin: original reconstruction from independently decoded target and anonymous sibling.
// Hazard::SetActorCause: SIBLING(fo4-private@1b765c70, author-permission); adapted to target call sequence.
// Sibling source: fo4-private@1b765c70 src/Game/AI/Combat/Hazard.cpp:200
// names: GUESS(low); call identities and method names remain unverified.
// 0x7ee740 Hazard::SetActorCause
#include "Hazard.h"
void Hazard::SetActorCause(ActorCause* cause) { if (cause) ownerActor = cause->actor; else ownerActor = nullHandle; TESObjectREFR::SetActorCause(cause); }
