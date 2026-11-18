// Source exposure: mixed
// Origin: original reconstruction from independently decoded target and anonymous sibling.
// Actor::HasPerkEntries: SIBLING(fo4-private@1b765c70, author-permission); adapted to target call sequence.
// Sibling source: fo4-private@1b765c70 src/Game/AI/Actor.cpp:5912
// names: GUESS(low); call identities and method names remain unverified.
// 0x69f990 Actor::HasPerkEntries
#include "Actor_69f990.h"
bool Actor::HasPerkEntries(unsigned char entry) const { return currentProcess && currentProcess->HasPerkEntries(entry); }
