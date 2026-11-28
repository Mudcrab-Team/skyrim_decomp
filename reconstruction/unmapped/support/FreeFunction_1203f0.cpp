// Source exposure: binary-analysis
// Code origin: original reconstruction from pinned-image observations
// SPDX-License-Identifier: CC0-1.0
// 0x1203f0 Function1203f0
// Adapted bodies: none
#include "FreeFunction_1203f0.h"

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

// Case-insensitively compares a character range against a second sequence.
bool Function1203f0(const char* a_first1, const char* a_last1, const char* a_first2)
{
    return std::equal(a_first1, a_last1, a_first2, CharEqualNoCase());
}
