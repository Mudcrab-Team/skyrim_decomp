// Source exposure: mixed (pinned target listing and sibling hints).
// Origin: adapted sibling source and target listing.
// SummonCreatureEffect::SetLocation: SIBLING(fo4-private@1b765c70, author-permission)
// Sibling source: fo4-private@1b765c70 src/Game/Magic/SummonCreatureEffect.cpp:197
// SummonCreatureEffect, SummonCreatureEffect::SetLocation: GUESS(low)
// SummonCreatureEffect fields: STANDIN GUESS(low)
// 0x5e5360 SummonCreatureEffect::SetLocation
#include "SummonCreatureEffect_5e5360.h"
void SummonCreatureEffect::SetLocation(const Point3& value) { location.x = value.x; location.y = value.y; location.z = value.z; }
