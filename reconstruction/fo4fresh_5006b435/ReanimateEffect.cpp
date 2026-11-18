// Source exposure: mixed (pinned image listing and authorized sibling hints).
// Origin: SIBLING(fo4-private@1b765c70, author-permission)
// ShouldDispelOnDeath: Sibling source: fo4-private@1b765c70 src/Game/Magic/ReanimateEffect.cpp:63
// ReanimateEffect, ReanimateEffect::ShouldDispelOnDeath: SIBLING(fo4-private@1b765c70, author-permission)
// unknown00, gettingUp, BaseShouldDispelOnDeath: STANDIN GUESS(low)
// 0x5da700 ReanimateEffect::ShouldDispelOnDeath
#include "ReanimateEffect.h"
bool ReanimateEffect::ShouldDispelOnDeath() const { return !gettingUp && BaseShouldDispelOnDeath(); }
