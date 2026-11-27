// Source exposure: mixed (pinned image, cited public declarations and the 2013 map).
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Code origin: original implementation based on the pinned game build; names as labelled in the header.
// Adapted bodies: none
// 0x390a50 BGSHeadPart::GetMustHeadPartBeUnique
#include "BGSHeadPart_390a50.h"

// Guess: a character carries at most one part of these types; misc parts and scars may stack.
bool BGSHeadPart::GetMustHeadPartBeUnique(HeadPartType a_type)
{
    bool unique = false;
    switch (a_type) {
    case HeadPartType::kFace:
    case HeadPartType::kEyes:
    case HeadPartType::kHair:
    case HeadPartType::kFacialHair:
    case HeadPartType::kEyebrows:
        unique = true;
        break;
    default:
        break;
    }
    return unique;
}
