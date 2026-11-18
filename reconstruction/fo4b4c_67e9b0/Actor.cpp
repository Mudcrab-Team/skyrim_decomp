// Source exposure: mixed
// Origin: original reconstruction from independently decoded target and anonymous sibling.
// Actor::SetCrimeGoldValue: SIBLING(fo4-private@1b765c70, author-permission); adapted to target call sequence.
// Sibling source: fo4-private@1b765c70 src/Game/AI/Actor.cpp:5216
// names: GUESS(low); call identities and method names remain unverified.
// 0x67e9b0 Actor::SetCrimeGoldValue
#include "Actor.h"
void Actor::SetCrimeGoldValue(TESFaction* faction, bool, unsigned value) { if (faction) faction->SetCrimeGoldValue(static_cast<TESNPC*>(data.objectReference), value); }
