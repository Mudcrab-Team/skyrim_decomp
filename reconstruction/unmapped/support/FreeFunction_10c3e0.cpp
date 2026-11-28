// Source exposure: binary-analysis (the pinned image listing).
// Code origin: original; written from the pinned image listing
// SPDX-License-Identifier: CC0-1.0
// 0x10c3e0 Function10c3e0
// Adapted bodies: none
#include <cstring>
#include "FreeFunction_10c3e0.h"

inline int StringView10c3e0::CompareNoCase(const char* a_other) const
{
    const char* self = c_str();
    if (a_other) {
        return _stricmp(self, a_other);
    }
    return data != nullptr ? 1 : 0;
}

// Compares two nullable C-string wrappers case-insensitively for equality.
bool Function10c3e0(const StringView10c3e0& a_lhs, const StringView10c3e0& a_rhs)
{
    return a_rhs.CompareNoCase(a_lhs.c_str()) == 0;
}
