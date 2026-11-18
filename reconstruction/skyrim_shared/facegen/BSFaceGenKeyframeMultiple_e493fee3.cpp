// Code origin: GetModifierName, Unk_08 and Unk_09 bodies written from the local listings; declarations added to the existing unit header.
// Source exposure: mixed (names and declarations from community headers; the listing of the pinned
// image).
// Declarations derived from powerof3/CommonLibSSE are GPL-3.0.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Adapted bodies: none
// 0x43acc0 BSFaceGenKeyframeMultiple::GetModifierName
#include "BSFaceGenKeyframeMultiple_e493fee3.h"
const char* BSFaceGenKeyframeMultiple::GetModifierName(std::uint32_t a_index)
{
    if (a_index <= 0x10) {
        // The public unsigned input has been bounded; its signed table index is representable.
        const std::int32_t tableIndex = static_cast<std::int32_t>(a_index);
        return g_modifierNameTable[tableIndex];
    }
    return nullptr;
}

float BSFaceGenKeyframeMultiple::Unk_08()
{
    float result = 0.0f;
    for (std::uint32_t i = 0; i < count; ++i) {
        if (Unk_0E(i)) {
            const float weight = values[i];
            result = weight > result ? weight : result;
        }
    }
    return result;
}

bool BSFaceGenKeyframeMultiple::Unk_09()
{
    for (std::uint32_t i = 0; i < count; ++i) {
        if (Unk_0E(i) && !(values[i] <= 0.0f)) {
            return false;
        }
    }
    return true;
}
