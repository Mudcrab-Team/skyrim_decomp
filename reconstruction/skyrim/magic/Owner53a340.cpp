// Source exposure: mixed (pinned image listing and anonymous sibling hints).
// Code origin: Stamped as a twin of matched 0x5da050 (skyrim/magic/PeakValueModifierEffect): source copied, names replaced by placeholders.
// Origin: anonymous sibling and target listing.
// OnAdd: SIBLING(fo4-private@1b765c70, author-permission)
// Sibling source: fo4-private@1b765c70 src/Game/Magic/PeakValueModifierEffect.cpp:172
// Sibling source: fo4-private@1b765c70 src/Game/Magic/PeakValueModifierEffect.cpp:288
// 0x53a340 Owner53a340::Function53a340
#include "Owner53a340.h"

// guess: same compiled code as matched 0x5da050 apart from relocated fields; its role here is not established.
void Owner53a340::Function53a340(MagicTarget* target) { FindListPosition(); ValueModifierEffect::OnAdd(target); }
