// Source exposure: binary-analysis (pinned image listing).
// Code origin: original; written from the pinned image listing.
// SPDX-License-Identifier: CC0-1.0
// Unit20db80, data, GetStripped20db80, g_prefix20db80: GUESS(low)
#pragma once

#include <cstddef>

extern const char g_prefix20db80[];

struct Unit20db80
{
    const char* data;  // 00

    const char* GetStripped20db80() const;  // compared: 0x20db80
};
static_assert(offsetof(Unit20db80, data) == 0x00, "Unit20db80::data offset");
