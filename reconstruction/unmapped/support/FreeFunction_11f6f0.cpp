// Source exposure: binary-analysis
// Code origin: original reconstruction from pinned-image observations
// SPDX-License-Identifier: CC0-1.0
// 0x11f6f0 Function11f6f0
// Adapted bodies: none
#include "FreeFunction_11f6f0.h"

namespace
{
    struct CharEqualNoCase
    {
        bool operator()(char a_lhs, char a_rhs) const
        {
            return tolower(a_lhs) == tolower(a_rhs);
        }
    };
}

// Case-insensitively compares two character ranges for equality.
bool Function11f6f0(const char* a_first1, const char* a_last1, const char* a_first2, const char* a_last2)
{
    return std::equal(a_first1, a_last1, a_first2, a_last2, CharEqualNoCase());
}
