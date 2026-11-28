// Source exposure: mixed (pinned image listing; CrashLogger PDB names).
// Code origin: original; written from the pinned image listing.
// SPDX-License-Identifier: CC0-1.0
// Unit1f3e80, HasPrefix1f3e80, text, g_prefix1f3e80: GUESS(low)
#pragma once

#include <cstddef>

extern const char g_prefix1f3e80[];

struct Unit1f3e80
{
    const char* text;  // 00

    bool HasPrefix1f3e80() const;  // compared: 0x1f3e80
};
static_assert(offsetof(Unit1f3e80, text) == 0x00, "Unit1f3e80::text offset");
