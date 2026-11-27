// Source exposure: mixed (pinned image listing and anonymous sibling hints).
// Code origin: Stamped as a twin of matched 0x5c9970 (skyrim/magic/LightEffect): source copied, names replaced by placeholders.
// Origin: anonymous sibling and target listing.
// Revert: SIBLING(fo4-private@1b765c70, author-permission)
// Sibling source: fo4-private@1b765c70 src/Game/Magic/LightEffect.cpp:230
// 0x1570720 Owner1570720::Function1570720
#include "Owner1570720.h"

// guess: same compiled code as matched 0x5c9970 apart from relocated fields; its role here is not established.
void Owner1570720::Function1570720(BGSLoadFormBuffer* buffer) { ActiveEffect::Revert(buffer); DetachLight(); }
