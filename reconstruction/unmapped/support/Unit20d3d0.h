// Source exposure: binary-analysis (pinned image listing).
// Code origin: original; written from the pinned image listing.
// SPDX-License-Identifier: CC0-1.0
// Unit20d3d0, data, GetStripped, EqualsCString20d3d0, g_prefix20d3d0: GUESS(low)
#pragma once

#include <cstddef>

extern const char g_prefix20d3d0[];
extern "C" __declspec(dllimport) int __cdecl _strnicmp(const char* a_lhs, const char* a_rhs, std::size_t a_count);

struct Unit20d3d0
{
    const char* data;  // 00

    const char* GetStripped() const
    {
        const char* text = data;
        bool hasPrefix = false;
        if (text) {
            hasPrefix = _strnicmp(text, g_prefix20d3d0, 4) == 0;
        }
        return hasPrefix ? text + 13 : text;
    }

    bool EqualsCString20d3d0(const char* a_other) const;  // compared: 0x20d3d0
};
static_assert(offsetof(Unit20d3d0, data) == 0x00, "Unit20d3d0::data offset");
