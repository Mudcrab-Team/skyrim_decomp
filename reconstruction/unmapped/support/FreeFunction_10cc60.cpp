// Source exposure: binary-analysis (the pinned image listing).
// Code origin: original; written from the pinned image listing
// SPDX-License-Identifier: CC0-1.0
// 0x10cc60 Function10cc60
// Adapted bodies: none
#include <cstring>
#include "FreeFunction_10cc60.h"

inline int StringView10cc60::CompareNoCase(const char* a_other) const
{
    const char* self = c_str();
    if (a_other) {
        return _stricmp(self, a_other);
    }
    return data != nullptr ? 1 : 0;
}

// Compares two nullable C-string wrappers case-insensitively for equality.
bool Function10cc60(const StringView10cc60& a_lhs, const StringView10cc60& a_rhs)
{
    return a_lhs.CompareNoCase(a_rhs.c_str()) == 0;
}
