// Origin: original reconstruction; declarations adapted from CommonLibSSE-NG at the pin below.
// Source exposure: mixed (local binary analysis and public declarations).
// Inferred names: GUESS(low)
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// 0x170910 ExtraDataList::ReadActionFlags
#include "ExtraDataList_170910.h"

std::uint32_t ExtraDataList::ReadActionFlags()
{
    const auto* entry = static_cast<ExtraAction*>(GetByType(13));
    return entry ? static_cast<std::uint8_t>(entry->action) : 1;
}
