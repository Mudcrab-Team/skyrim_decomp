// Source exposure: mixed (pinned image listing and authorized sibling hints).
// Origin: SIBLING(fo4-private@1b765c70, author-permission)
// InitItem: Sibling source: fo4-private@1b765c70 src/Shared/TESForms/Gameplay/BGSMusicTrack.cpp:33
// TestCanPlay: Sibling source: fo4-private@1b765c70 src/Shared/TESForms/Gameplay/BGSMusicTrack.cpp:21
// BGSMusicTrack, BGSMusicTrack::InitItem, BGSMusicTrack::TestCanPlay: SIBLING(fo4-private@1b765c70, author-permission)
// TESForm, ChangeMap, MusicCondition, Player, musicPlayer, unknown00, unknown10, formID, changes, conditions: STANDIN GUESS(low)
#pragma once
#include <cstdint>
class TESForm;
class Player;
class MusicCondition { public: void InitItem(TESForm*); bool IsTrue(Player*, Player*); };
class BGSMusicTrack { public: void InitItem(TESForm*); bool TestCanPlay() const; private: std::uint64_t unknown00[2]; MusicCondition* conditions; };
