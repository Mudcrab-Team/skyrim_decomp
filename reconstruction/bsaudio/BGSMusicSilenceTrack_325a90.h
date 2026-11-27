// Source exposure: mixed
// Code origin: community declarations and original flattened target layout.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// BGSMusicSilenceTrack: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); flattened base storage
// DoUpdate, DoPlay, DoPause, DoFinish, GetDurationImpl, GetType, TestCanPlay, GetMusicStatus: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// MUSIC_STATUS, kInactive, kPlaying, kPaused, kFinishing, kFinished, trackStatus, duration, pad24, playTime, pauseTime: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// unk0C, unk10: GUESS(low); unaccessed base storage
#pragma once
#include <cstddef>
#include <cstdint>

class BGSMusicSilenceTrack
{
public:
    enum class MUSIC_STATUS : std::uint32_t
    {
        kInactive = 0, kPlaying = 1, kPaused = 2, kFinishing = 3, kFinished = 4
    };
    virtual ~BGSMusicSilenceTrack();
    virtual void DoUpdate();
    virtual void DoPlay();
    virtual void DoPause();
    virtual void DoFinish(bool, float);
    virtual float GetDurationImpl() const;
    virtual std::uint32_t GetType() const;
    virtual bool TestCanPlay() const;
    virtual MUSIC_STATUS GetMusicStatus() const;
    MUSIC_STATUS trackStatus; // 08
    std::uint32_t unk0C; // 0C
    std::uint64_t unk10[2]; // 10
    float duration; // 20
    std::uint32_t pad24; // 24
    std::uint64_t playTime; // 28
    std::uint64_t pauseTime; // 30
};
static_assert(offsetof(BGSMusicSilenceTrack, trackStatus) == 0x08, "status offset");
static_assert(offsetof(BGSMusicSilenceTrack, duration) == 0x20, "duration offset");
static_assert(offsetof(BGSMusicSilenceTrack, playTime) == 0x28, "play time offset");
