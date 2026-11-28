// Source exposure: binary-analysis (pinned image listing).
// Code origin: original; written from the pinned image listing.
// SPDX-License-Identifier: CC0-1.0
// 0x1e27e0 Unit1e27e0::Equals1e27e0
// Adapted bodies: none
#include "Unit1e27e0.h"

// Compares two pointer arrays element by element for equality.
bool Unit1e27e0::Equals1e27e0(const Unit1e27e0& a_other) const
{
    std::uint32_t otherCount = a_other.count;
    bool equal = (count == otherCount);
    void** otherData = a_other.data;
    for (std::uint32_t i = 0; equal && i < otherCount; ++i) {
        equal = (data[i] == otherData[i]);
    }
    return equal;
}
