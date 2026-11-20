// Source exposure: mixed (pinned image and cited public declarations).
// Code origin: original implementations from the pinned listings and partial declarations.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// BGSMusicSilenceTrack: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// GetType, BGSMusicSilenceTrack::~BGSMusicSilenceTrack: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
#pragma once

#include <cstdint>

class BGSMusicSilenceTrack
{
public:
    BGSMusicSilenceTrack();
    std::uint32_t GetType() const;
    virtual ~BGSMusicSilenceTrack();

private:
    std::uint8_t padding08[0x30];
};
static_assert(sizeof(BGSMusicSilenceTrack) == 0x38, "observed allocation size");
