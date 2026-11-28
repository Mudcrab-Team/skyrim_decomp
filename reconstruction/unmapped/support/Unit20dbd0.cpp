// Source exposure: binary-analysis (pinned image listing).
// Code origin: original; written from the pinned image listing.
// SPDX-License-Identifier: CC0-1.0
// 0x20dbd0 Unit20dbd0::GetStrippedLength20dbd0
// Adapted bodies: none
#include "Unit20dbd0.h"

extern "C" __declspec(dllimport) int __cdecl _strnicmp(const char* a_lhs, const char* a_rhs, std::size_t a_count);

// Returns the string length minus the 13-byte prefix when the prefix is present.
std::uint32_t Unit20dbd0::GetStrippedLength20dbd0() const
{
    std::uint32_t length = Length();
    if (data && _strnicmp(data, g_prefix20dbd0, 4) == 0) {
        length -= 13;
    }
    return length;
}
