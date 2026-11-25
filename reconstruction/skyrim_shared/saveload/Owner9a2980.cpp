// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below Stamped as a twin of matched 0x9ad110 (skyrim_shared/saveload/BGSLoadGameBuffer_9ad110): source copied, names replaced by placeholders. Loose twin: constants differ from the exemplar and follow this function's code.
// SPDX-License-Identifier: CC0-1.0
// 0x9a2980 Owner9a2980::Function9a2980
#include "Owner9a2980.h"

// Reads the extra byte only from save versions that have it.
void Owner9a2980::Function9a2980()
{
    if (GetVersion() >= 0x6) {
        LoadDataEndian(&gLoadedByte, 1, 1);
    }
}
