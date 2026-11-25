// Source exposure: mixed (pinned image listing and authorized sibling hints).
// Code origin: existing sibling-adapted methods plus original reconstruction of BGSMusicTrack constructor. Stamped as a twin of matched 0x326dc0 (skyrim_shared/audio/BGSMusicTrack): source copied, names replaced by placeholders.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Sibling source: fo4-private@1b765c70 src/Shared/TESForms/Gameplay/BGSMusicTrack.cpp:21
// Sibling source: fo4-private@1b765c70 src/Shared/TESForms/Gameplay/BGSMusicTrack.cpp:33
// TESForm, MusicCondition, unknown18: STANDIN GUESS(low)
// Function453940, Owner453940: GUESS(low) STANDIN
// BSIMusicTrack, conditions: GUESS(low) STANDIN
#pragma once
#include "BGSMusicTrack.h"

class Owner453940 : public BSIMusicTrack {
public:
    Owner453940();
    void Function453940(TESForm*);
    bool TestCanPlay() const;
private:
    MusicCondition* conditions;
    std::uint32_t unknown18;
};
