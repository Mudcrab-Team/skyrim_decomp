// Source exposure: mixed
// Origin: original reconstruction from independently decoded target and anonymous sibling.
// Actor::RemoveCrimeGoldValue: SIBLING(fo4-private@1b765c70, author-permission); adapted to target call sequence.
// Sibling source: fo4-private@1b765c70 src/Game/AI/Actor.cpp:5231
// names: GUESS(low); call identities and method names remain unverified.
// 0x67ea00 Actor::RemoveCrimeGoldValue
#include "Actor.h"
void Actor::RemoveCrimeGoldValue(TESFaction* faction, bool, int value) { if (faction) faction->ModCrimeGoldValue(static_cast<TESNPC*>(data.objectReference), value); }
