// Source exposure: binary-analysis (the pinned image listing).
// Code origin: original reconstruction written from the pinned image listing.
// SPDX-License-Identifier: CC0-1.0
// 0x1bd9f0 Obj1bd9f0::UpdateMinTempFormId
// Adapted bodies: none.
#include "Obj1bd9f0.h"

// Lowers minIdD50 to a_formId when a_formId is a valid dynamic form ID above the reserved range.
void Obj1bd9f0::UpdateMinTempFormId(std::uint32_t a_formId)
{
    if (a_formId && (a_formId & 0xFF000000u) == 0xFF000000u && !flagDA9 && a_formId < minIdD50 && (a_formId & 0xFFFFFFu) > 0x7FFu) {
        minIdD50 = a_formId;
    }
}
