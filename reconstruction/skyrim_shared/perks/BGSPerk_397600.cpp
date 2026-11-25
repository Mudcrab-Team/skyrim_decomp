// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: CC0-1.0
// 0x397600 BGSPerk::CompareOrder
// Adapted bodies: none
#include "BGSPerk_397600.h"

int BGSPerk::CompareOrder(const BGSPerk& a_other)
{
    if (primaryKey > a_other.primaryKey) {
        return -1;
    }
    if (primaryKey < a_other.primaryKey) {
        return 1;
    }
    if (secondaryKey < a_other.secondaryKey) {
        return -1;
    }
    if (secondaryKey > a_other.secondaryKey) {
        return 1;
    }
    return 0;
}
