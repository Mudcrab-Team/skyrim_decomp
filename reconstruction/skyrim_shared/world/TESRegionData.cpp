// Source exposure: mixed (names and declarations from community headers; the listing of the pinned
// image).
// Adapted bodies: none
// 0x24fee0 TESRegionData::LoadDataHeader
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
