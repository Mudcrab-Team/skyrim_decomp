// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: CC0-1.0
// 0x389790 BGSAssociationType::Function389790
// Adapted bodies: none
#include "BGSAssociationType_389790.h"

// Falls back to the first string of the pair when the second is empty.
const char* BGSAssociationType::Function389790(std::int32_t a_index, std::int32_t a_variant) const
{
    const char* name = names[a_index][a_variant];
    if ((!name || !*name) && a_variant == 1) {
        return names[a_index][0];
    }
    return name;
}
