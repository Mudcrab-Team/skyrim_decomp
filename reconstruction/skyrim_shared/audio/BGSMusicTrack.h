// Source exposure: mixed (pinned image listing and authorized sibling hints).
// Code origin: existing sibling-adapted methods plus original reconstruction of BGSMusicTrack constructor.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Sibling source: fo4-private@1b765c70 src/Shared/TESForms/Gameplay/BGSMusicTrack.cpp:21
// Sibling source: fo4-private@1b765c70 src/Shared/TESForms/Gameplay/BGSMusicTrack.cpp:33
// BGSMusicTrack, BGSMusicTrack::InitItem, BGSMusicTrack::TestCanPlay: SIBLING(fo4-private@1b765c70, author-permission)
// BSIMusicTrack, trackStatus, conditions: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// TESForm, MusicCondition, Player, musicPlayer, unknown18: STANDIN GUESS(low)
#pragma once
#include <cstdint>
class TESForm;
class Player;
class MusicCondition { public: void InitItem(TESForm*); bool IsTrue(Player*, Player*); };
class BSIMusicTrack {
public:
    BSIMusicTrack() : trackStatus(0u) {}
    virtual ~BSIMusicTrack();
    std::uint32_t trackStatus;
};
class BGSMusicTrack : public BSIMusicTrack {
public:
    BGSMusicTrack();
    void InitItem(TESForm*);
    bool TestCanPlay() const;
private:
    MusicCondition* conditions;
    std::uint32_t unknown18;
};
