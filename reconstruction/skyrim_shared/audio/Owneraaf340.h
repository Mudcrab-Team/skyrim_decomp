// Origin: declarations adapted from labelled pinned community headers and target-specific partial declarations.
// Source exposure: mixed (pinned target listing and community declarations).
// Code origin: Stamped as a twin of matched 0x327660 (skyrim_shared/audio/BGSMusicTrackFormWrapper_327650): source copied, names replaced by placeholders.
// BSIMusicTrack, BSIMusicTrack::DoUpdate, BSIMusicTrack::DoPlay, BSIMusicTrack::DoPause, BSIMusicTrack::GetDurationImpl, BSIMusicTrack::GetType, BSIMusicTrack::TestCanPlay, BSIMusicTrack::GetMusicStatus, BSIMusicTrack::DoSetDuckingAttenuation, BSIMusicTrack::DoClearDucking: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); declared in NG slot order.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Functionaaf340, Owneraaf340: GUESS(low) STANDIN
// track: GUESS(low) STANDIN
#pragma once
#include "BGSMusicTrackFormWrapper_327650.h"

class Owneraaf340 {
public:
    void DoUpdate(); void DoPlay(); void DoPause(); void Functionaaf340(bool immediate, float fadeTime);
    float GetDurationImpl() const; std::uint32_t GetType() const; bool TestCanPlay() const;
    BSIMusicTrack::MusicStatus GetMusicStatus() const;
    void DoSetDuckingAttenuation(std::uint16_t ducking); void DoClearDucking();
private:
    std::uint8_t pad[0x10]; BSIMusicTrack* track;
};

