// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: original; the listing and community declarations only
// SPDX-License-Identifier: CC0-1.0
// 0x24ff10 TESRegionData::Function24ff10
// Adapted bodies: none
// Source exposure: mixed (names and declarations from community headers; the listing of the pinned
// image).
// Adapted bodies: none
#include "TESRegionData.h"

// TESRegionData::TESRegionData: GUESS(low); defined so the vftable and the deleting destructor are emitted
TESRegionData::TESRegionData()
{
}

// TESRegionData::LoadData: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
void TESRegionData::LoadData(void* a_arg1)
{
}

bool TESRegionData::LoadDataHeader(void* a_arg1)
{
    if (a_arg1 == nullptr) {
        return false;
    }
    const auto* src = static_cast<const std::uint8_t*>(a_arg1);
    unk08 = src[4];
    const std::uint8_t priority = src[5];
    if (priority <= 100) {
        unk0A = priority;
    }
    return true;
}

bool TESRegionData::Function24ff10(std::uint8_t a_value)
{
    const bool valid = a_value <= 100;
    if (valid) {
        unk0A = a_value;
    }
    return valid;
}
