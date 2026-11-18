// Source exposure: mixed
// Origin: original reconstruction from independently decoded target and anonymous sibling.
// Actor::ForEachPerkEntry: SIBLING(fo4-private@1b765c70, author-permission); adapted to target call sequence.
// Sibling source: fo4-private@1b765c70 src/Game/AI/Actor.cpp:5919
// names: GUESS(low); call identities and method names remain unverified.
// 0x69f9c0 Actor::ForEachPerkEntry
#include "Actor.h"
void Actor::ForEachPerkEntry(unsigned char entry, PerkEntryVisitor& visitor) const { if (currentProcess) currentProcess->ForEachPerkEntry(entry, visitor); }
