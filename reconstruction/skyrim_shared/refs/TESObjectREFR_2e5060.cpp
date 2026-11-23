// Source exposure: mixed (community declarations and the pinned image).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: CC0-1.0
// 0x2e5060 TESObjectREFR::CanUseWorldSpace
// Adapted bodies: none
#include "TESObjectREFR_2e5060.h"

// IsRecordBitSet: GUESS(low)
inline bool IsRecordBitSet(std::uint32_t a_flags, unsigned a_bit)
{
    const auto lowBits = static_cast<std::uint8_t>(a_flags >> a_bit);
    return lowBits % 2 == 1;
}

bool TESObjectREFR::CanUseWorldSpace(const TESObjectREFR* a_ref, const TESWorldSpace* a_world)
{
    bool result = false;
    if (a_ref) {
        const std::uint32_t flags = a_ref->formFlags;
        if (!IsRecordBitSet(flags, 5) && !IsRecordBitSet(flags, 14) && a_world) {
            if (a_ref->GetWorldSpace() == a_world) {
                result = true;
            }
        }
    }
    return result;
}
