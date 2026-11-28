// Source exposure: binary-analysis (pinned image listing).
// Code origin: original; written from the pinned image listing.
// SPDX-License-Identifier: CC0-1.0
// 0x20d2d0 Unit20d2d0::IsEmpty20d2d0
// Adapted bodies: none
#include "Unit20d2d0.h"

extern "C" __declspec(dllimport) int __cdecl _strnicmp(const char* a_lhs, const char* a_rhs, std::size_t a_count);

// Returns true when the string length after stripping the 13-byte prefix is zero.
bool Unit20d2d0::IsEmpty20d2d0() const
{
    std::uint32_t length = Length();
    if (data && _strnicmp(data, g_prefix20d2d0, 4) == 0) {
        length -= 13;
    }
    return length == 0;
}
