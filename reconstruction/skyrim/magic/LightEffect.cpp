// Source exposure: mixed (pinned image listing and anonymous sibling hints).
// Origin: anonymous sibling and target listing.
// Revert: SIBLING(fo4-private@1b765c70, author-permission)
// Sibling source: fo4-private@1b765c70 src/Game/Magic/LightEffect.cpp:230
// 0x5c9970 LightEffect::Revert
#include "LightEffect.h"
void LightEffect::Revert(BGSLoadFormBuffer* buffer) { ActiveEffect::Revert(buffer); DetachLight(); }
