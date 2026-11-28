// Source exposure: binary-analysis (pinned image listing).
// Code origin: original; written from the pinned image listing.
// SPDX-License-Identifier: CC0-1.0
// Unit1f5040, MatchesKnownEntry1f5040, value, g_knownEntries1f5040: GUESS(low)
#pragma once

#include <cstddef>

extern const void* g_knownEntries1f5040[5];

struct Unit1f5040
{
    const void* value;  // 00

    bool MatchesKnownEntry1f5040() const;  // compared: 0x1f5040
};
static_assert(offsetof(Unit1f5040, value) == 0x00, "Unit1f5040::value offset");
