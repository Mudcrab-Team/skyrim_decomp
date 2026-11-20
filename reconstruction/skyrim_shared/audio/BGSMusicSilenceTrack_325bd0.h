// Source exposure: mixed (pinned image and cited public declarations).
// Code origin: original code with a partial layout for the inherited cleanup.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// BGSMusicSilenceTrack: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// BGSMusicTrack: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
#pragma once

#include <cstdint>

class BGSMusicTrack
{
public:
    virtual ~BGSMusicTrack();

private:
    std::uint8_t padding08[0x18];
};

class BGSMusicSilenceTrack : public BGSMusicTrack
{
public:
    BGSMusicSilenceTrack();
    ~BGSMusicSilenceTrack() override = default;

private:
    std::uint8_t padding20[0x18];
};
static_assert(sizeof(BGSMusicSilenceTrack) == 0x38, "observed allocation size");
