// Origin: declarations adapted from labelled pinned community headers and target-specific partial declarations.
// Source exposure: mixed (pinned target listing and community declarations).
// BSIMusicTrack, BSIMusicTrack::DoUpdate, BSIMusicTrack::DoPlay, BSIMusicTrack::DoPause, BSIMusicTrack::DoFinish, BSIMusicTrack::GetDurationImpl, BSIMusicTrack::GetType, BSIMusicTrack::TestCanPlay, BSIMusicTrack::GetMusicStatus, BSIMusicTrack::DoSetDuckingAttenuation, BSIMusicTrack::DoClearDucking: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); declared in NG slot order.
// BGSMusicTrackFormWrapper, track: GUESS(low)
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
#pragma once
#include <cstdint>
class BSIMusicTrack {
public:
    enum class MusicStatus : std::uint32_t {};
    virtual ~BSIMusicTrack() = default;
    virtual void DoUpdate();
    virtual void DoPlay();
    virtual void DoPause();
    virtual void DoFinish(bool immediate, float fadeTime);
    virtual float GetDurationImpl() const;
    virtual std::uint32_t GetType() const;
    virtual bool TestCanPlay() const;
    virtual MusicStatus GetMusicStatus() const;
    virtual void DoSetDuckingAttenuation(std::uint16_t ducking);
    virtual void DoClearDucking();
};
class BGSMusicTrackFormWrapper {
public:
    void DoUpdate(); void DoPlay(); void DoPause(); void DoFinish(bool immediate, float fadeTime);
    float GetDurationImpl() const; std::uint32_t GetType() const; bool TestCanPlay() const;
    BSIMusicTrack::MusicStatus GetMusicStatus() const;
    void DoSetDuckingAttenuation(std::uint16_t ducking); void DoClearDucking();
private:
    std::uint8_t pad[0x10]; BSIMusicTrack* track;
};
