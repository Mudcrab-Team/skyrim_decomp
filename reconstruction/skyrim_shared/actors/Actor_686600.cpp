// Source exposure: mixed
// Origin: original reconstruction from independently decoded target and anonymous sibling.
// Actor::SetObjectReference: SIBLING(fo4-private@1b765c70, author-permission); adapted to target base and race fields.
// Sibling source: fo4-private@1b765c70 src/Game/AI/Actor.cpp:65
// names: GUESS(low); object and race identities remain inferred.
// 0x686600 Actor::SetObjectReference
#include "Actor_686600.h"
void Actor::SetObjectReference(TESBoundObject* object) { TESObjectREFR::SetObjectReference(object); if (data.objectReference) race = static_cast<TESNPC*>(data.objectReference)->TESRaceForm::race; }
