// Source exposure: binary-analysis (pinned image listing).
// Code origin: original; written from the listing
// SPDX-License-Identifier: CC0-1.0
// 0xce8430 Timerce8430::Functionce8430
// Adapted bodies: none
#include "Timerce8430.h"

// Queries the Windows high-resolution performance counter and returns its 64-bit tick count.
// guess: a timer member that reads no member of its object.
std::int64_t Timerce8430::Functionce8430() const
{
    std::int64_t count = 0;
    QueryPerformanceCounter(&count);
    return count;
}
