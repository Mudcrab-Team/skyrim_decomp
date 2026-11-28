// Source exposure: binary-analysis (pinned image listing).
// Code origin: original; written from the pinned image listing.
// SPDX-License-Identifier: CC0-1.0
// 0x20db80 Unit20db80::GetStripped20db80
// Adapted bodies: none
#include "Unit20db80.h"

extern "C" __declspec(dllimport) int __cdecl _strnicmp(const char* a_lhs, const char* a_rhs, std::size_t a_count);

// Returns data advanced past the 13-byte prefix when the prefix matches, otherwise returns data.
const char* Unit20db80::GetStripped20db80() const
{
    const char* text = data;
    bool hasPrefix = false;
    if (text) {
        hasPrefix = _strnicmp(text, g_prefix20db80, 4) == 0;
    }
    return hasPrefix ? text + 13 : text;
}
