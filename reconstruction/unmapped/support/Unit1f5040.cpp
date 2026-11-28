// Source exposure: binary-analysis (pinned image listing).
// Code origin: original; written from the pinned image listing.
// SPDX-License-Identifier: CC0-1.0
// 0x1f5040 Unit1f5040::MatchesKnownEntry1f5040
// Adapted bodies: none
#include "Unit1f5040.h"

// Returns true when value matches any of the five global pointer entries.
bool Unit1f5040::MatchesKnownEntry1f5040() const
{
    const void* current = value;
    return current == g_knownEntries1f5040[0] ||
           current == g_knownEntries1f5040[1] ||
           current == g_knownEntries1f5040[2] ||
           current == g_knownEntries1f5040[3] ||
           current == g_knownEntries1f5040[4];
}
