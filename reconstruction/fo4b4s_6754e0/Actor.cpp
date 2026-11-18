// Source exposure: mixed
// Origin: original reconstruction from independently decoded target and anonymous sibling.
// Actor::Disable: SIBLING(fo4-private@1b765c70, author-permission); adapted to target call sequence.
// Sibling source: fo4-private@1b765c70 src/Game/AI/Actor.cpp:6345
// names: GUESS(low); helper identities and names are unverified.
// 0x6754e0 Actor::Disable
#include "Actor.h"
void Actor::Disable() { if (this == player) return; if ((unsigned char)(formFlags >> 11) & 1) return; taskQueue->QueueDisableReference(this); }
