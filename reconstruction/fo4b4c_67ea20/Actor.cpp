// Source exposure: mixed
// Origin: original reconstruction from independently decoded target and anonymous sibling.
// Actor::GetCrimeGoldValue: SIBLING(fo4-private@1b765c70, author-permission); adapted to target call sequence.
// Sibling source: fo4-private@1b765c70 src/Game/AI/Actor.cpp:5238
// names: GUESS(low); call identities and method names remain unverified.
// 0x67ea20 Actor::GetCrimeGoldValue
#include "Actor.h"
unsigned Actor::GetCrimeGoldValue(const TESFaction* faction) const { return faction ? faction->GetCrimeGoldValue(static_cast<TESNPC*>(data.objectReference)) : 0; }
