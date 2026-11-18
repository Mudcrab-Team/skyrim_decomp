// Source exposure: mixed
// Origin: original reconstruction from independently decoded target and anonymous sibling.
// Actor::GetMagicTarget: SIBLING(fo4-private@1b765c70, author-permission); adapted to target base adjustment.
// Sibling source: fo4-private@1b765c70 src/Game/AI/Actor_Magic.cpp:386
// names: GUESS(low); method identity is unverified.
// 0x6d8550 Actor::GetMagicTarget
#include "Actor_6d8550.h"
MagicTarget* Actor::GetMagicTarget() { return static_cast<MagicTarget*>(this); }
