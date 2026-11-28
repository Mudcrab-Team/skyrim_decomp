// Source exposure: binary-analysis (pinned image listing).
// Code origin: original; written from the pinned image listing.
// SPDX-License-Identifier: CC0-1.0
// Unit20d320, data, GetStripped, Equals20d320, g_prefix20d320: GUESS(low)
#pragma once

#include <cstddef>

extern const char g_prefix20d320[];
extern "C" __declspec(dllimport) int __cdecl _strnicmp(const char* a_lhs, const char* a_rhs, std::size_t a_count);

struct Unit20d320
{
    const char* data;  // 00

    const char* GetStripped() const
    {
        const char* text = data;
        bool hasPrefix = false;
        if (text) {
            hasPrefix = _strnicmp(text, g_prefix20d320, 4) == 0;
        }
        return hasPrefix ? text + 13 : text;
    }

    bool Equals20d320(const Unit20d320& a_other) const;  // compared: 0x20d320
};
static_assert(offsetof(Unit20d320, data) == 0x00, "Unit20d320::data offset");
