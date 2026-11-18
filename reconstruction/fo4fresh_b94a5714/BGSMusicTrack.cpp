// Source exposure: mixed (pinned image listing and authorized sibling hints).
// Origin: SIBLING(fo4-private@1b765c70, author-permission)
// InitItem: Sibling source: fo4-private@1b765c70 src/Shared/TESForms/Gameplay/BGSMusicTrack.cpp:33
// TestCanPlay: Sibling source: fo4-private@1b765c70 src/Shared/TESForms/Gameplay/BGSMusicTrack.cpp:21
// BGSMusicTrack, BGSMusicTrack::InitItem, BGSMusicTrack::TestCanPlay: SIBLING(fo4-private@1b765c70, author-permission)
// TESForm, ChangeMap, MusicCondition, Player, musicPlayer, unknown00, unknown10, formID, changes, conditions: STANDIN GUESS(low)
// 0x326dc0 BGSMusicTrack::InitItem
// 0x326d00 BGSMusicTrack::TestCanPlay
#include "BGSMusicTrack.h"

extern Player* musicPlayer;
void BGSMusicTrack::InitItem(TESForm* form) { if (conditions) conditions->InitItem(form); }
bool BGSMusicTrack::TestCanPlay() const { if (conditions) { if (musicPlayer) return conditions->IsTrue(musicPlayer, musicPlayer); return false; } return true; }
