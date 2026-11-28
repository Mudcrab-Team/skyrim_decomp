// Source exposure: binary-analysis (pinned image listing).
// Code origin: original; written from the pinned image listing.
// SPDX-License-Identifier: CC0-1.0
// 0x20d320 Unit20d320::Equals20d320
// Adapted bodies: none
#include "Unit20d320.h"

#include <cstring>

// Compares two prefixed strings for equality after stripping any 13-byte prefix.
// NOTE: original behaviour: only the prefix test checks for null; a null text still reaches strcmp.
bool Unit20d320::Equals20d320(const Unit20d320& a_other) const
{
    bool equal = (data == a_other.data);
    if (!equal) {
        const char* rhs = a_other.GetStripped();
        const char* lhs = GetStripped();
        equal = (std::strcmp(lhs, rhs) == 0);
    }
    return equal;
}
