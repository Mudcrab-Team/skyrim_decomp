// Source exposure: mixed (pinned image listing and anonymous sibling hints).
// Origin: anonymous sibling and target listing.
// HandleEvent: SIBLING(fo4-private@1b765c70, author-permission)
// Sibling source: fo4-private@1b765c70 src/Game/Magic/SummonCreatureEffect.cpp:242
// 0x5e4680 SummonCreatureEffect::HandleEvent
#include "SummonCreatureEffect.h"
void SummonCreatureEffect::HandleEvent(const FixedString& event) {
    if (event.data == placeActorTag.data) DoSummon();
}
