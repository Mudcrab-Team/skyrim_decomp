// Source exposure: mixed (names and declarations from community headers; base classes, sizes and
// Code origin: Stamped as a twin of matched 0x327554 (skyrim_shared/audio/BGSMusicTrackFormWrapper): source copied, names replaced by placeholders.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Owner10ac0d0: GUESS(low) STANDIN
// BGSMusicTrackSecondary: GUESS(low) STANDIN
#pragma once
#include "BGSMusicTrackFormWrapper.h"

class Owner10ac0d0 : public TESForm, public BGSMusicTrackSecondary
{
public:
    Owner10ac0d0();
    virtual void InitItemImpl();
    virtual ~Owner10ac0d0();
};
