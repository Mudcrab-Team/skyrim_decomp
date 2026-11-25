// Source exposure: mixed (names and declarations from community headers; base classes, sizes and
// Code origin: Stamped as a twin of matched 0x325bc0 (skyrim_shared/audio/BGSMusicSilenceTrack): source copied, names replaced by placeholders.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// TESFile: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); GetCurrentSubRecordType, ReadData, SeekNextSubrecord are NG names
// Owner11274d0: GUESS(low) STANDIN
// GetDurationImpl, DoFinish, DoPause, DoPlay, Load, duration, pad24, playTime, pauseTime, BGSMusicTrack: GUESS(low) STANDIN
#pragma once
#include "BGSMusicSilenceTrack.h"

class Owner11274d0 : public BGSMusicTrack
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
static_assert(sizeof(Owner11274d0) == 0x38, "Owner11274d0 size");
