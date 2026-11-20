// Source exposure: mixed (pinned image and cited public declarations).
// Code origin: original implementations from the pinned listings and partial declarations.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// 0x325b90 BGSMusicSilenceTrack::GetType
// 0x325bd0 BGSMusicSilenceTrack::~BGSMusicSilenceTrack
// Adapted bodies: none
#include "BGSMusicSilenceTrack_325a90.h"

// g_silenceTrackType, g_silenceTrackTypeName, HashTrackType: GUESS(low)
extern std::uint32_t g_silenceTrackType;
extern const char g_silenceTrackTypeName[];
void HashTrackType(std::uint32_t* id, const char* name, std::uint32_t seed);

// Emit the virtual deleting destructor with the class constructor.
BGSMusicSilenceTrack::BGSMusicSilenceTrack() = default;

std::uint32_t BGSMusicSilenceTrack::GetType() const
{
    auto result = g_silenceTrackType;
    if (result == 0) {
        HashTrackType(&g_silenceTrackType, g_silenceTrackTypeName, 0);
        result = g_silenceTrackType;
    }
    return result;
}
