// Source exposure: mixed (pinned target listing and sibling hints).
// Origin: adapted sibling source and target listing.
// ReferenceEffect::ClearTarget: SIBLING(fo4-private@1b765c70, author-permission)
// Sibling source: fo4-private@1b765c70 src/Game/Magic/ReferenceEffect.cpp:155
// ReferenceEffect, ReferenceEffect::ClearTarget: GUESS(low)
// ReferenceEffect fields: STANDIN GUESS(low)
// 0x5db660 ReferenceEffect::ClearTarget
#include "ReferenceEffect.h"
void ReferenceEffect::ClearTarget() { target = nullHandle; }
