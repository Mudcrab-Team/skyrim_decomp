// Source exposure: mixed (pinned image listing and authorized sibling hints).
// Code origin: existing sibling-adapted methods plus original reconstruction of BGSMusicTrack constructor. Stamped as a twin of matched 0x326dc0 (skyrim_shared/audio/BGSMusicTrack): source copied, names replaced by placeholders.
// Sibling source: fo4-private@1b765c70 src/Shared/TESForms/Gameplay/BGSMusicTrack.cpp:21
// Sibling source: fo4-private@1b765c70 src/Shared/TESForms/Gameplay/BGSMusicTrack.cpp:33
// 0x44f480 Owner44f480::Function44f480
#include "Owner44f480.h"

Owner44f480::Owner44f480()
    : BSIMusicTrack(), conditions(nullptr), unknown18(0u)
{
}

// guess: same compiled code as matched 0x326dc0 apart from relocated fields; its role here is not established.
void Owner44f480::Function44f480(TESForm* form) { if (conditions) conditions->InitItem(form); }
