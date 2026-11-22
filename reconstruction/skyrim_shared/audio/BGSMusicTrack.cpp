// Source exposure: mixed (pinned image listing and authorized sibling hints).
// Code origin: existing sibling-adapted methods plus original reconstruction of BGSMusicTrack constructor.
// Sibling source: fo4-private@1b765c70 src/Shared/TESForms/Gameplay/BGSMusicTrack.cpp:21
// Sibling source: fo4-private@1b765c70 src/Shared/TESForms/Gameplay/BGSMusicTrack.cpp:33
// Adapted bodies: InitItem and TestCanPlay from fo4-private@1b765c70; constructor original.
// 0x326dc0 BGSMusicTrack::InitItem
// 0x326d00 BGSMusicTrack::TestCanPlay
// 0x326d30 BGSMusicTrack::Ctor
#include "BGSMusicTrack.h"

extern Player* musicPlayer;

BGSMusicTrack::BGSMusicTrack()
    : BSIMusicTrack(), conditions(nullptr), unknown18(0u)
{
}

void BGSMusicTrack::InitItem(TESForm* form) { if (conditions) conditions->InitItem(form); }
bool BGSMusicTrack::TestCanPlay() const { if (conditions) { if (musicPlayer) return conditions->IsTrue(musicPlayer, musicPlayer); return false; } return true; }
