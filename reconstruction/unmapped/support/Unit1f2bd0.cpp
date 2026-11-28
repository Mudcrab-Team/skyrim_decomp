// Source exposure: binary-analysis (pinned image listing).
// Code origin: original; written from the pinned image listing.
// SPDX-License-Identifier: CC0-1.0
// 0x1f2bd0 Unit1f2bd0::Differs1f2bd0
// Adapted bodies: none
#include "Unit1f2bd0.h"

extern "C" __declspec(dllimport) int __cdecl _stricmp(const char* a_lhs, const char* a_rhs);

// Compares this object's string against another Base1f2bd0 instance after dynamic_cast.
bool Unit1f2bd0::Differs1f2bd0(const Base1f2bd0* a_other) const
{
    const auto* other = dynamic_cast<const Unit1f2bd0*>(a_other);
    if (!other) {
        return true;
    }

    if (text.Length() == 0 && other->text.Length() == 0) {
        return false;
    }

    if (text.Length() != other->text.Length()) {
        return true;
    }

    if (_stricmp(text.data, other->text.data) != 0) {
        return true;
    }

    return false;
}
