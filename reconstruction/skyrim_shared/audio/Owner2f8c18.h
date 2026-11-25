// Source exposure: mixed (names and declarations from community headers; base classes, sizes and
// Code origin: Stamped as a twin of matched 0x327554 (skyrim_shared/audio/BGSMusicTrackFormWrapper): source copied, names replaced by placeholders.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Owner2f8c18: GUESS(low) STANDIN
// BGSMusicTrackSecondary: GUESS(low) STANDIN
#pragma once
#include "BGSMusicTrackFormWrapper.h"

class Owner2f8c18 : public TESForm, public BGSMusicTrackSecondary
{
public:
    Owner2f8c18();
    virtual void InitItemImpl();
    virtual ~Owner2f8c18();
};
