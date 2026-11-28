// Source exposure: binary-analysis (the pinned image listing).
// Code origin: original; written from the pinned image listing
// SPDX-License-Identifier: CC0-1.0
// 0x11c660 CharEqualNoCase11c660::Equals
// Adapted bodies: none
#include "CharEqualNoCase11c660.h"

extern "C" __declspec(dllimport) int __cdecl tolower(int a_ch);

// guess: a stateless predicate object; the call does not read this.
bool CharEqualNoCase11c660::Equals(char a_lhs, char a_rhs) const
{
    return tolower(a_lhs) == tolower(a_rhs);
}
