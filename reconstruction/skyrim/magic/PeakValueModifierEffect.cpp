// Source exposure: mixed (pinned image listing and anonymous sibling hints).
// Origin: anonymous sibling and target listing.
// OnAdd, FinishLoadGame: SIBLING(fo4-private@1b765c70, author-permission)
// Sibling source: fo4-private@1b765c70 src/Game/Magic/PeakValueModifierEffect.cpp:172
// Sibling source: fo4-private@1b765c70 src/Game/Magic/PeakValueModifierEffect.cpp:288
// 0x5da050 PeakValueModifierEffect::OnAdd
// 0x5da1b0 PeakValueModifierEffect::FinishLoadGame
#include "PeakValueModifierEffect.h"
void PeakValueModifierEffect::OnAdd(MagicTarget* target) { FindListPosition(); ValueModifierEffect::OnAdd(target); }
void PeakValueModifierEffect::FinishLoadGame(BGSLoadFormBuffer* buffer) { FindListPosition(); ActiveEffect::FinishLoadGame(buffer); }
