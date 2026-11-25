// Source exposure: mixed (names and declarations from community headers; base classes, sizes and
// Code origin: Stamped as a twin of matched 0x325bc0 (skyrim_shared/audio/BGSMusicSilenceTrack): source copied, names replaced by placeholders.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// TESFile: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); GetCurrentSubRecordType, ReadData, SeekNextSubrecord are NG names
// Ownerf43950: GUESS(low) STANDIN
// GetDurationImpl, DoFinish, DoPause, DoPlay, Load, duration, pad24, playTime, pauseTime, BGSMusicTrack: GUESS(low) STANDIN
#pragma once
#include "BGSMusicSilenceTrack.h"

class Ownerf43950 : public BGSMusicTrack
{
public:
    virtual float GetDurationImpl() const;
    virtual void DoFinish(bool a_arg1, float a_arg2);
    virtual void DoPause();
    virtual void DoPlay();
    virtual void Load(TESFile* a_mod);

    float duration;  // 20
    std::uint32_t pad24;  // 24
    std::uint64_t playTime;  // 28
    std::uint64_t pauseTime;  // 30
};
static_assert(sizeof(Ownerf43950) == 0x38, "Ownerf43950 size");
