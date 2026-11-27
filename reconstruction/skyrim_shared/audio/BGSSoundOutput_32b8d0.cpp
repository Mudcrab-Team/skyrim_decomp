// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: CC0-1.0
// 0x32b8d0 BGSSoundOutput::DoGetSupportsMonitor
// Adapted bodies: none
#include "BGSSoundOutput_32b8d0.h"

bool BGSSoundOutput::DoGetSupportsMonitor(std::uint32_t a_mode) const
{
    return TestBit(flagWord, 1) || (a_mode != Function55a430() && a_mode != Function55a420());
}
